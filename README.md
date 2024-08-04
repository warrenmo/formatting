# Source Location Formatter

This repo provides a template specialization of `std::formatter` for `std::source_location`, allowing users to covert a `source_location` to a textual representation of its data members (`file_name`, `line_number`, `column_number`, and `function_name` at the time of this writing).

### Prerequisites

- a C++20 that supports `std::format` and `std::source_location` (e.g., GCC gcc 13, Clang 16)
- CMake 3.10+
- GoogleTest (for testing)

### Building

```bash
mkdir build
cd build
cmake ..
make
```

### Running Tests

```bash
mkdir build
cd build
cmake ..
make
make test
```

### Usage

```cpp
#include "source_location_formatter.h"
#include <iostream>

int main() {
    std::cout << std::format("Current location: {}",
                             std::source_location::current());
}
```

