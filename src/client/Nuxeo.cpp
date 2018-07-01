//
// Created by Andrei Nechaev on 6/14/18.
//

#include "Nuxeo.h"


nx::Nuxeo::Builder::Builder() : _headers(Headers::get()),
                                _auth_type(_default_auth_type), _user(_default_user),
                                _pass(_default_pass), _host(DEFAULT_URL), _port(DEFAULT_PORT) {

    auto extra = Headers::extra();
    _headers.insert(extra.begin(), extra.end());
}

