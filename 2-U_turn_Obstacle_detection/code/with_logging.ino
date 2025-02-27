// @Ediylabs

// U-turn Traffic Light System

#include <Arduino.h>

// PIN mapping
const int TRIG1 = 8;
const int TRIG2 = 9;

const int ECHO1 = 7;
const int ECHO2 = 10;

const int RED1 = 6;
const int RED2 = 13;

const int YELLOW1 = 5;
const int YELLOW2 = 12;

const int GREEN1 = 4;
const int GREEN2 = 11;

const int BUZZER = 3;

// Buzzer distance
const int FASTBEEP_DISTANCE1 = 7;
const int FASTBEEP_DISTANCE2 = 7;

const int SLOWBEEP_DISTANCE1 = 20;
const int SLOWBEEP_DISTANCE2 = 20;

// Light distance
const int SHORT_DISTANCE = 20;
const int LONG_DISTANCE = 40;

bool enableLogging = true; // Toggle logging on/off

int lastStateRed1 = LOW;
int lastStateYellow1 = LOW;
int lastStateGreen1 = LOW;

int lastStateRed2 = LOW;
int lastStateYellow2 = LOW;
int lastStateGreen2 = LOW;

int lastBuzzerState = LOW;

void setup()
{
    Serial.begin(9600); // Initialize serial communication

    pinMode(TRIG1, OUTPUT);
    pinMode(TRIG2, OUTPUT);

    pinMode(ECHO1, INPUT);
    pinMode(ECHO2, INPUT);

    pinMode(RED1, OUTPUT);
    pinMode(RED2, OUTPUT);

    pinMode(YELLOW1, OUTPUT);
    pinMode(YELLOW2, OUTPUT);

    pinMode(GREEN1, OUTPUT);
    pinMode(GREEN2, OUTPUT);

    pinMode(BUZZER, OUTPUT);
}

int getDistance(int echoPin, int trigPin)
{

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    int duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2;

    if (enableLogging)
    {
        if (distance < 100)
        {
            Serial.print((trigPin == TRIG1) ? "Distance1" : "Distance2");
            Serial.print(" measured: ");
            Serial.print(distance);
            Serial.println(" cm");
        }
    }
    return distance;
}

void updateTrafficLight(int distance, int redPin, int yellowPin, int greenPin, int &lastRed, int &lastYellow, int &lastGreen)
{
    int newRed, newYellow, newGreen;
    if (distance < SHORT_DISTANCE)
    {
        newRed = HIGH;
        newYellow = LOW;
        newGreen = LOW;
    }
    else if (distance < LONG_DISTANCE)
    {
        newRed = LOW;
        newYellow = HIGH;
        newGreen = LOW;
    }
    else
    {
        newRed = LOW;
        newYellow = LOW;
        newGreen = HIGH;
    }

    if (newRed != lastRed || newYellow != lastYellow || newGreen != lastGreen)
    {
        if (enableLogging)
        {
            Serial.print("Traffic Light Change (pin ");
            Serial.print(redPin);
            Serial.print("): Red=");
            Serial.print(newRed);
            Serial.print(", Yellow=");
            Serial.print(newYellow);
            Serial.print(", Green=");
            Serial.println(newGreen);
        }
    }

    digitalWrite(redPin, newRed);
    digitalWrite(yellowPin, newYellow);
    digitalWrite(greenPin, newGreen);

    lastRed = newRed;
    lastYellow = newYellow;
    lastGreen = newGreen;
}

void updateBuzzer(int distance1, int distance2)
{
    int newBuzzerState;
    if (distance1 < FASTBEEP_DISTANCE1 && distance2 < FASTBEEP_DISTANCE2)
    {
        newBuzzerState = HIGH;
        delay(50);
        digitalWrite(BUZZER, LOW);
        delay(50);
    }
    else if (distance1 < FASTBEEP_DISTANCE1 || distance2 < FASTBEEP_DISTANCE2)
    {
        newBuzzerState = HIGH;
        delay(500);
        digitalWrite(BUZZER, LOW);
        delay(500);
    }
    else
    {
        newBuzzerState = LOW;
    }

    if (newBuzzerState != lastBuzzerState)
    {
        if (enableLogging)
        {
            Serial.print("Buzzer State Change: ");
            Serial.println(newBuzzerState);
        }
    }

    digitalWrite(BUZZER, newBuzzerState);
    lastBuzzerState = newBuzzerState;
}

void loop()
{
    int distance1 = getDistance(ECHO1, TRIG1);
    int distance2 = getDistance(ECHO2, TRIG2);

    updateTrafficLight(distance1, RED1, YELLOW1, GREEN1, lastStateRed1, lastStateYellow1, lastStateGreen1);
    updateTrafficLight(distance2, RED2, YELLOW2, GREEN2, lastStateRed2, lastStateYellow2, lastStateGreen2);
    updateBuzzer(distance1, distance2);

    delay(100);
}