#ifndef SerialCommand_h
#define SerialCommand_h

class SerialCommand
{

 public:
  SerialCommand(int baudrate); 

  int const bufmax = 10;
  int const cmdmax = 20;

  char cmdparsed[10][10];
  char cmdred[30];

  int cmdready = 0;

  void parsecommand(char *cmdin);
  void readcommand();    

 private:
  int inbyte = 0;
  int cmdindex = 0;
  char cmdbuffer[30];
  char cmdtoparse[30];

  char *cmdptr;
  char *segmentrest;
  char *segment;
  
};

#endif

