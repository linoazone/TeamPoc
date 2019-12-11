int LED = 9; // digital PWM like analog
// Pulse width modulation (PWM) is a powerful technique for controlling analog circuits with a microprocessor's digital outputs.
int LDR = A1;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int LDRvalue = analogRead(LDR);
  /*Serial.println(LDRvalue);
  delay(1000);*/
  
 // LDRvalue = constrain(LDRvalue, 400, 500);
 // LDRvalue = map(LDRvalue, 400, 500, 255, 0);
  Serial.println(LDRvalue);
  analogWrite(LED, LDRvalue);
  delay(1000);

  if(LDRvalue >= 400)
  {
    //digitalWrite(LED, HIGH);
    analogWrite(LED, LDRvalue);
    Serial.print(" it's dark here!! we need some light \n");
    Serial.println(LDRvalue);
    delay(1000);
    }
    else 
    {
      //digitalWrite(LED, LOW);
      analogWrite(LED, LDRvalue);
      Serial.print(" it's bright here!! we need some dark \n");
      Serial.println(LDRvalue);
      delay(1000);
      }
  

}
