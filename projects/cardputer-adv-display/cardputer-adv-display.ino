#include <M5Cardputer.h>

constexpr unsigned long INTERVAL_MS = 1000;

void setDisplayState(bool on) {
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
  setDisplayState(false);
}

void loop() {
  static unsigned long previousTime = 0;
  static bool displayOn = false;

  const unsigned long msSinceStart = millis();

  if (msSinceStart - previousTime >= INTERVAL_MS) {
    previousTime = msSinceStart;
    displayOn = !displayOn;
    setDisplayState(displayOn);
  }
}
