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

### Official M5Stack UserDemo

M5Stack publishes an ADV-specific UserDemo with its launcher, Wi-Fi scanner, IR tool, and other hardware demos.

- **Release** ⟶ [ADV-V0.3](https://github.com/m5stack/M5Cardputer-UserDemo/releases/tag/ADV-V0.3)
- **Binary** ⟶ [`K132-Adv-Cardputer-Adv-UserDemo-V0.3_0x0.bin`](https://github.com/m5stack/M5Cardputer-UserDemo/releases/download/ADV-V0.3/K132-Adv-Cardputer-Adv-UserDemo-V0.3_0x0.bin)
- **SHA-256** ⟶ `7bb1532427c875445b16186b6139afa371f67ddbdc83ae5bfe4a9089c7883b74`
- **Source** ⟶ [M5Cardputer-UserDemo `CardputerADV` branch](https://github.com/m5stack/M5Cardputer-UserDemo/tree/CardputerADV)

Do not use `K132-Cardputer-UserDemo-V0.9_0x0.bin`. That image targets the original Cardputer.

### Third-party Launcher

[bmorcelli Launcher](https://github.com/bmorcelli/Launcher) can keep multiple firmware applications in separate flash partitions. Use its `m5stack-cardputer` build, which supports both Cardputer and Cardputer ADV.

Install custom Arduino applications through Launcher's `SD` browser or `WUI` WebUI. Supply only the sketch application image, normally `<SKETCH>.ino.bin`. Do not supply an Arduino bootloader, partition table, or full merged image for a normal custom app.

Launcher's `USB` option exposes the inserted microSD card to the computer as a USB mass-storage drive. Safely eject it on the computer before leaving USB mode.

## Download mode

1. **Switch off** ⟶ Set the top power switch to `OFF`.
2. **Hold G0** ⟶ Hold the `G0` button beside the switch.
3. **Connect USB** ⟶ Connect a USB-C data cable.
4. **Release G0** ⟶ The Cardputer ADV is now in ESP32-S3 download mode.

Close serial monitors before using the port.

## Back up the full flash

A raw 8 MiB dump includes the bootloader, partition table, firmware, settings, and internal flash filesystems. It does not include the microSD card.

Install esptool:

```sh
python -m pip install --upgrade esptool
```

Confirm the target and flash size in download mode:

```sh
python -m esptool --chip esp32s3 --port <PORT> flash-id
python -m esptool --chip esp32s3 --port <PORT> read-mac
```

`flash-id` must report 8 MB. Create and verify the backup:

```sh
python -m esptool --chip esp32s3 --port <PORT> --baud 460800 read-flash 0x0 0x800000 cardputer-adv-backup-8MiB.bin
python -m esptool --chip esp32s3 --port <PORT> --baud 460800 verify-flash 0x0 cardputer-adv-backup-8MiB.bin
python -c "from pathlib import Path; import hashlib; p=Path('cardputer-adv-backup-8MiB.bin'); print(p.stat().st_size); print(hashlib.sha256(p.read_bytes()).hexdigest())"
```

The file must be exactly `8388608` bytes. Store it and its SHA-256 digest privately in two safe locations. It can contain credentials and tokens.

## Restore a raw backup

> **Warning:** This overwrites all internal flash. Restore only an image captured from the same physical Cardputer ADV.

Enter download mode, verify the saved SHA-256, then restore at offset `0x0`:

```sh
python -m esptool --chip esp32s3 --port <PORT> --baud 460800 write-flash 0x0 cardputer-adv-backup-8MiB.bin
python -m esptool --chip esp32s3 --port <PORT> --baud 460800 verify-flash 0x0 cardputer-adv-backup-8MiB.bin
```

Do not add `--erase-all` or flash mode, frequency, or size overrides. Restart normally without holding `G0` after verification succeeds.

## References

- [M5Stack Cardputer ADV](https://docs.m5stack.com/en/core/Cardputer-Adv)
- [M5Stack Cardputer ADV factory restore](https://docs.m5stack.com/en/guide/restore_factory/cardputer_adv)
- [M5Stack Arduino setup for Cardputer and ADV](https://docs.m5stack.com/en/arduino/m5cardputer/program)
- [Launcher features](https://github.com/bmorcelli/Launcher/wiki/Functionalities-explained)
- [Espressif esptool commands](https://docs.espressif.com/projects/esptool/en/latest/esp32s3/esptool/basic-commands.html)
