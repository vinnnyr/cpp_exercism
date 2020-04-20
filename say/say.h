#if !defined(SAY_H)
#define SAY_H
#include <string>
#include <stdexcept>
#include <cmath>
#define TRILLION 1000000000000

namespace say {

std::string in_english(unsigned long input);
std::string processNumbers(unsigned long input);
std::string powersOfTen(unsigned long input,unsigned long ten,std::string tenString);
std::string getHundredAndUnder(unsigned long input);
std::string numbers_under_ten(unsigned long input);
std::string teen_numbers(unsigned long input);
std::string div_by_ten(unsigned long input);
}  // namespace say

#endif // SAY_H