#include <iostream>
#include <stdexcept>
#include <vector>

#include "IReadStream.h"

void IReadStream::PipeTo(std::ostream& output) {
    if (_source) {
        std::vector<char> buffer(_buffer);
        while (true) {
            std::fill(buffer.begin(), buffer.end(), '\0');
            _source.read(&buffer[0], _buffer);
            if (_source.good()) {
                output.write(&buffer[0], _buffer);
            }
            else {
                for (auto elem : buffer) {
                    if (elem) {
                        output << elem;
                    }
                }
                if (_source.eof()) {
                    break;
                }
                else {
                    throw std::runtime_error("file read failure") ;
                }
            }
        }
    }
}