#include <Javino.h>			// About Javino --> https://javino.chon.group
#define pinLED 13
Javino javino;

void setup() {
 pinMode(pinLED,OUTPUT);

 // Javino Acts and Percept description
 javino.perceive(getExogenousPerceptions);
 javino.start(9600);

}

void loop() {
  javino.run();
}

//The serialEvent() function handles interruptions coming from the serial port.
void serialEvent(){javino.readSerial();}


//sends the exogenous environment's perceptions to the agent. 
int getExogenousPerceptions(){
 
int numeroL= random();
if(numeroL>0){
delay(50);
javino.addPercept("litros("+String(numeroL)+ ")");}
else getExogenousPerceptions();

}

//implements the commands to be executed in the exogenous environment. 
void ledOn(){
  digitalWrite(pinLED,HIGH); 
}

void ledOff(){
  digitalWrite(pinLED,LOW); 
}
