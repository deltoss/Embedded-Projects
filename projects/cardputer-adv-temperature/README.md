# Cardputer ADV Temperature

A minimal M5Stack Cardputer ADV sketch that reads ambient temperature from an [M5Stack Unit ENV-IV](https://docs.m5stack.com/en/unit/Unit_ENV-IV) and displays it in °C, updating every second. It uses the ENV-IV's SHT40 sensor.

## Hardware

Connect the ENV-IV to the Cardputer ADV's HY2.0-4P Grove port using the included cable.

- **SDA:** GPIO 2
- **SCL:** GPIO 1
- **Power:** Grove 5V and GND

The sensor must be connected before starting the sketch. If it is missing, the display shows `ENV-IV not found`; check the connection and reboot.

## Build for Launcher

Prepare the build toolchain using the [Cardputer ADV board guide](../../boards/M5Stack-Cardputer-ADV.md). The setup script installs the `Adafruit SHT4x Library` and its dependencies.

From this directory:

```sh
arduino-cli compile --output-dir build --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB .
```

Install only `build/cardputer-adv-temperature.ino.bin` using Launcher. Follow the board guide for USB transfer and installation.

## Flash directly and replace Launcher

```sh
arduino-cli board list
arduino-cli compile --upload --port <PORT> --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB .
```

Direct flashing replaces the existing Launcher installation. `<PORT>` is a port such as `COM5` on Windows or `/dev/ttyACM0` on Linux.
