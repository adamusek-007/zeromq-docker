docker build -t cpp_server -f Dockerfile.server .
docker build -t cpp_client -f Dockerfile.client .
docker run --name server cpp_server
docker run --name client --link server:server --rm cpp_client

@REM docker compose server exec g++ -o server server.cpp -lzmq \ ./server
@REM docker compose client exec g++ -o client client.cpp -lzmq \ ./client
