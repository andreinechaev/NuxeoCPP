# Nuxeo C++ client

The project intends to bring Nuxeo REST client to C++. Project maintainer Andrei Nechaev.
For all questions, comments and/or concerns please reach [us via email](mailto:an@nuxeo.com) 
or file an [issue](http://github.com/nuxeo/add_link_here)

## Package manager

We use Conan for managing our dependencies along with *cmake* generator.

To pull dependencies run: 

`conan install . -s build_type=Debug --install-folder=cmake-build-debug` - for debug build

`conan install . -s build_type=Release --install-folder=cmake-build-release` - for release build

## Usage

TODO: Add examples

## About Nuxeo

Nuxeo dramatically improves how content-based applications are built, 
managed and deployed, making customers more agile, 
innovative and successful. Nuxeo provides a next generation, 
enterprise ready platform for building traditional and cutting-edge 
content oriented applications. Combining a powerful application development 
environment with SaaS-based tools and a modular architecture, 
the Nuxeo Platform and Products provide clear business value 
to some of the most recognizable brands including 
Verizon, Electronic Arts, Sharp, FICO, the U.S. Navy, and Boeing. 
Nuxeo is headquartered in New York and Paris. 
More information is available at [www.nuxeo.com](http://www.nuxeo.com).

