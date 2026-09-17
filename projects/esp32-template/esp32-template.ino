#include <Arduino.h>

constexpr unsigned long INTERVAL_MS = 30000;

void setLed(bool on) {
#ifdef RGB_BUILTIN
  rgbLedWrite(RGB_BUILTIN, on ? 32 : 0, on ? 32 : 0, on ? 32 : 0);
#elif defined(LED_BUILTIN)
  digitalWrite(LED_BUILTIN, on ? HIGH : LOW);
#endif
}

void setup() {
#ifdef LED_BUILTIN
  pinMode(LED_BUILTIN, OUTPUT);
#endif
}

void loop() {
  setLed(true);
  delay(INTERVAL_MS);

  setLed(false);
  delay(INTERVAL_MS);
}
