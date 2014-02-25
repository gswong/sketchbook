#!/usr/bin/python
# Usage: ./listener.py

import serial
import sys

ser = serial.Serial('/dev/ttyACM0',9600)
while True:
  line = ser.readline()
  print line;
