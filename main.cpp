#include <iostream>
#include "src/client/Nuxeo.h"

using namespace nx;

int main() {
    Nuxeo nuxeo = Nuxeo::Builder().build();
    std::cout << nuxeo << std::endl;
    return 0;
}