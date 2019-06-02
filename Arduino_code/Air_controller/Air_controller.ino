int air1 = 11;
int air2 = 12;
int air3 = 13;
int delay_time = 500;//各流路がONになっている時間

void setup(){
    pinMode(air1,OUTPUT);
    pinMode(air2,OUTPUT);
    pinMode(air3,OUTPUT);
    digitalWrite(air1,LOW);
    digitalWrite(air2,LOW);
    digitalWrite(air3,LOW);
    delay(5000);
}
void loop(){
    digitalWrite(air1,HIGH);
    digitalWrite(air2,LOW);
    digitalWrite(air3,LOW);
    delay(delay_time);
    digitalWrite(air1,LOW);
    digitalWrite(air2,HIGH);
    digitalWrite(air3,LOW);
    delay(delay_time);
    digitalWrite(air1,LOW);
    digitalWrite(air2,LOW);
    digitalWrite(air3,HIGH);
    delay(delay_time);
}
