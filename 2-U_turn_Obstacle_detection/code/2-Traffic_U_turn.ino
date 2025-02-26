//@Ediylabs
const int buzzer = 3;
const int trig1 = 8;
const int trig2 = 9;
const int echno1 = 7;
const int echno2 = 10;
const int red1 = 6;

const int red2 = 13;
const int yel1 = 5;
const int yel2 = 12;
const int gr1 = 4;
const int gr2 = 11;

void setup()
{
    pinMode(trig1, OUTPUT);
    pinMode(trig2, OUTPUT);
    pinMode(echno1, INPUT);
    pinMode(echno2, INPUT);
    pinMode(red1, OUTPUT);
    pinMode(red2, OUTPUT);
    pinMode(yel1, OUTPUT);
    pinMode(yel2, OUTPUT);
    pinMode(gr1, OUTPUT);
    pinMode(gr2, OUTPUT);
    pinMode(buzzer, OUTPUT);
}

void loop()
{
    digitalWrite(trig1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig1, LOW);
    int duration = pulseIn(echno1, HIGH);
    int distance = duration * 0.034 / 2;

    // Check distance and alert drivers
    if (distance < 7)
    {                             // Adjust distance threshold
        digitalWrite(red2, HIGH); // Red LED indicates danger
        digitalWrite(yel2, LOW);
        digitalWrite(gr2, LOW);
    }
    else if (distance < 20)
    {
        digitalWrite(red2, LOW);
        digitalWrite(yel2, HIGH); // Yellow LED indicates caution
        digitalWrite(gr2, LOW);
    }
    else
    {
        digitalWrite(red2, LOW);
        digitalWrite(yel2, LOW);
        digitalWrite(gr2, HIGH); // Green LED indicates safe distance
    }

    digitalWrite(trig2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig2, LOW);
    int duration2 = pulseIn(echno2, HIGH);
    int distance2 = duration2 * 0.034 / 2;

    // Check distance and alert drivers
    if (distance2 < 7)
    {                             // Adjust distance threshold
        digitalWrite(red1, HIGH); // Red LED indicates danger
        digitalWrite(yel1, LOW);
        digitalWrite(gr1, LOW);
    }
    else if (distance2 < 20)
    {
        digitalWrite(red1, LOW);
        digitalWrite(yel1, HIGH); // Yellow LED indicates caution
        digitalWrite(gr1, LOW);
    }
    else
    {
        digitalWrite(red1, LOW);
        digitalWrite(yel1, LOW);
        digitalWrite(gr1, HIGH); // Green LED indicates safe distance
    }

    if (distance < 7 && distance2 < 7)
    {
        digitalWrite(3, HIGH);
        delay(50);
        digitalWrite(3, LOW);
        delay(50);
    }
    else if (distance < 7 || distance2 < 7)
    {
        digitalWrite(3, HIGH);
        delay(500);
        digitalWrite(3, LOW);
        delay(500);
    }
    else
    {
        digitalWrite(3, LOW);
    }
    delay(100);
}