/*
  Copyright 2014 Gary Wong. All rights reserved. 
  
  Description:
    Reads commands from text entered in the serial input stream.
*/

#ifndef CommandReader_h_
#define CommandReader_h_

#include <Arduino.h>

class CommandReader {
  public:
    // Singleton
    static CommandReader& getInstance() {
      static CommandReader instance;
      return instance;
    }
    
    // Listen to commands entered on serial port and return a C string of the command.
    const char* listen() {
      unsigned int byteCount = 0;
      char inputByte = 0;
      while(byteCount == 0) {
        delay(500);
        // Read from serial one byte at a time and append to string.
        while ( Serial.available() > 0 && byteCount <= kMaxCommandSizeInBytes ) {
          inputByte = Serial.read();
          command[byteCount] = inputByte;
          byteCount++;
          delay(50);
        }
        // Ensure last byte is null terminated.
        command[byteCount] = 0;
      }
      return command;
    }
  private:
    CommandReader() {
      Serial.begin(9600);
    }

    // Singleton - do not implement
    CommandReader(CommandReader const &);
    void operator=(CommandReader const &);

    static const char kMaxCommandSizeInBytes = 40;
    char command[ kMaxCommandSizeInBytes + 1 ];
};

#endif // CommandReader_h_
