sudo docker build --tag cpp_server --file Dockerfile.server .
sudo docker build --tag cpp_client --file Dockerfile.client .
sudo docker run --name server cpp_server
sudo docker run --name client --link server:server --rm cpp_client

@REM docker compose server exec g++ -o server server.cpp -lzmq \ ./server
@REM docker compose client exec g++ -o client client.cpp -lzmq \ ./client
