import serial
import time
port = "/dev/ttyACM0"

baud_rate = 9600


ser = serial.Serial(port, baud_rate, timeout=5)

time.sleep(3) # wait for Arduino

ser.write('F')
ser.write('B')
ser.write('L')
ser.write('R')

time.sleep(5)


