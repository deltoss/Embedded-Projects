# ESP32

Setup for generic Espressif ESP32 boards. This guide covers ESP32-C3, ESP32-C6, and ESP32-H2.

## Install the Arduino core

```sh
arduino-cli config add board_manager.additional_urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
arduino-cli core update-index
arduino-cli core install esp32:esp32
```

Confirm the core is installed:

```sh
arduino-cli core list
```

## Choose the board

Use the FQBN for the chip on your board:

| Chip | FQBN |
| --- | --- |
| ESP32-C3 | `esp32:esp32:esp32c3` |
| ESP32-C6 | `esp32:esp32:esp32c6` |
| ESP32-H2 | `esp32:esp32:esp32h2` |

Confirm the installed target and available options before compiling:

```sh
arduino-cli board details --fqbn <FQBN>
```

## Build and upload

Connect the board and find its serial port:

```sh
arduino-cli board list
```

`<PORT>` is a value such as `COM5` on Windows or `/dev/ttyACM0` or `/dev/ttyUSB0` on Linux.

```sh
arduino-cli compile --fqbn <FQBN> <SKETCH_DIRECTORY>
arduino-cli upload --port <PORT> --fqbn <FQBN> <SKETCH_DIRECTORY>
```

Save the board selection in the sketch's `sketch.yaml` file:

```sh
arduino-cli board attach --port <PORT> --fqbn <FQBN> <SKETCH_DIRECTORY>
```

## Linux serial access

If the port is visible but upload fails with a permission error, add your user to the serial-device group. On CachyOS/Arch, this is commonly `uucp`:

```sh
sudo usermod -aG uucp $USER
```

Log out and back in after changing groups.

## Example project

[`../projects/esp32-onboard-led`](../projects/esp32-onboard-led) is a minimal blink project for these boards. Keep the `.ino` filename equal to its containing directory name.

## References

- [Espressif Arduino core](https://github.com/espressif/arduino-esp32)
- [Arduino CLI](https://docs.arduino.cc/arduino-cli/)
