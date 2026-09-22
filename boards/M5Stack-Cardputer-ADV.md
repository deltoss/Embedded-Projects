# M5Stack Cardputer ADV

This repository targets the **Cardputer ADV**, not the original Cardputer. The ADV uses a Stamp-S3A with an ESP32-S3, 8 MiB flash, and different keyboard and RGB LED control hardware.

M5Stack's Arduino board package uses the shared `M5Cardputer` board profile for both models.

## Prepare the build toolchain

From the repository root, run the setup script:

```sh
nu scripts/setup-cardputer-adv.nu
```

The script adds M5Stack's board index, updates the index, and installs the core and libraries required by the Cardputer projects. It is safe to run again.

Confirm the shared board profile:

```sh
arduino-cli board listall M5Cardputer
arduino-cli board details --fqbn m5stack:esp32:m5stack_cardputer
```

Cardputer ADV applications in this repository use this 8 MiB FQBN:

```text
m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB
```

## Build for Launcher

[bmorcelli Launcher](https://github.com/bmorcelli/Launcher) keeps applications in separate flash partitions, so installing an application does not replace Launcher. Use its `m5stack-cardputer` build, which supports both Cardputer and Cardputer ADV.

From inside an Arduino project directory (AKA sketch directory). First compile to get a binary. I.e:

```sh
cd projects/cardputer-adv-led
arduino-cli compile --output-dir build --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB .
```

This produces several artifacts under `build/`. Install only the application image:

```text
build/cardputer-adv-led.ino.bin
```

### Transfer over USB

1. **Insert a microSD card** ⟶ Use a FAT32 card with an MBR partition table.
2. **Open `USB`** ⟶ Select `USB` in Launcher and connect the Cardputer to the computer.
3. **Copy the application** ⟶ Copy the sketch's `.ino.bin` file to any convenient directory on the mounted microSD card. Launcher does not require a specific directory.
4. **Eject the drive** ⟶ Safely eject it on the computer, then leave Launcher's USB mode.
5. **Install and boot the application** ⟶ Open `SD` in Launcher, select the copied `.bin`, and choose `Install`. Launcher flashes it into an internal application partition and reboots into it.
6. **Launch it later** ⟶ Start the persistent application from Launcher's installed application list. The SD copy is no longer required for launching.

## Launcher catalog

You can find a catalog of firmware at <https://bmorcelli.github.io/Launcher/catalog.html>.

Notable firmware includes:

- [Official M5Stack UserDemo](https://github.com/m5stack/M5Cardputer-UserDemo/tree/CardputerADV) - Wi-Fi scanner, IR tool, and more
- [Ultimate Remote](https://github.com/geo-tp/Ultimate-Remote) - Universal IR remote control
- [Cardputer Game Station Emulators](https://github.com/geo-tp/Cardputer-Game-Station-Emulators) - Game station emulator
- [Bluetooth-Keyboard-Mouse-Emulator](https://github.com/geo-tp/Bluetooth-Keyboard-Mouse-Emulator) - Act as a Bluetooth keyboard or mouse

## Flash directly and replace Launcher

Use direct serial flashing only when you intend to replace the current Launcher setup.

From inside a sketch directory, find the port, then compile and upload:

```sh
arduino-cli board list
arduino-cli compile --upload --port <PORT> --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB .
```

`<PORT>` is a value such as `COM5` on Windows or `/dev/ttyACM0` on Linux.

### Download mode

If a direct upload cannot connect:

1. **Switch off** ⟶ Set the top power switch to `OFF`.
2. **Hold G0** ⟶ Hold the `G0` button beside the switch.
3. **Connect USB** ⟶ Connect a USB-C data cable.
4. **Release G0** ⟶ The Cardputer ADV is now in ESP32-S3 download mode.

Close serial monitors before using the port.

## References

- [Launcher: obtaining binaries](https://github.com/bmorcelli/Launcher/wiki/Obtaining-binaries-to-launch)
- [Launcher features](https://github.com/bmorcelli/Launcher/wiki/Functionalities-explained)
- [Arduino CLI compile](https://arduino.github.io/arduino-cli/latest/commands/arduino-cli_compile/)
- [M5Stack Cardputer ADV](https://docs.m5stack.com/en/core/Cardputer-Adv)
- [M5Stack Arduino setup for Cardputer and ADV](https://docs.m5stack.com/en/arduino/m5cardputer/program)
