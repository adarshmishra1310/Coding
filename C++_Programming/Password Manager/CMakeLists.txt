cmake_minimum_required(VERSION 3.10)
project(RCPasswordManager)
set(CMAKE_CXX_STANDARD 17)
find_package(OpenSSL REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(RCPasswordManager
    src/main.cpp
    src/Cryptography.cpp
    src/Password.cpp
    src/PasswordAndKey.cpp
    src/UUID.cpp
)

target_link_libraries(RCPasswordManager
    OpenSSL::SSL
    OpenSSL::Crypto
    nlohmann_json::nlohmann_json
)