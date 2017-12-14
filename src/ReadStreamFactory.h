#include <memory>

#include "IReadStream.h"

class ReadStreamFactory {

public:
    ReadStreamFactory() { }
    ~ReadStreamFactory() { }

    std::shared_ptr<IReadStream> CreateFileReader(std::string const& fileName, int bufferSize);
    std::shared_ptr<IReadStream> CreateSocketReader(std::string const& domain, std::string const& port, int bufferSize);
    static ReadStreamFactory* Instance();
};