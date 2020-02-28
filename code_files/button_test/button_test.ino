



const int buttonPin[] = {2,3,4,5,6,7}; // arduino pins where buttons are connected
const int ledPin = LED_BUILTIN; // led pin on the board. (don't need to connect external LED).

int ledState = HIGH;
int buttonState[6];//={LOW, LOW, LOW, LOW, LOW,LOW}; // current reading from the buttons
int lastButtonState[] = {LOW, LOW, LOW, LOW, LOW, LOW}; //previous reading from the buttons

unsigned long lastDebounceTime[] = {0,0,0,0,0,0}; // the last time the output pin was toggled
unsigned long debounceDelay = 20; // the debounce time. increase if buttons not read correctly

void setup() {
  for(int i = 0; i<6; i++){
    pinMode(buttonPin[i], INPUT);
  }
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, ledState);

}

void loop() {
  //int reading[6];
  for(int i=0; i<6; i++)
  {
    //reading[i] = digitalRead(buttonPin[i]);
    int reading = digitalRead(buttonPin[i]);

    if(reading != lastButtonState[i]){
      lastDebounceTime[i] = millis();
    }

    if((millis() - lastDebounceTime[i]) > debounceDelay){
      if(reading != buttonState[i]){
        buttonState[i] = reading;
        if (buttonState[i] == HIGH){
          ledState = !ledState;
        }
      }
    }
  }
    
}
