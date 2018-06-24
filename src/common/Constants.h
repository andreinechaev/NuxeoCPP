//
// Created by Andrei Nechaev on 6/14/18.
//

#pragma once

#include <string>

typedef std::map<std::string, std::string> headers_t;

namespace nx {
    static const constexpr char* DEFAULT_API_PATH = "api/v1";

    static const constexpr char* DEFAULT_APP_NAME = "C++ Client";

    static const constexpr char* DEFAULT_URL = "http://localhost:8080/nuxeo/";

    static const constexpr int CHUNK_UPLOAD_LIMIT = 10 * 1024 * 1024; // 10 MB

    static const constexpr int DEFAULT_CHUNK_SIZE = 256 * 1024; // 256kB

    static const constexpr bool CHECK_PARAMETERS = false;
}
