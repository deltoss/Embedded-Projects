#!/usr/bin/env nu

const FQBN = "m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB"
const PROJECT_DIRECTORY = path self .
const OUTPUT_DIRECTORY = path self build
const BUILD_SCRIPT = path self build.nu

def main [port: string] {
  ^$nu.current-exe $BUILD_SCRIPT
  hide-env IOT_WIFI_SSID IOT_WIFI_PASSWORD

  let arduinoArguments = [
    "upload"
    "--input-dir" $OUTPUT_DIRECTORY
    "--port" $port
    "--fqbn" $FQBN
    $PROJECT_DIRECTORY
  ]

  ^arduino-cli ...$arduinoArguments
}
