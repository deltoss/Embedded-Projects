# Embedded Projects

## Prerequisites

These instructions assume **CachyOS / Arch Linux**.

### Arduino CLI

Install Arduino CLI from the Arch repositories:

```sh
sudo pacman -S arduino-cli
```

Verify the installation:

```sh
arduino-cli version
```

Create the Arduino CLI configuration file:

```sh
arduino-cli config init
```

### ESP32 support

Add Espressif's stable ESP32 package index:

```sh
arduino-cli config add board_manager.additional_urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
```

Update the package index and install the ESP32 Arduino core:

```sh
arduino-cli core update-index
arduino-cli core install esp32:esp32
```

Verify that the ESP32 core is installed:

```sh
arduino-cli core list
```

### USB access

Connect the board and confirm Arduino CLI can see it:

```sh
arduino-cli board list
```

This should show the board's serial port and, when it can be identified, its **FQBN** (Fully Qualified Board Name). Keep the detected FQBN; it will be used when compiling, uploading, and creating the project's `sketch.yaml`.

If the board appears but uploading fails with a permissions error, check that your user has read/write access to the board's serial device before changing any project configuration.

At this point the machine has the required Arduino CLI and ESP32 platform support to start an ESP32 Arduino project.
