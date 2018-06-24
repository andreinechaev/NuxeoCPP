//
// Created by Andrei Nechaev on 6/24/18.
//

#pragma once

#include <string>
#include <map>

template <typename K, typename V>
static std::string map_to_string(std::map<K, V> m) {
    std::string out{"{\n"};

    for (auto pair : m) {
        out += "\t" + pair.first + ": " + pair.second + "\n";
    }

    out += "}";
    return out;
};
