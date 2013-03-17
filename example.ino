#include <SerialCommand.h>


SerialCommand sepa(9600);

void setup(){
}

void loop(){
  
  sepa.readcommand();
  if(sepa.cmdready){

    sepa.parsecommand(sepa.cmdred);

    Serial.println("*incomming command + arguments:"); 
    Serial.println(sepa.cmdparsed[0]);
    Serial.println(sepa.cmdparsed[1]);
    Serial.println(sepa.cmdparsed[2]);
  }
}