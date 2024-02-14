int ledPin = 5;
int buttonOnPin = 8;
int buttonOffPin = 9;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonOnPin, INPUT_PULLUP);
  pinMode(buttonOffPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonOnPin) == LOW){
    digitalWrite(ledPin, HIGH);
  }

  if(digitalRead(buttonOffPin) == LOW){
    digitalWrite(ledPin, LOW);
  }
}
