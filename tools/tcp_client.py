#!/usr/bin/env python 
# simple blocking TCP client
# based on Python 3.9.5

import socket

AR_SERVER = ( '127.0.0.1', 8000 )
BUFFER_SIZE = 1024

try:
    sk = socket.create_connection( address = AR_SERVER, timeout = 2.0 )
except( ConnectionRefusedError ):
    print( 'server not available' )
else:
    print( f'connected to {AR_SERVER}' )
    data = bytes()
    while True:
        try:
            data += sk.recv(BUFFER_SIZE)

            if len(data) == 0: #
                print('connection was terminated by server')
                break
            while True:  # process received data
                index = data.find(b'\n') 
                if index >= 0:               
                    line = data[:index].decode('ascii')
                    data = data[index+1:]
                    print(line)
                else:
                    break
                             
        except(socket.timeout):
            print( 'your choice: ', end = '')
            key = input() # ask user
            if key in '123':
                sk.send(key.encode('ascii'))
        except(ConnectionResetError):
            print('connection was aborted')
            break
finally:
    sk.close()


        
    
