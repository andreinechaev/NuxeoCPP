//
// Created by Andrei Nechaev on 6/24/18.
//

#pragma once

#include <utility>
#include "NuxeoAPI.h"
#include "../net/HTTPConnection.h"

namespace nx {
    namespace api {

        class Document {

        public:
            Document() = default;

            ~Document() = default;

            class Query;

            class PageProvider;
        };

        class Document::Query : public API {

        public:
            explicit Query(std::string query): API(), _query(std::move(query)), _params{} {
                _params[QUERY_API_NAME] = _query;
            }

            ~Query() override = default;

            net::METHOD get_method() const override;

            std::map<std::string, std::string> get_parameters() const override;

            inline std::string get_path() const override {
                return NXQL_SEARCH_API_PATH;
            }

            void set_parameters(params_t &params) {
                _params.insert(params.begin(), params.end());
            }

        protected:
            std::string _query;

            params_t _params;
        };

        class Document::PageProvider: public Query {
        public:
            explicit PageProvider(std::string ppName): Query(std::move(ppName)), _path("search/pp/" + _query + "/execute") {
                _params.clear();
            }

            ~PageProvider() override = default;

            inline std::string get_path() const override {
                return _path;
            }

        private:
            std::string _path;
        };

    }
}
