#!/usr/bin/python
# Usage: ./listener.py

import serial
import sys
import time

ser = serial.Serial('/dev/ttyACM0',9600)
while True:
  time.sleep(10000)
