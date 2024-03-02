export CROSS_COMPILE=$CC

export ZEROMQ_DIR=/path/to/zeromq

# Compile your program
$CC -o your_program your_program.c -I$ZEROMQ_DIR/include -L$ZEROMQ_DIR/lib -lzmq
