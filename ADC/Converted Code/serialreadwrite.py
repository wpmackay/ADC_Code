
#open the serial port that the arduino is yelling on
import serial
import sys
ser = serial.Serial('/dev/ttyS0', 57600)

t = 0
output = [0] * 23

#print 'Starting Loop'
while t < 5400:
	
	#print ' Getting latest value'
	ser.write('1 \n')
	latestvalue = ser.readline()
	#Parse the csv string
	#print 'Parsing serial string'
	output = latestvalue.split(',')
	
	#print 'Displaying output'
	thetatrue = output[0]
	psitrue = output[1]
	phitrue = output[2]
	ratex = output[3]
	ratey = output[4]
	ratez = output[5]
	Bx = output[6]
	By = output[7]
	Bz = output[8]
	magx = output[9]
	magy = output[10]
	magz = output[11]
	gyrox = output[12]
	gyroy = output[13]
	gyroz = output[14]
	rrx = output[15]
	rry = output[16]
	rrz = output[17]
	qmeas1 = output[18]
	qmeas2 = output[19]
	qmeas3 = output[20]
	qmeas4 = output[21]
	trackerAvail = output[22]
	time = output[23]

	#standard output the output so it can be piped to the EKF
	print thetatrue
	print phitrue
	print psitrue
	print ratex
	print ratey
	print ratez
	print Bx
	print By
	print Bz
	print magx
	print magy
	print magz
	print gyrox
	print gyroy
	print gyroz
	print rrx
	print rry
	print rrz
	print qmeas1
	print qmeas2
	print qmeas3
	print qmeas4
	print trackerAvail
	print time

	t = float(time);
	sys.stdout.flush()
