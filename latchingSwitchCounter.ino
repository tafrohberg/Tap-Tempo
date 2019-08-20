// This is a simple sketch that I built for my Teensy to count state changes of a latching switch.

//declaring constants that wont change
const int buttonPin = 0; //the pin that the pushbutton is connected to
const int ledPin = LED_BUILTIN; //the Teensy can use its builtin LED

int buttonPushCounter = 0; //counter for the number of presses
int buttonState = 0; //current state of the button
int lastButtonState = 0; //previous state of the button
int stateCounter = 1; 
/* 
  stateCounter is an if loop counter to check the initial state of the latching switch
  if the buttonState == 1 or it's HIGH, then we need to decrease buttonPushCounter
  so that the initial button press is counted as 1. we only want that if statement
  to run once, so regardless of what happens in the loop, stateCounter becomes 2 and
  can never be run again because both conditions will never meet again.
*/ 

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Button state: ");
  Serial.println(buttonState);
  Serial.print("Button Push counter: ");
  Serial.println(buttonPushCounter);

  buttonState = digitalRead(buttonPin);
  
  if (buttonState == 1 && stateCounter == 1) {
    buttonPushCounter--;
    stateCounter = 2;
  } else {
    stateCounter = 2;
  }
  
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      buttonPushCounter++;
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    }
    delay(50);
  }
  
  lastButtonState = buttonState;
  
  delay (1000);
  
}
