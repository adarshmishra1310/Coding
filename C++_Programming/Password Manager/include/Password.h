#pragma once
#include <string>
#include <vector>

struct Entry {
    std::string label;
    std::string cipher;
};

// load JSON store
std::vector<Entry> load_store(const std::string &path);
void save_store(const std::string &path, const std::vector<Entry>&);
```cpp
#pragma once
#include <string>
#include <vector>

struct Entry {
    std::string label;
    std::string cipher;
};

// load JSON store
std::vector<Entry> load_store(const std::string &path);
void save_store(const std::string &path, const std::vector<Entry>&);