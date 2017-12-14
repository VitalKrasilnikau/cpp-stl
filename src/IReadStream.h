#include <iostream>
#include <stdexcept>

class IReadStream {

protected:

    IReadStream(std::istream& source, int bufferSize) : _source(source), _buffer(bufferSize) {
        if (!_source) {
            throw std::runtime_error("file open failure");
        }
    }

public:

    ~IReadStream() {

    }

    void PipeTo(std::ostream& output);

private:
    std::istream& _source;
    int _buffer;
};