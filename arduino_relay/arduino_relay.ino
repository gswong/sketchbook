/*
  Copyright 2014 Gary Wong. All rights reserved. 
  
  Description:
    Command a led to be turned on and off from the serial connection.
*/

#include <CommandReader.h>

int led = 13;

// Helper function to wrap singleton.
CommandReader& reader() {
  return CommandReader::getInstance();
}

// Perform turning a led on or off based on commanded text.
void commandHandler(const String& command) {
  if (command.equals("turn on led") ) {
    digitalWrite(led, HIGH);
  }
  else if (command.equals("turn off led") ) {
    digitalWrite(led, LOW);
  }
  else {
    Serial.println("Unrecognized command.");
  }
}

void setup() {                
  // Initialize the digital pin as an output for a LED.
  pinMode(led, OUTPUT);
  
  // Initialize the serial port.
  Serial.begin(9600);
  Serial.println("Arduino powered on.");
}

void loop() {
  // Read command from serial input and perform commanded action.
  String command( reader().listen() );
  Serial.println( command );
  commandHandler( command );
}
