//
// Created by Andrei Nechaev on 6/24/18.
//

#include "Document.h"

inline nx::net::METHOD nx::api::Document::Query::get_method() const {
    return nx::net::METHOD::GET;
}


std::map<std::string, std::string> nx::api::Document::Query::get_parameters() const {
    return _params;
}
