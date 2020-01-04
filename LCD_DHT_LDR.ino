#include<LiquidCrystal.h>
#include <DHT.h>

int LED = 9; 
int LDR = A2;

int DHT11pin=A0;
LiquidCrystal LCD(12, 11, 4, 3, 2, 1); //Initialisation de l'écran LCD avec les numéros des pins utilisés

int Heating=5;
int Cooling=6;
int MoreMoist=7;
int MoreDry=8;

float DHTTemp=0; // temp mesurée
float DHTHum=0; // pourcentage humidité

dht DHT ; // initialisation du capteur

void setup() {

  Serial.begin(9600);
  LCD.begin(16,2); // nb de colonnes et lignes de l'ecran
  LCD.clear();
  
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

  // PARTIE LCD
  if(isnan(DHTTemp) || isnan(DHTHum)) // si les valeurs retournées ne sont pas des nb
  {
    LCD.setCursor(0, 1); //Positionnement du curseur
    LCD.print(DHTTYPE); //On affiche le type de capteur
    LCD.setCursor(5, 1);
    LCD.print(" illisible"); //On affiche l'erreur
  }
  else
  {
    //mise en forme et affichage des informations sur l'écran LCD
    LCD.setCursor(0, 0); //Positionnement du curseur
    LCD.print("Degres : ");
    LCD.setCursor(9, 0);
    LCD.print(DHTTemp); //Affichage de la température
    LCD.setCursor(13, 0);
    LCD.print((char)223); //Affiche le caractère ° (degrés)
    LCD.setCursor(14, 0);
    LCD.print("C"); //En degrés Celsuis
    LCD.setCursor(0, 1);
    LCD.print("Humidite : ");
    LCD.setCursor(11, 1);
    LCD.print(DHTHum); //Affichage de l'humidité
    LCD.setCursor(15, 1);
    LCD.print("%");
  }
  delay(5000);

  // PARTIE LDR
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

   // PARTIE DHT11
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
