#include "reverse_string.h"

namespace reverse_string {
std::string reverse_string(std::string inputString)
{
    std::reverse(inputString.begin(),inputString.end()); 
    return inputString;//reverse operates in place, therefore we are modifying the inputString itself.
}
}  // namespace reverse_string
