#include <zmq.h>
#include <stdio.h>
#include <string.h>

int main()
{
    void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_REQ);
    zmq_connect(socket, "tcp://server:5555");

    const char *request_data = "Hello client there!";
    zmq_msg_t request;
    zmq_msg_init_size(&request, strlen(request_data));
    memcpy(zmq_msg_data(&request), request_data, strlen(request_data));
    zmq_msg_send(&request, socket, 0);
    zmq_msg_close(&request);

    zmq_msg_t reply;
    zmq_msg_init(&reply);
    zmq_msg_recv(&reply, socket, 0);

    printf("Received reply: %s\n", (char *)zmq_msg_data(&reply));

    zmq_msg_close(&reply);

    zmq_close(socket);
    zmq_ctx_destroy(context);

    return 0;
}
