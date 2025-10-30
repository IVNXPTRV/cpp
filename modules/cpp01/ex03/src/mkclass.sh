#!/usr/bin/env bash

# Script to generate C++98 class files
if [ $# -eq 0 ]; then
    echo "Usage: $0 ClassName1 ClassName2 ..."
    exit 1
fi

for class in "$@"; do
    # Create header file
    hpp_file="${class}.hpp"
    cpp_file="${class}.cpp"

    echo "#ifndef ${class^^}_HPP
#define ${class^^}_HPP

#include <iostream>

class ${class} {
public:
    ${class}();
    ~${class}();

    void exampleMethod();

private:
    // Add member variables here
};

#endif // ${class^^}_HPP" > "$hpp_file"

    # Create source file
    echo "#include \"${class}.hpp\"

${class}::${class}() {
    // Constructor implementation
}

${class}::~${class}() {
    // Destructor implementation
}

void ${class}::exampleMethod() {
    // Example method implementation
}" > "$cpp_file"

    echo "Generated $hpp_file and $cpp_file"
done
