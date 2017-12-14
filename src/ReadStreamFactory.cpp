#include <memory>

#include "ReadStreamFactory.h"
#include "FileReadStream.h"
#include "SocketReadStream.h"

std::shared_ptr<IReadStream>
ReadStreamFactory::CreateFileReader(std::string const& fileName, int bufferSize) {
    auto source = std::shared_ptr<FileSource>(new FileSource(fileName));
    return std::shared_ptr<IReadStream>(new FileReadStream(source, bufferSize));
};

std::shared_ptr<IReadStream>
ReadStreamFactory::CreateSocketReader(std::string const& domain, std::string const& port, int bufferSize) {
    auto source = std::shared_ptr<SocketSource>(new SocketSource(domain, port));
    return std::shared_ptr<IReadStream>(new SocketReadStream(source, bufferSize));
}

ReadStreamFactory* ReadStreamFactory::Instance() {
    static ReadStreamFactory factory;
    return &factory;
}