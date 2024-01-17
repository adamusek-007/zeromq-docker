docker build -t cpp_server -f Dockerfile.server .

docker build -t cpp_client -f Dockerfile.client .

docker run --name server cpp_server

docker run --name client --link server:server cpp_client
