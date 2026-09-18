# M5Stack Cardputer ADV

This repository targets the **Cardputer ADV**, not the original Cardputer. The ADV uses a Stamp-S3A with an ESP32-S3, 8 MiB flash, and different keyboard and RGB LED control hardware.

M5Stack's Arduino board package uses the shared `M5Cardputer` board profile for both models.

## Configure Arduino CLI

```sh
arduino-cli config add board_manager.additional_urls https://static-cdn.m5stack.com/resource/arduino/package_m5stack_index.json
arduino-cli core update-index
arduino-cli core install m5stack:esp32
arduino-cli lib install M5Cardputer
```

Confirm the shared board profile:

```sh
arduino-cli board listall M5Cardputer
arduino-cli board details --fqbn m5stack:esp32:m5stack_cardputer
```

Use its 8 MiB flash configuration:

```text
m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB
```

Find the port, then build and upload:

```sh
arduino-cli board list
arduino-cli compile --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB <SKETCH_DIRECTORY>
arduino-cli upload --port <PORT> --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB <SKETCH_DIRECTORY>
```

`<PORT>` is a value such as `COM5` on Windows or `/dev/ttyACM0` on Linux.

## Firmware options

### Launcher

[bmorcelli Launcher](https://github.com/bmorcelli/Launcher), a third-party firmware, can keep multiple firmware applications in separate flash partitions. Use its `m5stack-cardputer` build, which supports both Cardputer and Cardputer ADV.

Install custom Arduino applications through Launcher's `SD` browser or `WUI` WebUI. Supply only the sketch application image, normally `<SKETCH>.ino.bin`. Do not supply an Arduino bootloader, partition table, or full merged image for a normal custom app.

Launcher's `USB` option exposes the inserted microSD card to the computer as a USB mass-storage drive. Safely eject it on the computer before leaving USB mode.

### Launcher Catalog

You can find a catalog of firmwares at
<https://bmorcelli.github.io/Launcher/catalog.html>

Notable firmwares includes:
- [Official M5Stack UserDemo](https://github.com/m5stack/M5Cardputer-UserDemo/tree/CardputerADV) - Wi-Fi scanner, IR tool, and more
- [Ultimate Remote](https://github.com/geo-tp/Ultimate-Remote) - Universal IR remote control
- [Cardputer Game Station Emulators](https://github.com/geo-tp/Cardputer-Game-Station-Emulators) - Game station emulator
- [Bluetooth-Keyboard-Mouse-Emulator](https://github.com/geo-tp/Bluetooth-Keyboard-Mouse-Emulator) - Act as a bluetooth keyboard/mouse

## Download mode

1. **Switch off** ⟶ Set the top power switch to `OFF`.
2. **Hold G0** ⟶ Hold the `G0` button beside the switch.
3. **Connect USB** ⟶ Connect a USB-C data cable.
4. **Release G0** ⟶ The Cardputer ADV is now in ESP32-S3 download mode.

Close serial monitors before using the port.

## References

- [M5Stack Cardputer ADV](https://docs.m5stack.com/en/core/Cardputer-Adv)
- [M5Stack Arduino setup for Cardputer and ADV](https://docs.m5stack.com/en/arduino/m5cardputer/program)
- [Launcher features](https://github.com/bmorcelli/Launcher/wiki/Functionalities-explained)
