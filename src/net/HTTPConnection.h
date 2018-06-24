//
// Created by Andrei Nechaev on 6/24/18.
//

#pragma once

#include <iostream>
#include <Poco/Net/HTTPCredentials.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>

#include "../common/Constants.h"

using namespace Poco;

namespace nx {

    namespace net {

        enum METHOD {
            GET,
            HEAD,
            POST,
            PUT,
            DELETE,
            CONNECT,
            OPTIONS,
            TRACE
        };

        class HTTPConnection {

        private:
            Net::HTTPClientSession _session;

        public:
            explicit HTTPConnection(const std::string &host) : _session(host) {}

            virtual ~HTTPConnection() = default;

            std::string
            request(METHOD method, const std::string &path, const Net::HTTPCredentials &auth, const headers_t &headers,
                    Net::HTTPResponse &response, const std::string &http_proto = Net::HTTPMessage::HTTP_1_1,
                    bool await = true);
        };

    }
}
