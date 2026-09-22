# Embedded Projects

Arduino projects and board setup guides.

## Set up a board

Run the interactive setup script from the repository root:

```sh
nu scripts/setup.nu
```

Select one or more devices with `Space`, then press `Enter`. The script runs each board-specific setup.

## Board guides

- [ESP32](boards/ESP32.md) ⟶ Generic Espressif ESP32 boards, including ESP32-C3, ESP32-C6, and ESP32-H2.
- [M5Stack Cardputer ADV](boards/M5Stack-Cardputer-ADV.md) ⟶ Launcher workflow, Arduino CLI setup, and direct flashing.

## Projects

- [ESP32 onboard LED](projects/esp32-onboard-led) ⟶ Blink sketch for ESP32-C3, ESP32-C6, and ESP32-H2 boards.
- [Cardputer ADV display](projects/cardputer-adv-display) ⟶ Display blink sketch for the M5Stack Cardputer ADV.
- [Cardputer ADV LED](projects/cardputer-adv-led) ⟶ Onboard RGB LED blink sketch for the M5Stack Cardputer ADV.
- [Cardputer ADV HTTP LED](projects/cardputer-adv-http-led) ⟶ Toggle the onboard RGB LED through HTTP, with Wi-Fi secrets supplied by SecretSpec and 1Password.
