#include <zmq.hpp>
#include <iostream>

int main()
{
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    socket.bind("tcp://*:5555");

    while (true)
    {
        zmq::message_t request;
        socket.recv(&request);

        std::cout << "Received request: " << static_cast<char *>(request.data()) << std::endl;

        zmq::message_t reply(13);
        memcpy(reply.data(), "Hello, client!", 13);
        socket.send(reply);
    }

    return 0;
}
