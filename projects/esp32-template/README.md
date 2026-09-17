# ESP32 Template

Minimal Arduino sketch for ESP32 boards. The built-in LED stays on for 30 seconds, then off for 30 seconds, and repeats.

After copying the folder for a real project, keep the `.ino` filename the same as the folder name.

For Neovim/LSP support, connect the board and generate `sketch.yaml` with the detected port and FQBN:

```sh
arduino-cli board list
arduino-cli board attach -p <PORT> -b <FQBN> esp32-template.ino
```
