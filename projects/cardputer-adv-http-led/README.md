# Cardputer ADV HTTP LED

This sketch connects the Cardputer ADV to Wi-Fi and starts a small HTTP server. Each `POST /led/toggle` request toggles the onboard RGB LED and returns `on` or `off`.

## Prerequisites

- The [Cardputer ADV board setup](../../boards/M5Stack-Cardputer-ADV.md)
- Arduino CLI
- Nushell
- [SecretSpec](https://secretspec.dev/)
- 1Password
- 1Password CLI (`op`)

Install the required Arduino library once:

```sh
arduino-cli lib install "Adafruit NeoPixel"
```

## Store the Wi-Fi secrets

The committed `secretspec.toml` declares two required secrets and routes them to the default 1Password `Private` vault. It does not contain either secret value.

From this directory, store the values once:

```sh
secretspec set IOT_WIFI_SSID --provider onepassword
secretspec set IOT_WIFI_PASSWORD --provider onepassword
```

Change `onepassword://` in `secretspec.toml` if you want to use a different vault.

## Compile and flash

Find the Cardputer's port:

```sh
arduino-cli board list
```

Then let SecretSpec load the Wi-Fi values and run the flash script:

```sh
secretspec run -- nu flash.nu <PORT>
```

The script writes the values to a private temporary header, removes them from the build process's environment, compiles and uploads the sketch, then deletes the header.

## Toggle the LED

Open the serial monitor to find the Cardputer's IP address:

```sh
arduino-cli monitor --port <PORT> --config baudrate=115200
```

Restart the Cardputer if the connection message already passed before the monitor opened.

Send a request to the printed address:

```sh
curl --request POST http://<IP>/led/toggle
```

The password is absent from Git, but it must be embedded in the firmware so the Cardputer can join Wi-Fi. Anyone who can extract and inspect the firmware may be able to recover it. The endpoint also has no authentication, so use this example only on a network you trust.
