#include <M5Cardputer.h>
#include <Adafruit_SHT4x.h>
#include <Wire.h>

Adafruit_SHT4x sensor;

void setup() {
  auto config = M5.config();
  M5Cardputer.begin(config);

  auto& display = M5Cardputer.Display;
  display.setTextColor(TFT_WHITE, TFT_BLACK);
  display.setTextSize(2);
  display.setCursor(8, 8);
  display.println("Temperature");

  Wire.begin(2, 1); // Cardputer ADV Grove: SDA = GPIO 2, SCL = GPIO 1

  if (!sensor.begin(&Wire)) {
    display.println("ENV-IV not found");
    while (true) {
      delay(1000);
    }
  }
}

void loop() {
  sensors_event_t humidity, temperature;
  auto& display = M5Cardputer.Display;

  display.fillRect(0, 40, 240, 95, TFT_BLACK);
  display.setCursor(8, 60);

  if (sensor.getEvent(&humidity, &temperature)) {
    display.setTextSize(3);
    display.printf("%.1f C", temperature.temperature);
  } else {
    display.setTextSize(2);
    display.print("Read failed");
  }

  delay(1000);
}
