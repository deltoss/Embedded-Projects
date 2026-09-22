#!/usr/bin/env nu

const SCRIPT_DIRECTORY = path self .

# Prompts for devices and runs their setup scripts.
def main [] {
  let devices = [
    { name: "Generic ESP32", script: "setup-esp32.nu" }
    { name: "M5Stack Cardputer ADV", script: "setup-cardputer-adv.nu" }
  ] | input list --multi --display name "Select devices to set up:"

  if ($devices == null or ($devices | is-empty)) {
    exit 130
  }

  for device in $devices {
    ^$nu.current-exe ($SCRIPT_DIRECTORY | path join $device.script)
  }
}
