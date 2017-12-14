#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class SocketSource {

public:

    SocketSource(char const* domain, char const* port) : _source(domain, port) {
        _source << "GET " << "/" << " HTTP/1.0\r\n";
        _source << "Host: " << domain << "\r\n";
        _source << "Accept: */*\r\n";
        _source << "Connection: close\r\n\r\n";
    }

    SocketSource(std::string const& domain, std::string const& port) :
        SocketSource(domain.c_str(), port.c_str()) {

    }

    ~SocketSource() {
        
    }

    tcp::iostream& GetStream() {
        return _source;
    }

private:
    tcp::iostream _source;
};