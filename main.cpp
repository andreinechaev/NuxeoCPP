#include <iostream>
#include "src/client/Nuxeo.h"
#include "src/api/Document.h"

using namespace nx;

int main() {
    Nuxeo nuxeo = Nuxeo::Builder().build();
    api::Document::Query query("SELECT * FROM Document");
    nuxeo.request(query);

    api::Document::PageProvider pageProvider("tree_children");
    params_t params{};
    params["queryParams"] = "default_domain";
    pageProvider.set_parameters(params);

    nuxeo.request(pageProvider);
    std::cout << nuxeo << std::endl;
    return 0;
}