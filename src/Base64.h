#ifndef _BASE64_H_
#define _BASE64_H_

#include <vector>
#include <string>
typedef unsigned char BYTE;

class Base64
{
public:
    static std::vector<BYTE> decode(std::string encoded_string);
};

#endif
