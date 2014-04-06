/*
  Copyright 2014 Gary Wong. All rights reserved. 
  
  Description:
    Command a led to be turned on and off from the serial connection.
*/

#include <CommandReader.h>

int cp_status = 12;
int cp_control = 11;
int dp_status = 6;
int dp_control = 5;

// Helper function to wrap singleton.
CommandReader& reader() {
  return CommandReader::getInstance();
}

// Perform turning a led on or off based on commanded text.
void commandHandler(const String& command) {
  if (command.equals("cp on") ) {
    digitalWrite(cp_control, HIGH);
    digitalWrite(cp_status, HIGH);
  }
  else if (command.equals("cp off") ) {
    digitalWrite(cp_control, LOW);
    digitalWrite(cp_status, LOW);
  }
  else if (command.equals("dp on") ) {
    digitalWrite(dp_control, HIGH);
    digitalWrite(dp_status, HIGH);
  }
  else if (command.equals("dp off") ) {
    digitalWrite(dp_control, LOW);
    digitalWrite(dp_status, LOW);
  }
  else {
    Serial.println("Unrecognized command.");
  }
}

void setup() {                
  // Initialize the digital pin as an output for a LED.
  pinMode(cp_control, OUTPUT);
  pinMode(cp_status, OUTPUT);
  pinMode(dp_control, OUTPUT);
  pinMode(dp_status, OUTPUT);
  
  // Notify when Arduino is ready to receive messages.
  Serial.begin(9600);
  Serial.flush();
  Serial.println( "ready" );
  Serial.flush();
}

void loop() {
  // Read command from serial input and perform commanded action.
  String command( reader().listen() );
  //Serial.println( command );
  commandHandler( command );
}
