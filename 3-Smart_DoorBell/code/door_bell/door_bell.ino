// Ediylabs - Feb 27, 2025
// SMART DOOR BELL version 1

#define BLYNK_TEMPLATE_ID "TMPL30BbelEbs"
#define BLYNK_TEMPLATE_NAME "HOME"
#define BLYNK_AUTH_TOKEN "GQj0sEwwbNs5CpN-8lzHds0OL3WLOWl9"

#define PIR D2
#define DoorBell D5

#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

const char *ssid = "wifi";
const char *password = "123405678";

bool previousState = LOW;

void setup()
{
    Serial.begin(115200);
    pinMode(DoorBell, OUTPUT);
    digitalWrite(DoorBell, HIGH);
    pinMode(PIR, INPUT);

    connectWiFi();
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
    delay(2000);
}

void loop()
{
    Blynk.run();
    int currentState = digitalRead(PIR);

    if (currentState != previousState) // Detects change in state
    {
        if (currentState == HIGH)
        {
            digitalWrite(DoorBell, LOW);
            Serial.println("detected");
            Serial.println("bell HIGH");
            Blynk.logEvent("smart_door", "Person detected");
            delay(1000); // Small delay to avoid bounce
        }
        else
        {
            digitalWrite(DoorBell, HIGH);
            Serial.println("bell LOW");
        }
        previousState = currentState; // Update state only on change
    }

    delay(100); // Small debounce delay
}

void connectWiFi()
{
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    int retries = 0;

    while (WiFi.status() != WL_CONNECTED && retries < 20)
    {
        delay(1000);
        Serial.print(".");
        retries++;
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("\nConnected to WiFi!");
    }
    else
    {
        Serial.println("\nWiFi connection failed. Restarting...");
        ESP.restart();
    }
}
