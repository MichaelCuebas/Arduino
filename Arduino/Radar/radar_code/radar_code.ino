// Includes the Servo library
#include <Servo.h>

// Defines Trig and Echo pins of the Ultrasonic Sensor
const int trigPin = 10; // Pin connected to the trigger pin of the ultrasonic sensor
const int echoPin = 11; // Pin connected to the echo pin of the ultrasonic sensor

// Variables for the duration and the distance
long duration; // To hold the duration of the sound wave travel
int distance; // To hold the calculated distance

Servo myServo; // Creates a servo object for controlling the servo motor

// Setup function runs once when the program starts
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts serial communication at 9600 baud rate
  myServo.attach(12); // Attaches the servo motor to pin 12
}

// Loop function runs repeatedly as long as the Arduino has power
void loop() {
  // Rotates the servo motor from 15 to 165 degrees
  for (int i = 15; i <= 165; i++) {
    myServo.write(i); // Moves the servo to the specified degree
    delay(30); // Delays for stability

    distance = calculateDistance(); // Measures the distance using the ultrasonic sensor
    
    // Sends the current degree and distance to the Serial Port
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }

  // Rotates the servo motor from 165 to 15 degrees in reverse
  for (int i = 165; i > 15; i--) {
    myServo.write(i); // Moves the servo to the specified degree
    delay(30); // Delays for stability

    distance = calculateDistance(); // Measures the distance using the ultrasonic sensor
    
    // Sends the current degree and distance to the Serial Port
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance() {
  digitalWrite(trigPin, LOW); // Clears the trigger pin
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH); // Sets the trigger pin to high for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // Clears the trigger pin
  
  duration = pulseIn(echoPin, HIGH); // Measures the duration of the sound wave
  distance = duration * 0.034 / 2; // Calculates the distance based on the speed of sound
  return distance; // Returns the calculated distance
}
