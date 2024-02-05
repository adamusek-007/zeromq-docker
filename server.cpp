#include <zmq.hpp>
#include <iostream>
#include <string>

int main()
{
    try
    {
        zmq::context_t context(1);
        zmq::socket_t socket(context, ZMQ_REQ);
        socket.connect("tcp://192.168.100.5:5555");

        const std::string request_data = "Hello client there!";
        zmq::message_t request(request_data.size());
        memcpy(request.data(), request_data.c_str(), request_data.size());
        socket.send(request, zmq::send_flags::none);

        zmq::message_t reply;
        if (socket.recv(reply, zmq::recv_flags::none))
        {
            std::cout << "Received reply: " << std::string(static_cast<char *>(reply.data()), reply.size()) << std::endl;
        }
        else
        {
            std::cerr << "Error receiving reply." << std::endl;
        }
    }
    catch (const zmq::error_t &e)
    {
        std::cerr << "ZMQ Error: " << e.what() << std::endl;
    }

    return 0;
}
