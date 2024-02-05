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
        zmq::recv_result_t result = socket.recv(request, zmq::recv_flags::none);

        if (!result.has_value())
        {
            std::cerr << "Error receiving message" << std::endl;
            continue; // Handle the error as needed
        }

        std::cout << "Received request: " << static_cast<char *>(request.data()) << std::endl;

        zmq::message_t reply(15);
        memcpy(reply.data(), "Hello, client!", 15);
        socket.send(reply, zmq::send_flags::none);
    }

    return 0;
}
