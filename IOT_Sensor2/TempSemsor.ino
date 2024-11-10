int tempPin=1;
int val;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    val=analogRead(tempPin);
    float m = val*(5.0/1023.0);
    float cel=(m -0.5)*100;

    Serial.print("Temperature :");
    Serial.print(cel);
    Serial.print(" *C");
    Serial.println();
    delay(1500);
}