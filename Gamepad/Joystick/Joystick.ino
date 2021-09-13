
#include <Joystick.h>

#define joyX A3
#define joyY A2

#define joyThrottle A1

#define joyButton1 2
#define joyButton2 3
#define joyButton3 4
#define joyButton4 5
#define joyButton5 6
#define joyButton6 7

int xAxis_ = 0;
int yAxis_ = 0;
int throttle_ = 0;

  int lastButton1State = 0;
  int lastButton2State = 0;
  int lastButton3State = 0;
  int lastButton4State = 0;
  int lastButton5State = 0;
  int lastButton6State = 0;

Joystick_ Joystick(0x12, JOYSTICK_TYPE_JOYSTICK, 6, 0,true,true,false,false,false,false,false,true,false,false,false);

const bool initAutoSendState = true;

void setup() {

  pinMode(joyButton1, INPUT_PULLUP);
  pinMode(joyButton2, INPUT_PULLUP);
  pinMode(joyButton3, INPUT_PULLUP);
  pinMode(joyButton4, INPUT_PULLUP);
  pinMode(joyButton5, INPUT_PULLUP);
  pinMode(joyButton6, INPUT_PULLUP);

  Joystick.begin();
}

void loop() {
  xAxis_ = analogRead(joyX);
  xAxis_ = map(xAxis_,0,1023,0,255);

  Joystick.setXAxis(xAxis_);
  yAxis_ = analogRead(joyY);
  yAxis_ = map(yAxis_,0,1023,0,255);
  Joystick.setYAxis(yAxis_);

  throttle_ = analogRead(joyThrottle);
  throttle_ = map(throttle_,0,1023,0,255);
  Joystick.setThrottle(throttle_);
  
  int currentButton1State = !digitalRead(joyButton1);
  if (currentButton1State != lastButton1State){
    Joystick.setButton(0, currentButton1State);
    lastButton1State = currentButton1State;
  }

    int currentButton2State = !digitalRead(joyButton2);
  if (currentButton2State != lastButton2State){
    Joystick.setButton(1, currentButton2State);
    lastButton2State = currentButton2State;
  }
    int currentButton3State = !digitalRead(joyButton3);
  if (currentButton3State != lastButton3State){
    Joystick.setButton(2, currentButton3State);
    lastButton3State = currentButton3State;
  }
     int currentButton4State = !digitalRead(joyButton4);
  if (currentButton4State != lastButton4State){
    Joystick.setButton(3, currentButton4State);
    lastButton4State = currentButton4State;
  }
     int currentButton5State = !digitalRead(joyButton5);
  if (currentButton5State != lastButton5State){
    Joystick.setButton(4, currentButton5State);
    lastButton5State = currentButton5State;
  }
     int currentButton6State = !digitalRead(joyButton6);
  if (currentButton6State != lastButton6State){
    Joystick.setButton(5, currentButton6State);
    lastButton6State = currentButton6State;
  }
delay(10);
}
