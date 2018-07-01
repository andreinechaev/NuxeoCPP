//
// Created by Andrei Nechaev on 6/24/18.
//

#pragma once

#include <iostream>
#include <utility>
#include <Poco/Net/HTTPCredentials.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/URI.h>
#include <Poco/StreamCopier.h>
#include <Poco/Net/HTTPBasicCredentials.h>
#include <map>

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
            std::string _protocol;

        public:
            explicit
            HTTPConnection(const std::string &host, const uint16_t port,
                           std::string protocol = Net::HTTPMessage::HTTP_1_1) : _session(host, port),
                                                                                _protocol(std::move(protocol)) {}

            virtual ~HTTPConnection() = default;

            std::string
            request(METHOD method, const std::string &endpoint, Net::HTTPBasicCredentials &auth,
                    const headers_t &headers,
                    Net::HTTPResponse &response,
                    const std::map<std::string, std::string> &params=std::map<std::string, std::string>(),
                    bool await = true
            );
        };

        inline void get_method(const METHOD method, std::string &result) {
            switch (method) {
                case GET:
                    result = Net::HTTPRequest::HTTP_GET;
                    break;
                case POST:
                    result = Net::HTTPRequest::HTTP_POST;
                    break;
                case PUT:
                    result = Net::HTTPRequest::HTTP_PUT;
                    break;
                case DELETE:
                    result = Net::HTTPRequest::HTTP_PUT;
                    break;
                case TRACE:
                    result = Net::HTTPRequest::HTTP_TRACE;
                    break;
                case OPTIONS:
                    result = Net::HTTPRequest::HTTP_OPTIONS;
                    break;
                case CONNECT:
                    result = Net::HTTPRequest::HTTP_CONNECT;
                    break;
                case HEAD:
                    result = Net::HTTPRequest::HTTP_HEAD;
                    break;
            }
        }

    }
}
