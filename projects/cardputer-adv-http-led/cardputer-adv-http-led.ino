#include <Adafruit_NeoPixel.h>
#include <WebServer.h>
#include <WiFi.h>

constexpr uint8_t RGB_POWER_PIN = 38;
constexpr uint8_t RGB_DATA_PIN = 21;
constexpr uint16_t HTTP_PORT = 80;

Adafruit_NeoPixel led(1, RGB_DATA_PIN, NEO_GRB + NEO_KHZ800);
WebServer server(HTTP_PORT);

bool ledOn = false;

void setLed(bool on) {
  led.setPixelColor(0, on ? led.Color(255, 255, 255) : 0);
  led.show();
}

void toggleLed() {
  ledOn = !ledOn;
  setLed(ledOn);

  server.send(200, "text/plain", ledOn ? "on\n" : "off\n");
}

void connectToWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(IOT_WIFI_SSID, IOT_WIFI_PASSWORD);

  Serial.print("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print('.');
  }

  Serial.println();
  Serial.print("LED endpoint: http://");
  Serial.print(WiFi.localIP());
  Serial.println("/led/toggle");
}

void setup() {
  Serial.begin(115200);

  pinMode(RGB_POWER_PIN, OUTPUT);
  digitalWrite(RGB_POWER_PIN, HIGH);
  delay(10);

  led.begin();
  led.setBrightness(32);
  setLed(false);

  connectToWifi();

  server.on("/led/toggle", HTTP_POST, toggleLed);
  server.begin();
}

void loop() {
  server.handleClient();
}
