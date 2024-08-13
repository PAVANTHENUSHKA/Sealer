#include <Stepper.h>

// Define the number of steps per revolution for your stepper motor
const int stepsPerRevolution = 2000;  // This is for a 28BYJ-48 motor
const int buttonPin = 2;
const int relaypin = 4;
int buttonState = 0;
// Initialize the Stepper library with the pins you connected to on the Arduino
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); // Pins: IN1, IN3, IN2, IN4

void setup() {
  // Set the speed at 15 RPM
  myStepper.setSpeed(15);
  
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Stepper motor control");
  pinMode(buttonPin, INPUT);
  pinMode(relaypin,OUTPUT);
  //digitalWrite(relay,HIGH);
  //pinMode(3, OUTPUT);
}

void sealer() {
  int t=0;
  // Step one revolution in one direction:
  buttonState = digitalRead(buttonPin);
  while (buttonState == LOW){
    buttonState = digitalRead(buttonPin);
    delay(1000);
    t=t+1;
    if (t>5){
      break;
    }

  }
  Serial.println("breaked");
  // Step one revolution in the other direction:
  

  delay(1000);
  if (buttonState == HIGH){
    //digitalWrite(3,HIGH);
    Serial.println("Counterclockwise");
    Serial.println(buttonState);
    myStepper.step(stepsPerRevolution);
    delay(1000);

    digitalWrite(relaypin,LOW);
    delay(2000);
    Serial.println("sealing");
    digitalWrite(relaypin,HIGH);

    Serial.println("Clockwise");
    myStepper.step(-stepsPerRevolution);
    delay(1000);
    //Serial.println("LCD");
    buttonState = LOW;

  }
  else{//digitalWrite(3,LOW);
  Serial.println("g");}
  delay(1000);
}
void loop(){sealer();}