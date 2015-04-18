
#open the serial port that the arduino is yelling on
import sys

log = open('logfile.csv','w')

#print 'Starting Loop'
while True:
	#obtain several values, only trust the last one
	
	#print ' Getting latest value'
	latestvalue = raw_input()
	#Parse the csv string
	#print 'Parsing serial string'
	
	#Write the received data to a CSV file
	log.write(latestvalue + '\n')

	sys.stdout.flush()
