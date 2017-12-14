#include <cxxtest/TestSuite.h>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include "../src/ReadStreamFactory.h"

class Test : public CxxTest::TestSuite {

public:

    void testCreateFileReaderShouldReadFile(void) {
        auto fs = ReadStreamFactory::Instance()->CreateFileReader("testfile.txt", 5);
        std::stringstream output;
        fs->PipeTo(output);
        TS_ASSERT_EQUALS(output.str(), "hello123\\0");
    }

    void testCreateSocketReaderShouldReadHtmlIfSuccess(void) {
        auto fs = ReadStreamFactory::Instance()->CreateSocketReader("www.boost.org", "http", 1000);
        std::stringstream output;
        fs->PipeTo(output);
        TS_ASSERT(output.str().find("html") != std::string::npos);
    }

    void testCreateSocketReaderShouldThrowIfError(void) {
        TS_ASSERT_THROWS([](){
            auto fs = ReadStreamFactory::Instance()->CreateSocketReader("www.boost2.org", "http", 1000);
            std::stringstream output;
            fs->PipeTo(output);
        }(), std::runtime_error);
    }
};