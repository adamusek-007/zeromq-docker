#include <zmq.hpp>
#include <string>
#include <iostream>
#include <chrono> // Include chrono for time-related functions
#include <thread> // Include thread for sleep_for function

int main(int argc,     // Number of strings in array argv
         char *argv[], // Array of command-line argument strings
         char *envp[]) // Array of environment variable strings
{
    zmq::context_t context(1);
    zmq::socket_t requester(context, ZMQ_REQ);
    std::string address = "tcp://" + std::string(argv[1]);
    requester.connect(address);

    for (int request_nbr = 0; request_nbr < 10; request_nbr++)
    {
        zmq::message_t request(5);
        memcpy(request.data(), "Hello", 5);
        std::cout << "Sending request " << request_nbr << "...\n";
        requester.send(request, zmq::send_flags::none); // Use send_flags::none instead of direct integer value

        zmq::message_t reply;
        requester.recv(&reply);
        std::cout << "Received reply " << request_nbr << ": " << std::string(static_cast<char *>(reply.data()), reply.size()) << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}