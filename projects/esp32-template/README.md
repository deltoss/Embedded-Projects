# ESP32 Template

Minimal Arduino sketch for Espressif ESP32-H2, ESP32-C3, and ESP32-C6 dev boards. The built-in LED blinks on for 1 second and off for 1 second for 30 seconds total, then stays off.

The Espressif reference dev boards use an addressable RGB LED on GPIO8, but Arduino exposes it through `LED_BUILTIN`, so the sketch can treat it as a simple on/off LED.

After copying the folder for a real project, keep the `.ino` filename the same as the folder name.

For Neovim/LSP support, connect the board and generate `sketch.yaml` with the detected port and FQBN:

```sh
arduino-cli board list
arduino-cli board attach -p <PORT> -b <FQBN> esp32-template.ino
```
