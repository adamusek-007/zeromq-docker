# Use an official C++ runtime as a parent image
FROM gcc:latest

# Set the working directory
WORKDIR /app

# Install ZeroMQ development package
RUN apt-get update && apt-get install -y libzmq3-dev

# Copy the current directory contents into the container
COPY ../client.cpp /app/

# Compile the source code
RUN g++ -o client client.cpp -lzmq

# Run the executable
CMD ["./client"]
