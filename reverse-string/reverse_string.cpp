#include "reverse_string.h"

namespace reverse_string {
std::string reverse_string(std::string inputString)
{
    std::string outputString = inputString;
    for(signed int i=inputString.length()-1; i>=0; i--){ //has to be signed int because of the comparision to 0
        signed int i_prime = outputString.length()-1-i; //this will be 0 if i is equal to string length -1 , etc.
        outputString[i_prime] = inputString[i];
    }
    return outputString;
}
}  // namespace reverse_string
