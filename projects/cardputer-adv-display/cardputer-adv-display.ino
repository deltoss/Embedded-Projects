#include <M5Cardputer.h>

constexpr unsigned long INTERVAL_MS = 1000;

void showState(bool on) {
  auto& display = M5Cardputer.Display;
  display.fillScreen(TFT_BLACK);

  if (!on) {
    return;
  }

  display.setCursor(0, 0);
  display.setTextColor(TFT_WHITE);
  display.setTextSize(3);
  display.print("ON");
}

void setup() {
  auto config = M5.config();
  M5Cardputer.begin(config);
  showState(false);
}

void loop() {
  static unsigned long previousTime = 0;
  static bool displayOn = false;

  const unsigned long now = millis();

  if (now - previousTime >= INTERVAL_MS) {
    previousTime = now;
    displayOn = !displayOn;
    showState(displayOn);
  }
}
