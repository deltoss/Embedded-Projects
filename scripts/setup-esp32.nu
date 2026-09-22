#!/usr/bin/env nu

# Installs the Arduino core for generic Espressif ESP32 boards.
def main [] {
  if (which arduino-cli | where type == external | is-empty) {
    error make "arduino-cli is not installed or not in PATH"
  }

  ^arduino-cli config add board_manager.additional_urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
  ^arduino-cli core update-index
  ^arduino-cli core install esp32:esp32
}
