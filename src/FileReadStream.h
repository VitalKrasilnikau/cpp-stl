#include <memory>

#include "FileSource.h"

class FileReadStream : public IReadStream {

public:

    FileReadStream(std::shared_ptr<FileSource> fileSource, int bufferSize) :
        IReadStream(fileSource->GetStream(), bufferSize),
        _fileSource(fileSource) { }

    ~FileReadStream() { }

private:
    std::shared_ptr<FileSource> _fileSource;
};