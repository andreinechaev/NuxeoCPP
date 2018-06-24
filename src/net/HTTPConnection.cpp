//
// Created by Andrei Nechaev on 6/24/18.
//

#include <sstream>
#include "HTTPConnection.h"

std::string
nx::net::HTTPConnection::request(const nx::net::METHOD method, const std::string &path, const Net::HTTPCredentials &auth,
                            const headers_t &headers, Net::HTTPResponse &response, const std::string &http_proto,
                            bool await) {

    std::string method_str;
    switch (method) {
        case GET:
            method_str = Net::HTTPRequest::HTTP_GET;
            break;
        case POST:
            method_str = Net::HTTPRequest::HTTP_POST;
            break;
        default:
            std::cerr << "Request with method " << method << " is not implemented";
            return "";
    }

    Net::HTTPRequest request{method_str, path, http_proto};
    for (auto header : headers) {
        request.set(header.first, header.second);
    }

    _session.sendRequest(request);

    std::stringstream ss;
    if (await) {
        auto &rs = _session.receiveResponse(response);

        Poco::StreamCopier::copyStream(rs, ss);
    }

    return ss.str();
}
