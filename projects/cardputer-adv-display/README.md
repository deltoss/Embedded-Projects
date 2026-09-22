# Cardputer ADV Display

A minimal M5Stack Cardputer ADV sketch. It continuously shows `ON` for one second and clears the display for one second.

The sketch uses the display instead of `LED_BUILTIN`, preserving the logic of [`../esp32-onboard-led`](../esp32-onboard-led) on Cardputer ADV hardware.

## Build for Launcher

Prepare the build toolchain in the [Cardputer ADV board guide](../../boards/M5Stack-Cardputer-ADV.md). From this directory:

```sh
arduino-cli compile --output-dir build --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB .
```

Install only `build/cardputer-adv-display.ino.bin`. Follow the board guide to transfer it through Launcher's USB mode or WUI and install it.

## Flash directly and replace Launcher

Find the Cardputer's port, then compile and upload directly:

```sh
arduino-cli board list
arduino-cli compile --upload --port <PORT> --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB .
```

A direct flash replaces the current Launcher setup. `<PORT>` is a value such as `COM5` on Windows or `/dev/ttyACM0` on Linux.
