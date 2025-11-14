

  void setup() {
    
  }

  void loop() {
    
  }

/*
TASK 1
  const int potPin = A0;

  void setup() {
  Serial.begin(9600);

  }

  void loop() {
  int potValue = analogRead(potPin);
  int potPercentage = map(potValue, 0, 1023, 0, 100);
  Serial.print("Raw Value:");
  Serial.print(potValue);
  Serial.print("Potentiometer Percentage:");
  Serial.println(potPercentage);
  delay(100);

  }

TASK 2
  const int ldrPin = A1;

  void setup() {
  Serial.begin(9600);
  }
  
  void loop() {
    int ldrValue = analogRead(ldrPin);
    if (ldrValue < 300) {
      Serial.println("Dark");
    } else if (ldrValue < 700) {
      Serial.println("Dim");
    } else {
      Serial.println("Bright");
  }
  delay(100);
  }

TASK 3
  const int pn2222Pin = A2;

  void setup() {
    Serial.begin(9600);
  }

  void loop() {
    int pn2222Value = analogRead(pn2222Pin);
    float voltage = (pn2222Value / 1024.0) * 5.0;
    float temperatureC = (voltage - 0.65) / 0.0021; // approximate temperature coefficient
    float temperatureF = (temperatureC * 9 / 5) + 32;
    Serial.print("Temperature (C): ");
    Serial.print(temperatureC);
    Serial.print(", Temperature (F): ");
    Serial.println(temperatureF);
    delay(100);
  }

TASK 4
  const int pirPin = 2;
  int pirState = LOW;

  void setup() {
    pinMode(pirPin, INPUT);
    Serial.begin(9600);
  }

  void loop() {
    int pirValue = digitalRead(pirPin);
    if (pirValue == HIGH && pirState == LOW) {
      Serial.println("Motion Detected!");
      pirState = HIGH;
    } else if (pirValue == LOW && pirState == HIGH) {
      Serial.println("Motion Ended!");
      pirState = LOW;
    }
    delay(100);
  }

TASK 5
  const int potPin = A0;
  const int ldrPin = A1;
  const int ledPin = 13;

  void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
  }

  void loop() {
    int potValue = analogRead(potPin);
    int ldrValue = analogRead(ldrPin);
    int threshold = map(potValue, 0, 1023, 0, 1023);
    if (ldrValue < threshold) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
    delay(100);
  }

TASK 6
  const int pn2222Pin = A2;

  void setup() {
    Serial.begin(9600);
  }

  void loop() {
    int pn2222Value = analogRead(pn2222Pin);
    float voltage = (pn2222Value / 1024.0) * 5.0;
    float temperatureC = (voltage - 0.65) / 0.0021; // approximate temperature coefficient
    Serial.print("Temp: ");
    Serial.println(temperatureC, 2);
    delay(5000);
  }

TASK 7
  const int potPin = A0;
  const int ldrPin = A1;
  const int pn2222Pin = A2;

  void setup() {
    Serial.begin(9600);
  }
  
  void loop() {
    int potValue = analogRead(potPin);
    int ldrValue = analogRead(ldrPin);
    int pn2222Value = analogRead(pn2222Pin);
    float voltage = (pn2222Value / 1024.0) * 5.0;
    float temperatureC = (voltage - 0.65) / 0.0021; // approximate temperature coefficient
    int potPercentage = map(potValue, 0, 1023, 0, 100);
    Serial.print("Pot: ");
    Serial.print(potPercentage);
    Serial.print("%, Light: ");
    Serial.print(ldrValue);
    Serial.print(", Temp: ");
    Serial.println(temperatureC, 2);
    delay(2000);
  }

TASK 8

  const int pirPin = 2;
  const int greenLedPin = 13;
  const int redLedPin = 12;

  void setup() {
    pinMode(pirPin, INPUT);
    pinMode(greenLedPin, OUTPUT);
    pinMode(redLedPin, OUTPUT);
  }

  void loop() {
    int pirValue = digitalRead(pirPin);
    if (pirValue == HIGH) {
      digitalWrite(greenLedPin, LOW);
      digitalWrite(redLedPin, HIGH);
      delay(100);
      digitalWrite(redLedPin, LOW);
      delay(100);
    } else {
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      delay(100);
      digitalWrite(greenLedPin, LOW);
      delay(100);
    }
  }

*/
