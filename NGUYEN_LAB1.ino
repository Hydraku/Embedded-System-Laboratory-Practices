/*
//Task 1
//Task 2 
  void setup() is initializing the codes
  void loop() is looping the codes
//Task 3
  The led pin is connected to 9 and is an output
//Task 4
  int ledPin = 9; 
//Task 5
  digitalWrite(ledPin, HIGH);  
  delay(1000);                        
  digitalWrite(ledPin, LOW);
  delay(1000);            
//Task 6
  digitalWrite(ledPin, HIGH);   
  delay(200);                       
  digitalWrite(ledPin, LOW);    
  delay(800);
//Task 7
  digitalWrite(ledPin, HIGH);   
  Serial.println("LED turned ON");  // Print when ON
  delay(200);                       
  digitalWrite(ledPin, LOW);    
  Serial.println("LED turned OFF"); // Print when OFF
  delay(800);  
*/ 

int ledPin = 9;  

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);   // Initialize serial at 9600 baud
}

void loop() {
  digitalWrite(ledPin, HIGH);   
  Serial.println("LED turned ON");  // Print when ON
  delay(200);                       

  digitalWrite(ledPin, LOW);    
  Serial.println("LED turned OFF"); // Print when OFF
  delay(800);                 
}
