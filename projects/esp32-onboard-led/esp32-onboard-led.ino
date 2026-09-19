#include <Arduino.h>

constexpr unsigned long INTERVAL_MS = 1000;

void setLed(bool on) {
  if (on) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  setLed(false);
}

void loop() {
  static unsigned long previousTime = 0;
  static bool ledOn = false;

  const unsigned long msSinceStart = millis();

  if (msSinceStart - previousTime >= INTERVAL_MS) {
    previousTime = msSinceStart;
    ledOn = !ledOn;
    setLed(ledOn);
  }
}
