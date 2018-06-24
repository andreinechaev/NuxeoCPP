//
// Created by Andrei Nechaev on 6/14/18.
//

#pragma once

#include <ostream>
#include "Authentication.h"
#include "../common/Utils.h"
#include "../common/Constants.h"

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

    struct Properties {

    };

    class Nuxeo {
    public:
        class Builder;

        virtual ~Nuxeo() = default;

        void request() {

        }

        bool operator==(const Nuxeo &rhs) const {
            return _host == rhs._host &&
                   _auth == rhs._auth &&
                   _headers == rhs._headers;
        }

        bool operator!=(const Nuxeo &rhs) const {
            return !(rhs == *this);
        }

        friend std::ostream &operator<<(std::ostream &os, const Nuxeo &nuxeo) {
            os << "_host: " << nuxeo._host << " _auth: " << nuxeo._auth << " headers_t: " << map_to_string(nuxeo._headers);
            return os;
        }

    private:
        Nuxeo(std::string &host, headers_t& head, nx::Authentication &auth) : _host(host), _auth(auth), _headers(head) {}

        std::string _host;
        nx::Authentication _auth;
        headers_t _headers;
    };

    class Nuxeo::Builder {

    private:
        static const constexpr AuthType _default_auth_type = Basic;

        static const constexpr char *_default_user = "Administrator";

        static const constexpr char *_default_pass = "Administrator";

        static const constexpr char *_default_host = "http://localhost:8080/nuxeo";

        headers_t _headers;

        AuthType _auth_type;

        std::string _user;

        std::string _pass;

        std::string _host;

    public:
        Builder();

        virtual ~Builder() {};

        Builder &set_headers(const headers_t &h) {
            this->_headers = h;
            return *this;
        }

        Builder &set_nuxeo_headers(const headers_t &h) {
            this->_headers.insert(h.begin(), h.end());
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

        Builder &set_host(const std::string &host) {
            this->_host = host;
            return *this;
        }

        Nuxeo build() {
            Authentication auth(this->_auth_type, this->_user, this->_pass);
            return Nuxeo(this->_host, this->_headers, auth);
        }
    };
}

