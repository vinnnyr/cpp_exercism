#if !defined(SAY_H)
#define SAY_H
#include <string>
#include <cmath>

namespace say {

std::string in_english(unsigned long input);
std::string zero_to_ninetynine(unsigned long input);
std::string numbers_under_ten(unsigned long input);
std::string teen_numbers(unsigned long input);
std::string div_by_ten(unsigned long input);
}  // namespace say

#endif // SAY_H