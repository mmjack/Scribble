/*
 * sha3.cpp
 *
 *  Created on: 15 Nov 2013
 *      Author: blake
 */
#include "sha3.h"
#include <stdio.h>

std::string sha3_text(std::string input, unsigned int outputLength) {
    uint8_t* buffer = new uint8_t[outputLength];
    sha3_hash((uint8_t*) input.c_str(), input.size(), buffer, outputLength);

    char* resultBuffer = new char[outputLength * 2 + 1];

    for (unsigned int i = 0; i < outputLength; i++) {
        sprintf(resultBuffer + (i*2), "%02X", (unsigned char) buffer[i]);
    }

    std::string hashString = std::string(resultBuffer);
    return hashString;
}
