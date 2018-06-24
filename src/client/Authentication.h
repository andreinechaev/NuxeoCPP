//
// Created by Andrei Nechaev on 6/14/18.
//

#pragma once

#include <string>
#include <ostream>
#include <Poco/Net/HTTPCredentials.h>

using namespace Poco;

namespace nx {
    enum AuthType {
        Basic,
        Digest
    };

    class Authentication {
    public:
        Authentication(AuthType type, const std::string &username, const std::string &auth);

        Authentication(const Authentication &auth): _auth(auth._auth.getUsername(), auth._auth.getPassword()) {}

        virtual ~Authentication();

        const Net::HTTPCredentials& get_auth() const;

        bool operator==(const Authentication &rhs) const;

        bool operator!=(const Authentication &rhs) const;

        friend std::ostream& operator<<(std::ostream &os, const Authentication &authentication) {
            os << authentication.get_auth().getUsername();
            return os;
        }

    private:
        Net::HTTPCredentials _auth;
    };
}
