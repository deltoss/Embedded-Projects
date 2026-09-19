# Cardputer ADV LED

A minimal M5Stack Cardputer ADV sketch. It continuously turns the onboard SK6812 RGB LED white for one second and off for one second without blocking the main loop.

- **GPIO 38** ⟶ Enables the ADV RGB LED power switch.
- **GPIO 21** ⟶ Sends SK6812 RGB data.

Install the required library once:

```sh
arduino-cli lib install "Adafruit NeoPixel"
```

## Build and upload directly

Follow the [Cardputer ADV board guide](../../boards/M5Stack-Cardputer-ADV.md) first. From this directory:

```sh
arduino-cli compile --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB .
arduino-cli upload --port <PORT> --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB .
```

A direct upload replaces the firmware that currently boots. Use the Launcher workflow below to keep Launcher installed.

## Build for Launcher

Export the application binary:

```sh
arduino-cli compile --export-binaries --output-dir out --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB .
```

Install only `out/cardputer-adv-led.ino.bin` through Launcher. Do not install the bootloader, partitions, merged, ELF, or map files.

Launcher can install the app from its `SD` browser or `WUI` WebUI. It creates or selects a separate app partition, preserving Launcher.

`<PORT>` is a value such as `COM5` on Windows or `/dev/ttyACM0` on Linux. The LED color is set in `led.Color(255, 255, 255)`.
