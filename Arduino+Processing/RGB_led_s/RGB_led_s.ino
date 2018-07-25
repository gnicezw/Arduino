
int led_red;
int led_blue;
int led_green;    //declare variables
int light_val;
int ldr_pin = A0;
int mapd_light;
int test;
void setup() {
  Serial.begin(9600); //start the serial monitor
  // put your setup code here, to run once:
  //init RGB lED PINS  as outputs
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  //pinMode(A0, INPUT); //init LDR as an input

}

void loop() {
  // put your main code here, to run repeatedly:
//Set pin 10 high
light_val = analogRead(A1);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH); //Also set 11 and 12 high\

//Serial.println(light_val); //write the ldr value to serial monitor
//int mapd_light = map(light_val, 1019, 1023, 0, 256);//Map the ldr values to Led intensity
Serial.println(mapd_light);


}
