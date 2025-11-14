/*
  Task 1
    const int ledRed = 10;    // the number of the LED pin
    const int ledGreen = 11;    // the number of the LED pin

    void setup() {
  // initialize the LED pin as an output:
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

void loop() {
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledRed, LOW);
  delay(50);

  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, HIGH);
  delay(50);
}

  Task 2
    const int button = 2;  // the number of the pushbutton pin

    void setup(){
    pinMode(button, INPUT_PULLUP);
    Serial.begin(9600);
    }

    void loop(){
    int buttonState = digitalRead(button);
      //LOW - because in arduino it means pushed button, not 0 LMAO
    if (buttonState == LOW) {
    Serial.println("turned ON")
  } else {
    Serial.println("turned OFF")
  }
  delay(50);
  }

  Task 3
    pinMode(button, INPUT);

  Task 4
  const int ledRed = 10;    // the number of the LED pin
  const int ledGreen = 11;    // the number of the LED pin
  const int button = 2;  // the number of the pushbutton pin

   void setup(){
    Serial.begin(9600);
    pinMode(ledRed, OUTPUT);
    pinMode(ledGreen, OUTPUT);
    pinMode(button, INPUT);
    }

   void loop(){
  int buttonState = digitalRead(button);

    if (buttonState == LOW) {
    digitalWrite(ledGreen, HIGH);
    Serial.println("GREEN turned ON");
    digitalWrite(ledRed, LOW);
    Serial.println("RED turned OFF");
  } else {
    digitalWrite(ledRed, HIGH);
    Serial.println("RED turned ON");
    digitalWrite(ledGreen, LOW);
    Serial.println("GREEN turned OFF");
  }
  
  }

  Task 5
  const int ledRed = 10;    // the number of the LED pin
  const int ledGreen = 11;    // the number of the LED pin
  const int button = 2;  // the number of the pushbutton pin

   void setup(){
    Serial.begin(9600);
    pinMode(ledRed, OUTPUT);
    pinMode(ledGreen, OUTPUT);
    pinMode(button, INPUT);
    }

   void loop(){
  int buttonState = digitalRead(button);

     if (buttonState == LOW) {
    digitalWrite(ledRed, HIGH);
    Serial.println("RED turned ON");
    digitalWrite(ledGreen, LOW);
    Serial.println("Green turned OFF");
  } else {
    digitalWrite(ledGreen, HIGH);
    Serial.println("Green turned ON");
    digitalWrite(ledRed, LOW);
    Serial.println("RED turned OFF");
  }

  }

  Task 6
    delay(50); // Debounce delay

  Task 7
    const int ledRed = 9;

    int brightness = 0;
    int fade = 5;

    void setup() {
  // initialize the LED pin as an output:
  pinMode(ledRed, OUTPUT);
}

  void loop() {
  analogWrite(ledRed, brightness);

  brightness = brightness +fade;
  if(brightness <=0 || brightness >= 255){
    fade = -fade
  }

  }

  delay(50); 
  
  Task 8
  const int ledRed = 9;
  const int ledGreen = 11;
  const int buttonPin = 2;   // button pin

  int buttonState = 0; 
  int brightness = 0;   // start from dark
  int fade = 5;         // step size

  void setup() {
    pinMode(ledRed, OUTPUT);
    pinMode(ledGreen, OUTPUT);
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
  }

  void loop() {
    buttonState = digitalRead(buttonPin);

    if (buttonState == LOW) {
      analogWrite(ledGreen, brightness);
      Serial.print("Green: ");
      Serial.print(brightness);

      analogWrite(ledRed, 255 - brightness);
      Serial.print(" | Red: ");
      Serial.println(255 - brightness);

    } else {
      analogWrite(ledRed, brightness);
      Serial.print("Red: ");
      Serial.print(brightness);

      analogWrite(ledGreen, 255 - brightness);
      Serial.print(" | Green: ");
      Serial.println(255 - brightness);
    }

    brightness += fade;
    if (brightness <= 0 || brightness >= 255) {
      fade = -fade;
    }
    delay(50);
  }

*/

   const int button = 2;  // the number of the pushbutton pin

    void setup(){
    pinMode(button, INPUT_PULLUP);
    Serial.begin(9600);
    }

    void loop(){
    if (button == HIGH) {
    Serial.println("turned ON");
  } else {
    Serial.println("turned OFF");
  }
   delay(10000);
    }