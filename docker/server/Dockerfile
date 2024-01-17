FROM gcc:latest

WORKDIR /app

RUN apt-get update && apt-get install -y libzmq3-dev

COPY ../../server.cpp /app/

RUN g++ -o server server.cpp -lzmq

CMD ["./server"]

EXPOSE 5555