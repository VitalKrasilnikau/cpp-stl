# This is an example project using C++ smart pointers (shared_ptr), STL streams and Boost sockets.

## Build

`build.sh` is used to build with GCC and run the application. Make sure you have added all required includes.

For example:

1. `/usr/lib/gcc/x86_64-redhat-linux/6.2.1/include`
1. `/usr/include/boost`

Boost Asio is required only for **SocketReadStream** example. **FileReadStream** uses STL. **IReadStream::PipeTo** reads all the streams in the similar way.

To install Boost run `sudo dnf install boost-devel`.

## Test

`test.sh` is used to build with GCC and test the application with **CxxTest**.