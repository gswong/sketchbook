/*
  Copyright 2014 Gary Wong. All rights reserved. 
  
  Description:
    Command a led to be turned on and off from the serial connection.
*/

#include <CommandReader.h>

int cp_off = 12;
int cp_on = 11;
int dp_off = 6;
int dp_on = 5;

// Helper function to wrap singleton.
CommandReader& reader() {
  return CommandReader::getInstance();
}

// Perform turning a led on or off based on commanded text.
void commandHandler(const String& command) {
  if (command.equals("cp on") ) {
    digitalWrite(cp_on, HIGH);
    digitalWrite(cp_off, LOW);
  }
  else if (command.equals("cp off") ) {
    digitalWrite(cp_on, LOW);
    digitalWrite(cp_off, HIGH);
  }
  else if (command.equals("dp on") ) {
    digitalWrite(dp_on, HIGH);
    digitalWrite(dp_off, LOW);
  }
  else if (command.equals("dp off") ) {
    digitalWrite(dp_on, LOW);
    digitalWrite(dp_off, HIGH);
  }
  else {
    Serial.println("Unrecognized command.");
  }
}

void setup() {                
  // Initialize the digital pin as an output for a LED.
  pinMode(cp_on, OUTPUT);
  pinMode(cp_off, OUTPUT);
  pinMode(dp_on, OUTPUT);
  pinMode(dp_off, OUTPUT);
  commandHandler("cp off");
  commandHandler("dp off");
}

void loop() {
  // Read command from serial input and perform commanded action.
  String command( reader().listen() );
  Serial.println( command );
  commandHandler( command );
}
