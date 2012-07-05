#!/usr/bin/env python
#-*- coding: utf-8 -*-

# Author: youngtrips(youngtrips@gmail.com)
# Created Time:  2012-07-04
# File Name: servo.py
# Description: 
#

import serial
import struct
import sys
import time

SERIAL_PORT = "/dev/ttyUSB0"

def main(op_dir, op_val):
    ser = serial.Serial(SERIAL_PORT, 9600)
    val = (op_dir << 16) | op_val
    msg = struct.pack('BB', op_dir, op_val)
    ret = ser.write(msg)
    ser.close()

def usage():
    print 'Usage: %s DIRECTION OFFSET' % (sys.argv[0])
    print 'DIRECTION: 1=Counterclockwise, 2=Clockwise'
    print 'OFFSET: Rotate degree(0~180), ignore offset exceed limit.'

if __name__ == "__main__":
    if len(sys.argv) != 3:
        usage()
        sys.exit(0)
    op_dir = int(sys.argv[1])
    op_val = int(sys.argv[2])
    main(op_dir, op_val)

