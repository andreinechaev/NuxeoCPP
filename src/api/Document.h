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
            Document() : _id(), _name(), _type(), _state(),
                         _path(), _lock_owner(), _version_label(),
                         _is_checked_out(), _last_modified(), _properties() {};

            ~Document() = default;

            class Query;

            class PageProvider;

            const std::string &get_id() const;

            const std::string &get_name() const;

            const std::string &get_type() const;

            const std::string &get_state() const;

            const std::string &get_path() const;

            const std::string &get_lock_owner() const;

            const std::string &get_version_label() const;

            const std::string &get_is_checked_out() const;

            const std::string &get_last_modified() const;

            const std::map<std::string, std::string> &get_properties() const;

        private:
            std::string _id;

            std::string _name;

            std::string _type;

            std::string _path;

            std::string _state;

            std::string _lock_owner;

            std::string _version_label;

            std::string _is_checked_out;

            std::string _last_modified;

            std::map<std::string, std::string> _properties;

        };

        class Document::Query : public API {

        public:
            explicit Query(std::string query) : API(), _query(std::move(query)), _params{} {
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

        class Document::PageProvider : public Query {
        public:
            explicit PageProvider(std::string ppName) : Query(std::move(ppName)),
                                                        _path("search/pp/" + _query + "/execute") {
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
