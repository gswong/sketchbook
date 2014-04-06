#!/usr/bin/python
# Usage: ./commander.py "<string>"

import serial
import sys

if(len(sys.argv) != 2):
  print "Error: bad argument"

ser = serial.Serial('/dev/ttyACM0',9600, timeout=20)
ser.write(sys.argv[1])
