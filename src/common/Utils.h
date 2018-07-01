//
// Created by Andrei Nechaev on 6/24/18.
//

#pragma once

#include <string>
#include <sstream>
#include <map>

template <typename K, typename V>
static std::string map_to_string(std::map<K, V> m) {
    std::ostringstream oss;
    oss << "{\n";
    for (auto pair : m) {
        oss << "\t" + pair.first + ": " + pair.second + ",\n";
    }
    oss << "}";
    return oss.str();
};
