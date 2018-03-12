/* created by Adam Nagy for Karkhana
12 March 2018. 
Interactive Snakes and Ladders game */ 

//pin declarations
const int button1 = 2;
const int button2 = 4;
const int ladderFader = 3;
const int ladderSwitch1 = 5;
const int ladderSwitch2 = 6;
const int snakeSwitch1 = 7;



int fadeValue = 0;
int sliderValue = 0; 


//button 1 setup
int buttonState1;
int button1Counter = 0;
int lastButtonState1 = 0;

//button 2 setup
int buttonState2;
int button2Counter = 0;
int lastButtonState2 = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(button1, INPUT); 
  pinMode(button2, INPUT);
  pinMode(ladderFader, OUTPUT);
  pinMode(ladderSwitch1, OUTPUT);
  pinMode(ladderSwitch2, OUTPUT);
  pinMode(snakeSwitch1, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  sliderValue = analogRead(A0);

//fader
  fadeValue = map(sliderValue, 0, 1023, 0, 255);
  analogWrite(ladderFader, fadeValue);
  delay(10);

//button 1 controls ladder 1
 if (buttonState1 != lastButtonState1) {
  if (buttonState1 == HIGH) {
    button1Counter++;
    delay(3);
    Serial.print("current button counter: ");
    Serial.println(button1Counter);
    
  }
 }
 lastButtonState1 = buttonState1;
   //change ladder 1 state
  if (button1Counter % 2 == 1) {digitalWrite(ladderSwitch1, HIGH);}
  else{digitalWrite(ladderSwitch1, LOW);}

  //button 2 controls ladder 2 and snake 1
  if (buttonState2 != lastButtonState2) {
  if (buttonState2 == HIGH) {
    button2Counter++;
    delay(3);
    Serial.print("current button counter: ");
    Serial.println(button2Counter);
  } 
 }
 //avoiding bouncing
 lastButtonState2 = buttonState2;
 //change ladder 2 state and snake 1 state
  if (button2Counter % 2 == 1) {digitalWrite(ladderSwitch2, HIGH); digitalWrite(snakeSwitch1, LOW);}
  else{digitalWrite(ladderSwitch2, LOW); digitalWrite(snakeSwitch1, HIGH);}

//end
}

