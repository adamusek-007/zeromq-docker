#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    void *context = zmq_ctx_new();
    void *requester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(requester, "tcp://192.168.100.5:5555");

    int request_nbr;
    for (request_nbr = 0; request_nbr < 10; request_nbr++)
    {
        zmq_msg_t request;
        zmq_msg_init_size(&request, 5);
        memcpy(zmq_msg_data(&request), "Hello", 5);
        printf("Sending request %d...\n", request_nbr);
        zmq_msg_send(&request, requester, 0);
        zmq_msg_close(&request);

        zmq_msg_t reply;
        zmq_msg_init(&reply);
        zmq_msg_recv(&reply, requester, 0);
        printf("Received reply %d: %s\n", request_nbr, (char *)zmq_msg_data(&reply));
        zmq_msg_close(&reply);
        sleep(1);
    }
    zmq_close(requester);
    zmq_ctx_destroy(context);
    return 0;
}
