#include <Stepper.h>
// defines pins numbers

int i=5000;
int t=800;
char input;

const int dirPin_1  = 3;
const int dirPin_2  = 6;
const int dirPin_3  = 9;
const int dirPin_4  = 12;
const int stepPin_1 = 4;
const int stepPin_2 = 7; 
const int stepPin_3 = 10; 
const int stepPin_4 = 13;  
const int enPin_1 = 5;
const int enPin_2 = 8;
const int enPin_3 = 11;
const int enPin_4 = 14;

void setup() {
    Serial.begin(115200); 
    delay(1000);  
    Serial.println("Type something!");
  // Sets the two pins as Outputs
  pinMode(stepPin_1,OUTPUT); 
  pinMode(stepPin_2,OUTPUT); 
  pinMode(stepPin_3,OUTPUT); 
  pinMode(stepPin_4,OUTPUT); 
  pinMode(dirPin_1,OUTPUT);
  pinMode(dirPin_2,OUTPUT);
  pinMode(dirPin_3,OUTPUT);
  pinMode(dirPin_4,OUTPUT);
  pinMode(enPin_1,OUTPUT);
  pinMode(enPin_2,OUTPUT);
  pinMode(enPin_3,OUTPUT);
  pinMode(enPin_4,OUTPUT);
  digitalWrite(enPin_1,LOW);
  digitalWrite(enPin_2,LOW);
  digitalWrite(enPin_3,LOW);
  digitalWrite(enPin_4,LOW);
}

void loop() {

    if(Serial.available()){
        input = Serial.read();
        Serial.print("You typed: " );
        Serial.println(input);

        if(input == '1'){
          forward();
          }
         
        if(input == '2'){
          backward();
          }

        if(input == '3'){
          righmove();
          }
         
        if(input == '4'){
          leftmove();
          }
    }
}

void forward(){
  digitalWrite(dirPin_1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  digitalWrite(dirPin_2,HIGH);
  digitalWrite(dirPin_3,LOW);
  digitalWrite(dirPin_4,LOW);
  for(int x = 0; x < t; x++) {
    digitalWrite(stepPin_1,HIGH); 
    digitalWrite(stepPin_2,HIGH);
    digitalWrite(stepPin_3,HIGH);
    digitalWrite(stepPin_4,HIGH);
    delayMicroseconds(i); 
    digitalWrite(stepPin_1,LOW);
    digitalWrite(stepPin_2,LOW);
    digitalWrite(stepPin_3,LOW);
    digitalWrite(stepPin_4,LOW); 
    delayMicroseconds(i);
  }
}

void backward(){
  digitalWrite(dirPin_1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  digitalWrite(dirPin_2,LOW);
  digitalWrite(dirPin_3,HIGH);
  digitalWrite(dirPin_4,HIGH);

  
  for(int x = 0; x < t; x++) {
    digitalWrite(stepPin_1,HIGH); 
    digitalWrite(stepPin_2,HIGH); 
    digitalWrite(stepPin_3,HIGH); 
    digitalWrite(stepPin_4,HIGH); 
    delayMicroseconds(i); 
    digitalWrite(stepPin_1,LOW); 
    digitalWrite(stepPin_2,LOW); 
    digitalWrite(stepPin_3,LOW); 
    digitalWrite(stepPin_4,LOW); 
    delayMicroseconds(i);
  }
}

void righmove(){
  digitalWrite(dirPin_1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  digitalWrite(dirPin_2,LOW);
  digitalWrite(dirPin_3,LOW);
  digitalWrite(dirPin_4,HIGH);
  for(int x = 0; x < t; x++) {
    digitalWrite(stepPin_1,HIGH); 
    digitalWrite(stepPin_2,HIGH);
    digitalWrite(stepPin_3,HIGH);
    digitalWrite(stepPin_4,HIGH);
    delayMicroseconds(i); 
    digitalWrite(stepPin_1,LOW);
    digitalWrite(stepPin_2,LOW);
    digitalWrite(stepPin_3,LOW);
    digitalWrite(stepPin_4,LOW); 
    delayMicroseconds(i);
  }
}

void leftmove(){
  digitalWrite(dirPin_1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  digitalWrite(dirPin_2,HIGH);
  digitalWrite(dirPin_3,HIGH);
  digitalWrite(dirPin_4,LOW);


  
  for(int x = 0; x < t; x++) {
    digitalWrite(stepPin_1,HIGH); 
    digitalWrite(stepPin_2,HIGH);
    digitalWrite(stepPin_3,HIGH);
    digitalWrite(stepPin_4,HIGH);
    delayMicroseconds(i); 
    digitalWrite(stepPin_1,LOW);
    digitalWrite(stepPin_2,LOW);
    digitalWrite(stepPin_3,LOW);
    digitalWrite(stepPin_4,LOW); 
    delayMicroseconds(i);
  }
}
