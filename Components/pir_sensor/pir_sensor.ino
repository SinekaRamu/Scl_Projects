// Ediylabs - Feb 27, 2025
// PIR sensor

const int PIR = D4;

void setup()
{
    Serial.begin(9600);
    pinMode(PIR, INPUT_PULLDOWN_16);
    Serial.println("start");
}

void loop()
{
    int sensor = digitalRead(PIR);
    Serial.println(sensor);
    // if (sensor == HIGH)
    // {
    //     Serial.println("Got You!");
    // }else{
    //     Serial.println("Nope!");
    // }
    delay(1000);
}
