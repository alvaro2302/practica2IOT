import socket
import threading

def on_new_client(clientsocket,addr):
    while True : 
        print("ingrese la opcion ")
        print("1 prender led azul")
        print("2 prender led rojo")
        respuesta = input()
        if(respuesta != " "):
            conn.send(respuesta.encode())
        if(str(respuesta) =="0"):
            print("entro aqui")
            break
        data  = conn.recv(1024)
        print("esto es el data")
        print("data", data)
        # if not data:
        #     break
            
        #conn.sendall(data)
    clientsocket.close()

HOST = '0.0.0.0'
PORT = 10000
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST,PORT))
s.listen()

while True:
    conn, addr = s.accept()
    #with conn:
    threading._start_new_thread(on_new_client,(conn,addr))
print("se termino la conexion ")
conn.close()