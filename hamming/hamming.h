#if !defined(HAMMING_H)
#define HAMMING_H
#include <stdexcept>
using namespace std;


namespace hamming {

int compute(string sequence1,string sequence2);
bool isStringLengthSame(string string1, string string2);
}  // namespace hamming

#endif // HAMMING_H