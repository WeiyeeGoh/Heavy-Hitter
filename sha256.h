#ifndef SHA256_H
#define SHA256_H

#include <string.h>
#include <iostream>
#include <openssl/sha.h>

int sha256(std::string str)
{
    unsigned char digest[SHA256_DIGEST_LENGTH];


    std::string s = str;

    char cstr[s.size() + 1];
    strcpy(cstr, s.c_str());

    SHA256((unsigned char*)&cstr, strlen(cstr), (unsigned char*)&digest);    

    char mdString[SHA256_DIGEST_LENGTH*2+1];

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    	/* Convert the unsigned int in hexadecimal format to char and store it in variable 'mdString' */
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    }
    
    return std::stoi(mdString);
}

#endif