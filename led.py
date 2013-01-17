import serial	#For communication
import time	#To sleep between sends
import random	#Random numbers for lights

#Location of the arduino
port ='/dev/ttyACM0'

#Connect to the arduino, 9600 baud rate
try:
  arduino = serial.Serial(port,9600)
except:
  print "Failed to connect on ",port

#Wait for a response telling us it's ready
arduino.read()

while True:
  try:
    #Write a random number to board
    no = random.randrange(0,255)
    arduino.write(str(no))
  except:
    print "failed to send!"
  time.sleep(2)
