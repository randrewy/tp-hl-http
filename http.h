#ifndef HTTP_H
#define HTTP_H
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <cstring>
#include <string>
#include <sys/stat.h>
#include <fcntl.h>
#include <map>

enum Status {
    OK = 200,
    FORBIDDEN = 403,
    NOT_FOUND = 404,
    BAD_REQUEST = 405,
};


enum RequestMethod{
    GET,
    HEAD,
    UNSUPPORTED,
};


enum ContentType
{
    HTML = 0, CSS, JS,  JPG,
    JPEG,     PNG, GIF, SWF,
    OTHER,
};

struct RequestInfo{
    RequestMethod method;
    std::string path;

    RequestInfo(const RequestMethod& m, const std::string& p) : method(m), path(p) {}
    const static RequestInfo BAD_REQUEST;
};

constexpr const char* SERVER = "TP-HL-SERVER";
constexpr const char* CONNECTION = "close";
constexpr const char* DOCUMENT_ROOT = "/home/andrey/projects/tp/srvroot";

void createResponse(bufferevent*);

#endif // HTTP_H
