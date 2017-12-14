#include <iostream>
#include <stdexcept>

#include "ReadStreamFactory.h"

int main() {
    auto fs = ReadStreamFactory::Instance()->CreateFileReader("testfile.txt", 5);
    fs->PipeTo(std::cout);

    std::cout << '\n';

    try { // not blocking, change to www.boost.org to see HTML
        auto fs2 = ReadStreamFactory::Instance()->CreateSocketReader("www.boost2.org", "http", 1000);
        fs2->PipeTo(std::cout);
    }
    catch (std::runtime_error e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    return 0;
}