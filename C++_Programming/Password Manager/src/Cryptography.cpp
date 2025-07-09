#include "Cryptography.h"
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

std::string sha256(const std::string &input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.data()), input.size(), hash);

    std::ostringstream os;
    for (unsigned char b : hash) {
        os << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(b);
    }
    return os.str();
}

std::vector<unsigned char> aes_encrypt(...){ /* generate iv, encrypt via EVP, prepend iv */ }
std::vector<unsigned char> aes_decrypt(...){ /* parse iv + decrypt */ }