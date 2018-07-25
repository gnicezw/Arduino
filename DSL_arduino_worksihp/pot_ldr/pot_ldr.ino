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
int pot_value;     //[varialbe integer for the pot]
int ldr_value;     //variable to hold ldr info
int freq;          //variable for mapping ranges
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);     //intialise the serial read in
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  pot_value = analogRead(A0);   //read in the pot value
  ldr_value = analogRead(A1); //read in the ldr value
  freq = map(ldr_value, 50, 282, 200, 5000);   //map the ldr value to a larger frequency range
  Serial.println(pot_value);   //so we can see the ldr value
  Serial.println(ldr_value);   //so we know how much light is hitting it
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  tone(3, freq);  //set off the tone whenever the light turns on
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  noTone(3);                           //turn the buzzer off when the light is off
  delay(pot_value);                       // wait for a second
}
