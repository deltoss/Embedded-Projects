#!/usr/bin/env nu

# Installs the Arduino core and libraries for the M5Stack Cardputer ADV.
def main [] {
  if (which arduino-cli | where type == external | is-empty) {
    error make "arduino-cli is not installed or not in PATH"
  }

  ^arduino-cli config add board_manager.additional_urls https://static-cdn.m5stack.com/resource/arduino/package_m5stack_index.json
  ^arduino-cli core update-index
  ^arduino-cli core install m5stack:esp32
  ^arduino-cli lib install M5Cardputer
  ^arduino-cli lib install "Adafruit NeoPixel"
}
