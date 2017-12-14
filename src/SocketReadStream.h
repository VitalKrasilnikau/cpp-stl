#include <memory>

#include "SocketSource.h"

class SocketReadStream : public IReadStream {

public:

    SocketReadStream(std::shared_ptr<SocketSource> socketSource, int bufferSize) :
        IReadStream(socketSource->GetStream(), bufferSize),
        _socketSource(socketSource) { }

    ~SocketReadStream() { }

private:
    std::shared_ptr<SocketSource> _socketSource;
};