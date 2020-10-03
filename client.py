import socket

HOST = '127.0.0.1'
PORT = 8090

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM) 
s.connect((HOST,PORT))
message="off"
while True:
   
    s.sendall(b'Hello world')
    data = s.recv(1024)
    message=repr(data)
    print('Received',repr(data))