#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "NARZO 70 Pro 5G";
const char* password = "shreyas@0308";

const int flamePin = D0;
const int buzzer = D1;

// Your bot token and chat ID
String botToken = "7617443270:AAEtlh04UuA8P2bnPXhGT1_riQZ5e7QUaWo";
String chatID = "1224747223";

bool fireAlertSent = false;

void sendTelegramMessage(String message) {
  WiFiClientSecure client;
  client.setInsecure(); // Needed for HTTPS

  if (!client.connect("api.telegram.org", 443)) {
    Serial.println("Connection failed");
    return;
  }

  String url = "/bot" + botToken + "/sendMessage?chat_id=" + chatID + "&text=" + message;

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: api.telegram.org\r\n" +
               "Connection: close\r\n\r\n");

  delay(1000);
  while (client.available()) {
    String line = client.readStringUntil('\n');
    Serial.println(line);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(flamePin, INPUT);
  pinMode(buzzer, OUTPUT);q
  digitalWrite(buzzer, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");
}

void loop() {
  int flameStatus = digitalRead(flamePin);

  if (flameStatus == 0 && !fireAlertSent) {
    digitalWrite(buzzer, HIGH);
    sendTelegramMessage("🔥 Fire Detected! Please check immediately!");
    fireAlertSent = true;
  } 
  else if (flameStatus == 1) {
    digitalWrite(buzzer, LOW);
    fireAlertSent = false; // Reset so next detection triggers again
  }

  delay(1000);
}
