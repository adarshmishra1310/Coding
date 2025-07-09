#pragma once
#include <string>
#include <vector>

std::string sha256(const std::string &);
std::vector<unsigned char> aes_encrypt(
    const std::vector<unsigned char>& plaintext,
    const std::vector<unsigned char>& key,
    std::vector<unsigned char>& iv_out
);
std::vector<unsigned char> aes_decrypt(
    const std::vector<unsigned char>& ciphertext_with_iv,
    const std::vector<unsigned char>& key
);