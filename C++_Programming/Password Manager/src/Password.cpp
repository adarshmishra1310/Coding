#include "Password.h"
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

std::vector<Entry> load_store(const std::string &path) {
    std::ifstream in(path);
    if (!in) return {};
    json j; in >> j;
    // deserialize
}

void save_store(const std::string &path, const std::vector<Entry>& v) {
    json j = json::array();
    for (auto &e: v) j.push_back({{"label",e.label},{"cipher",e.cipher}});
    std::ofstream out(path); out << j.dump(2);
}