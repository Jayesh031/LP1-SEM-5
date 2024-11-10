int IR_remote=0;

void setup()
{
    pinMode(7,OUTPUT);
    pinMode(3,INPUT);
}

void loop()
{
    IR_remote=digitalRead(3);

    if(IR_remote == LOW)
    {
        digitalWrite(7,HIGH);
        delay(1000);
        digitalWrite(7,LOW);
        delay(1000);
    }
    else
    {
        didigitalWrite(7,LOW);
    }
}