#!/usr/bin/env python
from serial import Serial
from datetime import datetime as dt

for line in Serial("/dev/ttyUSB0"):
    print line.strip()
    newtime = dt.now()
    print newtime - oldtime, "\n"
    oldtime=newtime
