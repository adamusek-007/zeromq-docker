export CROSS_COMPILE=$CXX

export ZEROMQ_DIR=./compiled

# Compile your program
$CROSS_COMPILE -o server server.cpp -I$ZEROMQ_DIR/include -L$ZEROMQ_DIR/lib -lzmq
