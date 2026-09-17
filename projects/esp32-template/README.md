# ESP32 Template

Minimal Arduino sketch for ESP32 boards. The built-in LED blinks on for 1 second and off for 1 second for 30 seconds total, then stays off.

After copying the folder for a real project, keep the `.ino` filename the same as the folder name.

For Neovim/LSP support, connect the board and generate `sketch.yaml` with the detected port and FQBN:

```sh
arduino-cli board list
arduino-cli board attach -p <PORT> -b <FQBN> esp32-template.ino
```
