# Cardputer ADV Display

A minimal M5Stack Cardputer ADV sketch. It continuously shows `ON` for one second and clears the display for one second.

The sketch uses the display instead of `LED_BUILTIN`, preserving the logic of [`../esp32-onboard-led`](../esp32-onboard-led) on Cardputer ADV hardware.

## Build and upload

Follow the [Cardputer ADV board guide](../../boards/M5Stack-Cardputer-ADV.md) first. From this directory:

```sh
arduino-cli compile --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB .
arduino-cli upload --port <PORT> --fqbn m5stack:esp32:m5stack_cardputer:FlashSize=8M,PartitionScheme=default_8MB .
```

`<PORT>` is a value such as `COM5` on Windows or `/dev/ttyACM0` on Linux.
