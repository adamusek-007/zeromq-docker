#include <zmq.hpp>
#include <iostream>

int main()
{
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);
    socket.connect("tcp://127.0.0.1:5555");

    zmq::message_t request(5);
    memcpy(request.data(), "Hello", 5);
    socket.send(request);

    zmq::message_t reply;
    socket.recv(&reply);

    std::cout << "Received reply: " << static_cast<char *>(reply.data()) << std::endl;

    return 0;
}
