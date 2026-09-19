# ESP32 Onboard LED

Minimal Arduino sketch for Espressif ESP32-H2, ESP32-C3, and ESP32-C6 dev boards. The built-in LED continuously blinks on for one second and off for one second.

The Espressif reference dev boards use an addressable RGB LED on GPIO8, but Arduino exposes it through `LED_BUILTIN`, so the sketch can treat it as a simple on/off LED.

The `.ino` filename matches the folder name as required by Arduino.

For Neovim/LSP support, connect the board and generate `sketch.yaml` with the detected port and FQBN:

```sh
arduino-cli board list
arduino-cli board attach -p <PORT> -b <FQBN> esp32-onboard-led.ino
```
