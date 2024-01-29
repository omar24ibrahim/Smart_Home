#include <DHT.h>
#define FLAME  2
#define LDR  3
#define PIR 4
#define buzzerFLAME 5
#define ledLDR  6
#define DHTPIN 7
#define WATER 8
#define ledPIR 10
#define buzzerGAS 11
#define GAS A5
#define DHTTYPE DHT22  


DHT dht(DHTPIN, DHTTYPE); 
int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;
int PIRValue = 0;
int THRESHOLD = 275;
float hum;  
float temp; 


void setup()
{
Serial.begin(9600);
dht.begin();
pinMode(buzzerFLAME, OUTPUT);
pinMode(FLAME, INPUT);
pinMode(LDR, INPUT);
pinMode(WATER, INPUT); 
pinMode(ledLDR, OUTPUT); 
pinMode(PIR, INPUT);
pinMode(ledPIR, OUTPUT);
pinMode(buzzerGAS, OUTPUT);
pinMode(GAS, INPUT);
}

void loop()
{ 
  LIGHTSensor();
  PIRSensor();
  TEMPHUMDSensor();
  FLAMESensor(); 
  WATERSensor();
  SMOKESensor();
}

void PIRSensor()
 {
   if(digitalRead(PIR) == HIGH) {
      if(lockLow) {
         PIRValue = 1;
         lockLow = false;
         delay(50);
      }
      takeLowTime = true;
      digitalWrite(ledPIR, HIGH);
   }
   if(digitalRead(PIR) == LOW) {
      if(takeLowTime){
         lowIn = millis();
         takeLowTime = false;
      }
      if(!lockLow && millis() - lowIn > pause) {
         PIRValue = 0;
         lockLow = true;
         delay(50);
      }
      digitalWrite(ledPIR,LOW);
   }
   }
   void TEMPHUMDSensor()
   {
     hum = dht.readHumidity();
     temp= dht.readTemperature();
    Serial.print("*&");
    Serial.print(hum);
    Serial.println(" %");
    Serial.print("*+");
    Serial.print(temp);
    Serial.println(" C");
   }
   void FLAMESensor()
   {
   if(digitalRead(FLAME) == LOW)
   {
    digitalWrite(buzzerFLAME, HIGH);
    Serial.print("*=Danger");
   }
   else
   {
    digitalWrite(buzzerFLAME, LOW);
    Serial.print("*=Safe");
   }
   }
void LIGHTSensor()
{
    if(digitalRead(LDR) == HIGH)
   {
    digitalWrite(ledLDR, HIGH);
   }
   else
   {
    digitalWrite(ledLDR, LOW);
   }
} 
void WATERSensor(){
 if( digitalRead(WATER) == HIGH) {
      Serial.print("*_Raining");
   }else {
      Serial.print("*_No rain");
   } 
}
 void SMOKESensor()
 {
   int analogValue = analogRead(GAS);
   if (analogValue >= THRESHOLD) {
    digitalWrite(buzzerGAS, HIGH); 
    Serial.print("*#Danger");
   }
   else {
   digitalWrite(buzzerGAS, LOW);
   Serial.print("*#Safe");
   }
   delay(5);
}