#include <Arduino.h>

constexpr unsigned long INTERVAL_MS = 1000;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  static unsigned long previousTime = 0;
  static bool ledOn = false;

  const unsigned long now = millis();

  if (now - previousTime >= INTERVAL_MS) {
    previousTime = now;
    ledOn = !ledOn;

    if (ledOn) {
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
