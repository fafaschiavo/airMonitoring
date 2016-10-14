import serial
import csv

print 'Hi there!'

ser = serial.Serial('/dev/ttyUSB0', 9600)

line = ''
counter = 0
with open('data_air_motherfucker.csv', 'wb') as csvfile:
	while True:
		raw_data = ser.readline()
		# print raw_data.split('\n')[0]
		if len(raw_data.split('\n')[0]) < 5:
			processed_data = raw_data.split('\n')
			final_data = processed_data[0].split('\r')[0]
			line = line + final_data + ';'
			counter = counter + 1
		else:
			if counter == 3:
				spamwriter = csv.writer(csvfile, delimiter=';')
				data = []
				data.append(line)
				spamwriter.writerows([data])
			print line
			line = ''
			counter = 0

#to install serial library
#pip install pyserial

#to find all the oserial devices connected
#ls /dev/tty*

#Simple tutorial here:
#http://playground.arduino.cc/Interfacing/Python