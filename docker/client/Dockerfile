FROM gcc:latest

WORKDIR /app

RUN apt-get update && apt-get install -y libzmq3-dev

COPY ../../client.cpp /app/

RUN g++ -o client client.cpp -lzmq

CMD ["./client"]
