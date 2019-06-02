int air1 = 10;
int air2 = 11;
int air3 = 12;
int delay_time = 100;//各流路がONになっている時間

void setup(){
    pinMode(air1,OUTPUT);
    pinMode(air2,OUTPUT);
    pinMode(air3,OUTPUT);
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
