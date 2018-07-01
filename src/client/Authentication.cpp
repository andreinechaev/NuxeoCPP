//
// Created by Andrei Nechaev on 6/14/18.
//

#include "Authentication.h"


nx::Authentication::Authentication(nx::AuthType type, const std::string &username, const std::string &auth): _auth(username, auth) {
}


Net::HTTPBasicCredentials& nx::Authentication::get_auth() {
    return _auth;
}

nx::Authentication::~Authentication() = default;
