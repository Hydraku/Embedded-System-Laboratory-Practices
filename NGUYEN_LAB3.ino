/*

Task 1
   void loop(){
  int buttonState = digitalRead(button);

  digitalWrite(ledRed, HIGH);
  delay(1000);
  digitalWrite(ledRed, LOW);
  delay(1000);
    if (button == LOW) {
    Serial.println("Button Pressed!");
  } 
  }

Task 2
   const int ledRed = 13;    // the number of the LED pin
   const int button = 2;  // the number of the pushbutton pin
   volatile bool interrupt = false;
   volatile bool ledState = LOW;
   volatile bool interruptEnabled = true;

   void setup(){
    Serial.begin(9600);
    pinMode(ledRed, OUTPUT);
    pinMode(button, INPUT_PULLUP); 
    pinMode(button2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(button), ISR_Function, FALLING);
    Serial.begin(9600);
    }
    void loop(){
  if(interrupt){
    Serial.println("Interrupt Triggered!");
    interrupt = false;
  }
}

Task 3

void toggleLED_ISR(){
  interrupt = true;
}

Task 4
  volatile bool interrupt = false;

void loop(){
  if(interrupt){
    Serial.println("Button Pressed!");
    interrupt = false;
  }
}
void toggleLED_ISR(){
  interrupt = true;
}

Task 5
   void loop(){
  digitalWrite(ledRed,ledstate);
}
void toggleLED_ISR(){
  ledstate = !ledstate;
}
Task 6
   void loop(){
  digitalWrite(ledRed,ledstate);
  delay(5000);
}
Task 7
   void loop(){
  digitalWrite(ledRed,ledstate);
}
void toggleLED_ISR(){
  ledstate = !ledstate;
}
void detachISR(){
  
  detachInterrupt(digitalPinToInterrupt(button));
  Serial.println("INTERUPT DEATACH");
}

Task 8
  The interrupt is more responsive than the polling method, as it immediately triggers an action when the button is pressed, regardless of the main loop delay. 
  In contrast, the polling method checks the button state periodically, which may lead to delayed responses.

*/
   const int ledRed = 13;    // the number of the LED pin
   const int button = 2;  // the number of the pushbutton pin
   const int button2 = 3;
   volatile bool interrupt = false;
   volatile bool ledState = LOW;
   volatile bool interruptEnabled = true;

   void setup(){
    Serial.begin(9600);
    pinMode(ledRed, OUTPUT);
    pinMode(button, INPUT_PULLUP); 
    pinMode(button2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(button), ISR_Function, FALLING);
    Serial.begin(9600);
    attachInterrupt(digitalPinToInterrupt(button2), detachISR,FALLING);
    Serial.begin(9600);
    }
   