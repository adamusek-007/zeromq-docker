#include <zmq.hpp>
#include <string>
#include <iostream>
#include <chrono> // Include chrono for time-related functions
#include <thread> // Include thread for sleep_for function

int main()
{
    // Prepare the context and socket
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    socket.bind("tcp://*:5555");

    while (true)
    {
        zmq::message_t request;

        // Wait for next request from client
        socket.recv(&request);
        std::cout << "Received request: " << std::string(static_cast<char *>(request.data()), request.size()) << std::endl;

        // Do some "work"
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Send reply back to client
        zmq::message_t reply(5);
        memcpy(reply.data(), "World", 5);
        socket.send(reply, zmq::send_flags::none); // Use send_flags::none instead of direct integer value
    }
    return 0;
}
