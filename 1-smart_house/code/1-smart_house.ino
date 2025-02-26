#define BLYNK_TEMPLATE_ID "TMPL30BbelEbs"
#define BLYNK_TEMPLATE_NAME "HOME"
#define BLYNK_AUTH_TOKEN "GQj0sEwwbNs5CpN-8lzHds0OL3WLOWl9"

#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#include <Servo.h>

const char* ssid = "wifi"; 
const char* password = "12340678";

Servo servo;

#define relayFan D1
#define relayLight D2

void setup() {
  Serial.begin(115200);
  digitalWrite(relayFan, HIGH);
  digitalWrite(relayLight, HIGH);

  pinMode(relayFan, OUTPUT);
  pinMode(relayLight, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED ) {  // 20 retries max
    delay(1000);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to WiFi!");
  }
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);


  servo.attach(13); //D7
  servo.write(0);
  delay(2000);
}

BLYNK_WRITE(V0) 
{
    if (param.asInt() == 1) {
        digitalWrite(relayFan, LOW);
    } else {
        digitalWrite(relayFan, HIGH);
    }
}

BLYNK_WRITE(V1) 
{
    if (param.asInt() == 1) {
        digitalWrite(relayLight, LOW);
    } else {
        digitalWrite(relayLight, HIGH);
    }
}

BLYNK_WRITE(V2) 
{
    if (param.asInt() == 1) {
          servo.write(180);
    } else {
          servo.write(0);
    }
}

void loop() {
  Blynk.run();
}

// void connectWiFi() {
//   WiFi.disconnect(true);  // Disconnect from any previous WiFi
//   delay(1000);
//   WiFi.mode(WIFI_STA);  // Set WiFi to Station mode
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi");
//   int retries = 0;
//   while (WiFi.status() != WL_CONNECTED && retries < 20) {  // 20 retries max
//     delay(1000);
//     Serial.print(".");
//     retries++;
//   }

//   if (WiFi.status() == WL_CONNECTED) {
//     Serial.println("\nConnected to WiFi!");
//   } else {
//     Serial.println("\nWiFi connection failed. Restarting...");
//     ESP.restart();  // Restart ESP if connection fails
//   }
// }
