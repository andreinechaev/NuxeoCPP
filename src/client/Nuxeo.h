//
// Created by Andrei Nechaev on 6/14/18.
//

#pragma once

#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <string>
#include "Authentication.h"
#include "../common/Utils.h"
#include "../common/Constants.h"
#include "../net/HTTPConnection.h"
#include "../api/NuxeoAPI.h"

namespace nx {

    struct Headers {
        static headers_t get() {
            headers_t h{};
            h["X-Application-Name"] = "C++ Client";
            h["X-Client-Version"] = "0.0.1-SNAPSHOT";
            h["User-Agent"] = "C++ Client/0.0.1-SNAPSHOT";
            h["Accept"] = "application/json+nxentity, */*";

            return h;
        }

        static headers_t extra() {
            headers_t extra{};
            extra["X-NXDocumentProperties"] = "*";
            extra["X-NXRepository"] = "default";

            return extra;
        }
    };

    class Nuxeo {
    public:
        class Builder;

        virtual ~Nuxeo() = default;

        void request(api::API &func) {
            auto method = func.get_method();
            auto path = func.get_path();
            auto params = func.get_parameters();

            net::HTTPConnection connection(_host, _port);

            Net::HTTPResponse resp;
            auto endpoint = _api_path + path;
            auto resp_str = connection.request(method, endpoint, _auth.get_auth(), _headers, resp, params);
//            if (DEBUG) {
                std::cout << "Response: " << resp_str << std::endl;
//            }
        }

        bool operator==(const Nuxeo &rhs) const {
            return _host == rhs._host &&
                   _headers == rhs._headers;
        }

        bool operator!=(const Nuxeo &rhs) const {
            return !(rhs == *this);
        }

        friend std::ostream &operator<<(std::ostream &os, const Nuxeo &nuxeo) {
            os << "_host: " << nuxeo._host << " headers_t: " << map_to_string(nuxeo._headers);
            return os;
        }

    private:
        Nuxeo(std::string &host, uint16_t port, headers_t& head, nx::Authentication &auth) : _host(host), _port(port), _auth(auth), _headers(head), _api_path(DEFAULT_API_PATH) {}

        std::string _host;
        uint16_t _port;
        nx::Authentication _auth;
        headers_t _headers;
        std::string _api_path;
    };

    class Nuxeo::Builder {

    private:
        static const constexpr AuthType _default_auth_type = Basic;

        static const constexpr char *_default_user = "Administrator";

        static const constexpr char *_default_pass = "Administrator";

        headers_t _headers;

        AuthType _auth_type;

        std::string _user;

        std::string _pass;

        std::string _host;

        uint16_t _port;

    public:
        Builder();

        virtual ~Builder() = default;;

        Builder &set_host(const std::string &host) {
            this->_host = host;
            return *this;
        }

        Builder &set_port(const uint16_t port) {
            this->_port = port;
            return *this;
        }

        Builder &set_headers(const headers_t &h) {
            if (h.empty()) {
                this->_headers = h;
            } else {
                this->_headers.insert(h.begin(), h.end());
            }

            return *this;
        }

        Builder &set_nuxeo_headers(const headers_t &h) {
            this->_headers.insert(h.begin(), h.end());
            return *this;
        }

        Builder &set_enrichers(const std::vector<std::string> &enrichers) {
            const char *delim = ", ";

            std::ostringstream ss;
            std::copy(enrichers.begin(), enrichers.end(), std::ostream_iterator<std::string>(ss, delim));

            return *this;
        }

        Builder &set_client_version(const std::string &version) {
            this->_headers["X-Application-Name"] = version;
            return *this;
        }

        Builder &set_application_name(const std::string &name) {
            _headers["X-Application-Name"] = "C++ Client";
            return *this;
        }

        Builder &set_auth_type(const AuthType auth) {
            this->_auth_type = auth;
            return *this;
        }

        Builder &set_username(const std::string &user) {
            this->_user = user;
            return *this;
        }

        Builder &set_password(const std::string &pass) {
            this->_pass = pass;
            return *this;
        }

        Nuxeo build() {
            Authentication auth(this->_auth_type, this->_user, this->_pass);
            return Nuxeo(this->_host, this->_port, this->_headers, auth);
        }
    };
}

