#include <Adafruit_NeoPixel.h>

constexpr unsigned long INTERVAL_MS = 1000;
constexpr uint8_t RGB_POWER_PIN = 38;
constexpr uint8_t RGB_DATA_PIN = 21;

Adafruit_NeoPixel led(1, RGB_DATA_PIN, NEO_GRB + NEO_KHZ800);

void setLed(bool on) {
  led.setPixelColor(0, on ? led.Color(255, 255, 255) : 0);
  led.show();
}

void setup() {
  pinMode(RGB_POWER_PIN, OUTPUT);
  digitalWrite(RGB_POWER_PIN, HIGH);
  delay(10);

  led.begin();
  led.setBrightness(32);
  setLed(false);
}

void loop() {
  static unsigned long previousTime = 0;
  static bool ledOn = false;

  const unsigned long now = millis();

  if (now - previousTime >= INTERVAL_MS) {
    previousTime = now;
    ledOn = !ledOn;
    setLed(ledOn);
  }
}
