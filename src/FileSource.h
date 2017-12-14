#include <fstream>

class FileSource {

public:

    FileSource(char const* fileName) : _source(fileName, std::ifstream::binary) {
        
    }

    FileSource(std::string const& fileName) : FileSource(fileName.c_str()) {

    }

    ~FileSource() {
        
    }

    std::ifstream& GetStream() {
        return _source;
    }

private:
    std::ifstream _source;
};