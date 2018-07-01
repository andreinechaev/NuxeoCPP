//
// Created by Andrei Nechaev on 6/24/18.
//

#include <sstream>
#include "HTTPConnection.h"
#include <iostream>
#include <Poco/Net/HTTPBasicCredentials.h>

std::string
nx::net::HTTPConnection::request(const nx::net::METHOD method, const std::string &endpoint,
                                 Net::HTTPBasicCredentials &auth,
                                 const headers_t &headers, Net::HTTPResponse &response,
                                 const std::map<std::string, std::string> &params, bool await) {

    std::string method_str;
    get_method(method, method_str);

    Poco::URI uri{endpoint};
    if (!params.empty()) {
        for (auto pair : params) {
            uri.addQueryParameter(pair.first, pair.second);
        }
    }

    Net::HTTPRequest request{method_str, uri.getPathEtc(), _protocol};

    for (auto header : headers) {
        request.add(header.first, header.second);
    }
    auth.authenticate(request);
    auto &bos = _session.sendRequest(request);

    std::cout << request.getURI() << std::endl;
    std::ostringstream oss;
    oss << bos.rdbuf();
    std::cout << oss.str() << std::endl;

    std::stringstream ss;
    if (await) {

        auto &rs = _session.receiveResponse(response);

        if (response.getStatus() == Poco::Net::HTTPResponse::HTTP_UNAUTHORIZED) {
            std::cerr << "Unauthorized: Status(" << response.getStatus() << ")\n";
        }

        Poco::StreamCopier::copyStream(rs, ss);
    }

    return ss.str();
}
