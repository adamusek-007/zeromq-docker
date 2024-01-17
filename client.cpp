#include <zmq.hpp>
#include <iostream>

int main()
{
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);
    socket.connect("tcp://server:5555");

    // Send a request to the server
    zmq::message_t request(5);
    memcpy(request.data(), "Hello Server - Client there!", 5);
    socket.send(request);

    // Receive the reply from the server
    zmq::message_t reply;
    socket.recv(&reply);

    std::cout << "Received reply: " << static_cast<char *>(reply.data()) << std::endl;

    return 0;
}
