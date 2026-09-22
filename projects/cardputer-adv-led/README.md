# Cardputer ADV LED

A minimal M5Stack Cardputer ADV sketch. It continuously turns the onboard SK6812 RGB LED white for one second and off for one second.

- **GPIO 38** ⟶ Enables the ADV RGB LED power switch.
- **GPIO 21** ⟶ Sends SK6812 RGB data.

Install the required library once:

```sh
arduino-cli lib install "Adafruit NeoPixel"
```

## Build for Launcher

Prepare the build toolchain in the [Cardputer ADV board guide](../../boards/M5Stack-Cardputer-ADV.md). From this directory:

```sh
arduino-cli compile --output-dir build --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB .
```

Install only `build/cardputer-adv-led.ino.bin`. Follow the board guide to transfer it through Launcher's USB mode or WUI and install it.

## Flash directly and replace Launcher

Find the Cardputer's port, then compile and upload directly:

```sh
arduino-cli board list
arduino-cli compile --upload --port <PORT> --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB .
```

A direct flash replaces the current Launcher setup. `<PORT>` is a value such as `COM5` on Windows or `/dev/ttyACM0` on Linux. The LED color is set in `led.Color(255, 255, 255)`.
