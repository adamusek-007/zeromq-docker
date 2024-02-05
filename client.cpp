#include <zmq.h>
#include <iostream>

int main()
{
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);
    socket.connect("tcp://server:5555");

    zmq::message_t request(255);
    memcpy(request.data(), "Hello client there!", 255);
    socket.send(request);

    zmq::message_t reply;
    socket.recv(&reply);

    std::cout << "Received reply: " << static_cast<char *>(reply.data()) << std::endl;

    return 0;
}
