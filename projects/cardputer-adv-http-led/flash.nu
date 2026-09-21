#!/usr/bin/env nu

const FQBN = "m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB"
const PROJECT_DIRECTORY = path self .

def main [port: string] {
  for secretName in [WIFI_SSID WIFI_PASSWORD] {
    if $secretName not-in $env {
      error make $"SecretSpec did not provide ($secretName)"
    }
  }

  let wifiSsid = ($env.WIFI_SSID | to json --raw)
  let wifiPassword = ($env.WIFI_PASSWORD | to json --raw)
  hide-env WIFI_SSID WIFI_PASSWORD

  let secretDirectory = (mktemp --directory)
  let secretHeader = ($secretDirectory | path join "wifi-secrets.h")

  try {
    [
      "#pragma once"
      ""
      $"constexpr char WIFI_SSID[] = ($wifiSsid);"
      $"constexpr char WIFI_PASSWORD[] = ($wifiPassword);"
    ]
    | str join "\n"
    | save --force $secretHeader

    if $nu.os-info.family == "unix" {
      ^chmod 600 $secretHeader
    }

    let compilerFlags = $'compiler.cpp.extra_flags=-include "($secretHeader)"'
    let arduinoArguments = [
      "compile"
      "--upload"
      "--port" $port
      "--fqbn" $FQBN
      "--build-property" $compilerFlags
      $PROJECT_DIRECTORY
    ]

    do --capture-errors {
      ^arduino-cli ...$arduinoArguments
    }
  } finally {
    rm --recursive --force $secretDirectory
  }
}
