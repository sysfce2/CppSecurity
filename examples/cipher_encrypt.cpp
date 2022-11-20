/*!
    \file cipher_encrypt.cpp
    \brief Cipher encrypt example
    \author Ivan Shynkarenka
    \date 20.11.2022
    \copyright MIT License
*/

#include "security/cipher.h"

#include "string/encoding.h"

#include <iostream>

int main(int argc, char** argv)
{
    CppSecurity::Cipher cipher;

    // Show the password
    std::password password = "passw0rd";
    std::cout << "Password: " << password << std::endl;

    // Initialize the cipher with a password and salt
    cipher.Initialize(password, "12345678");
    std::cout << "Cipher name: " << cipher.name() << std::endl;
    std::cout << "Cipher iterations: " << cipher.iterations() << std::endl;

    std::cout << "Please enter strings to encrypt. Enter '0' to exit..." << std::endl;

    // Perform text input
    std::string line;
    while (getline(std::cin, line))
    {
        if (line.empty() || (line == "0"))
            break;

        std::string encrypted = cipher.Encrypt(line);
        std::string encoded = CppCommon::Encoding::Base32Encode(encrypted);

        // Show the encoded string
        std::cout << encoded << std::endl;
    }

    return 0;
}
