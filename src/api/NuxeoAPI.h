//
// Created by Andrei Nechaev on 6/24/18.
//

#pragma once

#include "../net/HTTPConnection.h"

namespace nx {
    namespace api {

        class API {

        public:
            virtual ~API() = default;

            virtual net::METHOD get_method() const = 0;

            virtual std::string get_path() const = 0;

            virtual std::map<std::string, std::string> get_parameters() const = 0;

            API() = default;
        };
    }
}
