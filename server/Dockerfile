# Use an official C++ runtime as a parent image
FROM gcc:latest

# Set the working directory
WORKDIR /app

# Install ZeroMQ development package
RUN apt-get update && apt-get install -y libzmq3-dev

# Copy the current directory contents into the container
COPY ../server.cpp /app/

# Compile the source code
RUN g++ -o server server.cpp -lzmq

# Run the executable
CMD ["./server"]
