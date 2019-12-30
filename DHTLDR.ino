#include <dht.h>

int LED = 9; 
int LDR = A2;

int DHT11pin=A0;
int Heating=2;
int Cooling=3;
int MoreMoist=12;
int MoreDry=13;
float DHTTemp=0;
float DHTHum=0;

dht DHT ;

void setup() {

  Serial.begin(9600);
  pinMode(Heating, OUTPUT);
  pinMode(Cooling, OUTPUT);
  pinMode(MoreMoist, OUTPUT);
  pinMode(MoreDry, OUTPUT);
  pinMode(DHT11pin, INPUT);
  
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
  delay(1000);
}

void loop() {

  int LDRvalue = analogRead(LDR);
  

   DHT.read11(DHT11pin);
   DHTTemp=(DHT.temperature);
   DHTHum=(DHT.humidity);
   Serial.print("DHT11 Temperature measured as:");
   Serial.println(DHT.temperature);
   Serial.print("DHT11 Humidity measured as:");
   Serial.println(DHT.humidity);


  if(LDRvalue <= 400)
  {
    //analogWrite(LED, HIGH);
    analogWrite(LED, (1023-LDRvalue));
    Serial.print(" it's dark here!! we need some light \n");
    Serial.println(LDRvalue);
  }
  else 
    {
      //analogWrite(LED, LOW);
      analogWrite(LED, (1023-LDRvalue));
      Serial.print(" it's bright here!! we need some dark \n");
      Serial.println(LDRvalue);
   }


   if (DHTTemp < 16) {
    digitalWrite(Heating, HIGH);
    delay (1000);
    digitalWrite(Cooling, LOW);
    delay (1000);
   }

   if (DHTTemp > 22) {
    digitalWrite(Heating, LOW);
    delay (1000);
    digitalWrite(Cooling, HIGH);
    delay (1000);
   }

   if (DHTHum < 41) {
    digitalWrite(MoreMoist, HIGH);
    delay (1000);
    digitalWrite(MoreDry, LOW);
    delay (1000);
   }

   if (DHTTemp > 80) {
    digitalWrite(MoreMoist, LOW);
    delay (1000);
    digitalWrite(MoreDry, HIGH);
    delay (1000);
   }


   delay (500);   
}
