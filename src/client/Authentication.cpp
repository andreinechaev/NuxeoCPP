//
// Created by Andrei Nechaev on 6/14/18.
//

#include "Authentication.h"


nx::Authentication::Authentication(nx::AuthType type, const std::string &username, const std::string &auth): _auth(username, auth) {
}

bool nx::Authentication::operator==(const nx::Authentication &rhs) const {
    return _auth.getUsername() == rhs.get_auth().getUsername();
}

bool nx::Authentication::operator!=(const nx::Authentication &rhs) const {
    return !(rhs == *this);
}

const Net::HTTPCredentials& nx::Authentication::get_auth() const {
    return _auth;
}

nx::Authentication::~Authentication() = default;
