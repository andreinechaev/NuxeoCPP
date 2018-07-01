//
// Created by Andrei Nechaev on 6/14/18.
//

#pragma once

#include <string>

#define DEBUG false

typedef std::map<std::string, std::string> headers_t;

typedef std::map<std::string, std::string> params_t;

namespace nx {
    static const constexpr char* DEFAULT_API_PATH = "/nuxeo/api/v1/";

    static const constexpr char* DEFAULT_APP_NAME = "C++ Client";

    static const constexpr char* DEFAULT_URL = "localhost";

    static const constexpr uint16_t DEFAULT_PORT = 8080;

    static const constexpr int CHUNK_UPLOAD_LIMIT = 10 * 1024 * 1024; // 10 MB

    static const constexpr int DEFAULT_CHUNK_SIZE = 256 * 1024; // 256kB

    static const constexpr bool CHECK_PARAMETERS = false;

    static const constexpr char* QUERY_API_NAME = "query";

    static const constexpr char* NXQL_SEARCH_API_PATH = "search/lang/NXQL/execute";
}
