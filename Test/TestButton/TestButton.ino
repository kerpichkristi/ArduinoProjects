boolean butt1,butt2,butt3,butt4,butt5,butt6;
unsigned long last_press; 
void setup() {

pinMode (2,INPUT_PULLUP);
pinMode (3,INPUT_PULLUP);
pinMode (4,INPUT_PULLUP);
pinMode (5,INPUT_PULLUP);
pinMode (6,INPUT_PULLUP);
pinMode (7,INPUT_PULLUP);
Serial.begin (9600);  
}

void loop() {
butt1 =! digitalRead(2);
butt2 =! digitalRead(3); 
butt3 =! digitalRead(4);
butt4 =! digitalRead(5);
butt5 =! digitalRead(6);
butt6 =! digitalRead(7);

/*Serial.println(analogRead(2));
delay(100);
Serial.println(analogRead(3));
delay(100);
/*Serial.println(analogRead(1));
delay(100);*/


if (butt1 == 1){
  Serial.println ("1");
delay(300);}
if (butt2 == 1){
  Serial.println ("2");
delay(300);}
if (butt3 == 1){
 Serial.println ("3"); 
delay(300);}
if (butt4 == 1){
 Serial.println ("4"); 
delay(300);}
if (butt5 == 1){
 Serial.println ("5");
delay(300);}
if (butt6 == 1){
 Serial.println ("6"); 
delay(300);}
}
