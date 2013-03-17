#include "Arduino.h"
#include "SerialCommand.h"

SerialCommand::SerialCommand(int baudrate)
{
  //initializer
  Serial.begin(baudrate);
}

void SerialCommand::parsecommand(char *cmdin){
  int idx = 0; 
  int lenbuf = 0;
  char *cmdbuf;
  char segment[bufmax];
  char temporal[bufmax];

  strcpy(cmdtoparse,cmdin);
  cmdptr = cmdtoparse;
  cmdptr[strlen(cmdptr)] = ' ';
  cmdbuf = cmdptr;

  while(1){
    segmentrest = strstr(cmdptr," ");
    if(!segmentrest) break;
    cmdptr = &segmentrest[1];

    memset( &segment, 0, bufmax );
    strncpy(segment,cmdbuf,(cmdptr-cmdtoparse-1)-lenbuf);
 
    lenbuf = (cmdptr-cmdtoparse-1);
    cmdbuf = cmdptr;
    
    strcpy(cmdparsed[idx],segment);
    //Serial.println(cmdparsed[idx]);

    idx++;
  }
}


void SerialCommand::readcommand(){
  cmdready = 0;

  if(Serial.available() > 0){
    inbyte = Serial.read();

    if(inbyte != bufmax){
      cmdbuffer[cmdindex] = (char)inbyte;
      cmdindex++;
      return;
    }
    else{
      strcpy(cmdred,cmdbuffer);
      memset( &cmdbuffer, 0, bufmax );
      cmdindex = 0;
      cmdready = 1;
      return;
    }
  }
  

  return;
}
