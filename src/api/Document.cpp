//
// Created by Andrei Nechaev on 6/24/18.
//

#include "Document.h"

const std::string &nx::api::Document::get_id() const {
    return _id;
}

const std::string &nx::api::Document::get_name() const {
    return _name;
}

const std::string &nx::api::Document::get_type() const {
    return _type;
}

const std::string &nx::api::Document::get_state() const {
    return _state;
}

const std::string &nx::api::Document::get_path() const {
    return _path;
}

const std::string &nx::api::Document::get_lock_owner() const {
    return _lock_owner;
}

const std::string &nx::api::Document::get_version_label() const {
    return _version_label;
}

const std::string &nx::api::Document::get_is_checked_out() const {
    return _is_checked_out;
}

const std::string &nx::api::Document::get_last_modified() const {
    return _last_modified;
}

const std::map<std::string, std::string> &nx::api::Document::get_properties() const {
    return _properties;
}

inline nx::net::METHOD nx::api::Document::Query::get_method() const {
    return nx::net::METHOD::GET;
}


std::map<std::string, std::string> nx::api::Document::Query::get_parameters() const {
    return _params;
}
