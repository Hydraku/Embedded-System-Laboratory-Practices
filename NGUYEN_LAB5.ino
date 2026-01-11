 #include <Servo.h>
    Servo myServo;
    const int potPin = A0;
    const int enA = 3;
    const int in1 = 4;
    const int in2 = 5;
    const int relayPin = 8;
    const int buttonPin = 2;
    bool relayState = false;
    void setup() {
      myServo.attach(9);
      pinMode(enA, OUTPUT);
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);
      pinMode(relayPin, OUTPUT);
      pinMode(buttonPin, INPUT);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    }
    void loop() {
      // Servo sweep
      static int servoPosition = 0;
      static bool servoDirection = true;
      if (servoDirection) {
        servoPosition++;
        if (servoPosition >= 180) servoDirection = false;
      } else {
        servoPosition--;
        if (servoPosition <= 0) servoDirection = true;
      }
      myServo.write(servoPosition);
      // DC motor speed control
      int potValue = analogRead(potPin);
      int motorSpeed = map(potValue, 0, 1023, 0, 255);
      analogWrite(enA, motorSpeed);
      // Relay toggle
      if (digitalRead(buttonPin) == HIGH) {
        delay(50); // debouncing
        if (digitalRead(buttonPin) == HIGH) {
          relayState = !relayState;
          digitalWrite(relayPin, relayState);
          while (digitalRead(buttonPin) == HIGH);
        }
      }
      delay(15);
    }

/*
TASK 1
    #include <Servo.h>
    Servo myServo;
    void setup() {
      myServo.attach(9);
    }
    void loop() {
      for (int i = 0; i <= 180; i++) {
        myServo.write(i);
        delay(15);
      }
      for (int i = 180; i >= 0; i--) {
        myServo.write(i);
        delay(15);
      }
    }

TASK 2
    #include <Servo.h>
    Servo myServo;
    const int potPin = A0;
    void setup() {
      myServo.attach(9);
    }
    void loop() {
      int potValue = analogRead(potPin);
      int servoPosition = map(potValue, 0, 1023, 0, 180);
      myServo.write(servoPosition);
      delay(15);
    }

TASK 3
    const int enA = 3;
    const int in1 = 4;
    const int in2 = 5;
    void setup() {
      pinMode(enA, OUTPUT);
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    }
    void loop() {
      analogWrite(enA, 255);
    }

TASK 4
    const int enA = 3;
    const int in1 = 4;
    const int in2 = 5;
    const int potPin = A0;
    void setup() {
      pinMode(enA, OUTPUT);
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    }
    void loop() {
      int potValue = analogRead(potPin);
      int motorSpeed = map(potValue, 0, 1023, 0, 255);
      analogWrite(enA, motorSpeed);
    }

TASK 5
    const int enA = 3;
    const int in1 = 4;
    const int in2 = 5;
    const int buttonPin = 2;
    void setup() {
      pinMode(enA, OUTPUT);
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);
      pinMode(buttonPin, INPUT);
    }
    void loop() {
      if (digitalRead(buttonPin) == HIGH) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
      } else {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
      }
      analogWrite(enA, 255);
    }

TASK 6
    const int relayPin = 8;
    void setup() {
      pinMode(relayPin, OUTPUT);
    }
    void loop() {
      digitalWrite(relayPin, HIGH);
      delay(2000);
      digitalWrite(relayPin, LOW);
      delay(2000);
    }

TASK 7
    const int relayPin = 8;
    const int buttonPin = 2;
    bool relayState = false;
    void setup() {
      pinMode(relayPin, OUTPUT);
      pinMode(buttonPin, INPUT);
    }
    void loop() {
      if (digitalRead(buttonPin) == HIGH) {
        delay(50); // debouncing
        if (digitalRead(buttonPin) == HIGH) {
          relayState = !relayState;
          digitalWrite(relayPin, relayState);
          while (digitalRead(buttonPin) == HIGH);
        }
      }
    }

TASK 8
    #include <Servo.h>
    Servo myServo;
    const int potPin = A0;
    const int enA = 3;
    const int in1 = 4;
    const int in2 = 5;
    const int relayPin = 8;
    const int buttonPin = 2;
    bool relayState = false;
    void setup() {
      myServo.attach(9);
      pinMode(enA, OUTPUT);
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);
      pinMode(relayPin, OUTPUT);
      pinMode(buttonPin, INPUT);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    }
    void loop() {
      // Servo sweep
      static int servoPosition = 0;
      static bool servoDirection = true;
      if (servoDirection) {
        servoPosition++;
        if (servoPosition >= 180) servoDirection = false;
      } else {
        servoPosition--;
        if (servoPosition <= 0) servoDirection = true;
      }
      myServo.write(servoPosition);
      // DC motor speed control
      int potValue = analogRead(potPin);
      int motorSpeed = map(potValue, 0, 1023, 0, 255);
      analogWrite(enA, motorSpeed);
      // Relay toggle
      if (digitalRead(buttonPin) == HIGH) {
        delay(50); // debouncing
        if (digitalRead(buttonPin) == HIGH) {
          relayState = !relayState;
          digitalWrite(relayPin, relayState);
          while (digitalRead(buttonPin) == HIGH);
        }
      }
      delay(15);
    }
*/
