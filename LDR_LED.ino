// Pulse width modulation (PWM) is a powerful technique for controlling analog circuits with a microprocessor's digital outputs.
int LED = 9; // digital PWM like analog
int LDR = A2;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
}

void loop() {
  
  int LDRvalue = analogRead(LDR);
 
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

  delay(1000);
}
