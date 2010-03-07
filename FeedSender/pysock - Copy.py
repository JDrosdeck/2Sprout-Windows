import socket, sys, struct, time, md5
from itertools import izip, cycle
import base64, random



def XOR(value,key):
	return ''.join(chr(ord(x) ^ ord(y)) for (x,y) in izip(value, cycle(key)))

def checksum(st):
    return reduce(lambda x,y:x+y, map(ord, st))
	
hostname = '127.0.0.1'
port = 4950
host = socket.gethostbyname(hostname)
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)	



for x in xrange(11,20):
	tempMessage = "^120511^"+ str(x) + "^0^TESTdddkjESTES'125.99</price><spdroutcast><url>www.amazon.com/prod1d=43453</url><title>gold watch</title></sproutcast><price>125.99</price>kjg;" + str(x)
	total = checksum(tempMessage)
	msg1 = str(total) + tempMessage
	print msg1
	msg = "ePsYDJbtxC" + msg1     #This is the SECRET KEY
	msg = XOR(msg,'aACZfGGL8R')   # THIS IS THE CIPHER
	msg = base64.b64encode(msg)
	#g = random.uniform(.002)
	#print g
	s.sendto(msg,(host,port))
	del msg1
	del msg
	del tempMessage
	time.sleep(.1)



