# Cardputer ADV HTTP LED

This sketch connects the Cardputer ADV to Wi-Fi and starts a small HTTP server. `GET /` returns `Ok` as plain text. Each `POST /led/toggle` request toggles the onboard RGB LED and returns `on` or `off`.

## Prerequisites

- The build toolchain from the [Cardputer ADV board guide](../../boards/M5Stack-Cardputer-ADV.md)
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

## Build for Launcher

From this directory, let SecretSpec load the Wi-Fi values and build the application image:

```sh
secretspec run -- nu build.nu
```

The script writes the values to a private temporary header, compiles the sketch, then deletes the header. Install only `build/cardputer-adv-http-led.ino.bin`. Follow the board guide to transfer it through Launcher's USB mode or WUI and install it.

## Flash directly and replace Launcher

Find the Cardputer's port, then build and upload directly:

```sh
arduino-cli board list
secretspec run -- nu flash.nu <PORT>
```

A direct flash replaces the current Launcher setup. `<PORT>` is a value such as `COM5` on Windows or `/dev/ttyACM0` on Linux.

## Toggle the LED

Open the serial monitor to find the Cardputer's IP address:

```sh
arduino-cli monitor --port <PORT> --config baudrate=115200
```

Restart the Cardputer if the connection message already passed before the monitor opened.

Send a request to the printed address:

```sh
curl http://<IP>/
# Ok

curl --request POST http://<IP>/led/toggle
# on or off
```

The password is absent from Git, but it must be embedded in the firmware so the Cardputer can join Wi-Fi. Anyone who can extract and inspect the firmware may be able to recover it. The endpoint also has no authentication, so use this example only on a network you trust.
