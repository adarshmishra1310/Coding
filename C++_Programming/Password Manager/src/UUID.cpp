#include "UUID.h"
#include <fstream>
#include <string>

std::string getMachineUUID() {
    std::ifstream f("/etc/machine-id");
    std::string id;
    std::getline(f, id);
    return id;
}