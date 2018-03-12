/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
//pin declarations
const int button1 = 2;
const int button2 = 4;
const int ladderFader = 3;
const int ladderSwitch = 5;

int fadeValue = 0;
int sliderValue = 0; 


//button 1 setup
int buttonState1;
int lastButtonState1 = 0;

//button 2 setup
int buttonState2;
int button1Counter = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(ladderFader, OUTPUT);
  pinMode(ladderSwitch, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  sliderValue = analogRead(A0);


 Serial.println(sliderValue);

  fadeValue = map(sliderValue, 0, 1023, 0, 255);

  analogWrite(ladderFader, fadeValue);
 
 delay(100);

 if (buttonState1 != lastButtonState1) {

  if (buttonState1 == HIGH) {
    button1Counter++;
    delay(3);
    Serial.print("current button counter: ");
    Serial.println(button1Counter);
    
  } else {
    
  }

 }
 lastButtonState1 = buttonState1;
   
  if (button1Counter % 2 == 1) {digitalWrite(ladderSwitch, HIGH);}
  else{digitalWrite(ladderSwitch, LOW);}

    
  }

