#include "hamming.h"
namespace hamming {

int compute(string sequence1,string sequence2){
    int distance = 0; // init distance counter
    
    // check if string length is same, otherwise this hamming distance does not work.
    bool stringLengthSameness = isStringLengthSame(sequence1,sequence2);
    if (!stringLengthSameness){
        throw std::domain_error("Hamming Distance cannot be calculated with different length strings");
    }

    for(unsigned int i = 0; i < sequence1.length(); i++){
        if (!(sequence1[i] == sequence2[i])){ // don't have to worry about out of bounds errors, as that will be caught up above
            distance++;
        }
    }

    return distance;
}

bool isStringLengthSame(string string1, string string2){
    if (string1.length() == string2.length())
    {
        return true;
    }
    else {
        return false;
    }
}
}  // namespace hamming
