#include <Arduino.h>

constexpr unsigned long INTERVAL_MS = 1000;
constexpr int BLINK_COUNT = 15;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  for (int i = 0; i < BLINK_COUNT; ++i) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(INTERVAL_MS);

    digitalWrite(LED_BUILTIN, LOW);
    delay(INTERVAL_MS);
  }

  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {}
