#include <M5Cardputer.h>

constexpr unsigned long INTERVAL_MS = 1000;
constexpr int BLINK_COUNT = 15;

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

  for (int i = 0; i < BLINK_COUNT; ++i) {
    showState(true);
    delay(INTERVAL_MS);

    showState(false);
    delay(INTERVAL_MS);
  }

  showState(false);
}

void loop() {}
