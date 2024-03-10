import zmq
import time

context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind("tcp://*:5555")

while True:
    request = socket.recv()
    print("Received request:", request.decode())

    time.sleep(1)

    socket.send(b"World")
