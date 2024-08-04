#include "source_location_formatter.h"
#include <iostream>

int main() {
    std::cout << std::format("Current location: {}",
                             std::source_location::current()) << '\n';
}

