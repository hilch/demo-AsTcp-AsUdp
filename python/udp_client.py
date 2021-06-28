#!/usr/bin/env python 
# simple blocking UDP client
# based on Python 3.9.5

import socket
import random

port_receiver = random.randint(5001,8000)
SEND_TO = ( '127.0.0.1', 5000 )
RECEIVE = ( '', port_receiver )
BUFFER_SIZE = 1024

print( 'use port:', port_receiver )
sk = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sk.bind(RECEIVE)                     

# send a hello message to server
sk.sendto( b'Hello AR !', SEND_TO )

# process received data and send data given by input
while True:
    data, addr = sk.recvfrom(BUFFER_SIZE)
    print( f'Received: \'{data.decode("ascii")}\' from host {addr}')
    print( 'input text: ', end = '' )
    text = input()
    sk.sendto(text.encode('ascii'), SEND_TO)
