#include "say.h"

namespace say {
std::string in_english(unsigned long input){
    if(input >= 100){
        unsigned long nHundreds = std::floor(input/100);
        unsigned long remainderHundreds = input % 100;
        if(remainderHundreds==0){
            return(zero_to_ninetynine(nHundreds) +" hundred");
        }
        else{
            return(zero_to_ninetynine(nHundreds) +" hundred " + zero_to_ninetynine(remainderHundreds));
        }
        
    }
    else{
        return zero_to_ninetynine(input);
    }
}
std::string zero_to_ninetynine(unsigned long input){
    if (input < 10)
    {
        return numbers_under_ten(input);
    }
    else if (input % 10 == 0){
        return div_by_ten(input);
    }
    else if ((10 < input) && (input < 20))
    {
        return teen_numbers(input);
    }
    else {
        unsigned long nearestTen = std::floor(input/10) * 10; //for example, will take in 42 and output 40
        unsigned long remainder = input % 10; // in same example, will give you 2
        std::string nearestTenString = div_by_ten(nearestTen);//"fourty"
        std::string remainderString = numbers_under_ten(remainder);//"two"
        return nearestTenString + "-" + remainderString;//"fourty-two"
    }
}

std::string numbers_under_ten(unsigned long input){
    switch(input)
    {
        case(0):
            return("zero");
            break;
        case(1):
            return("one");
            break;
        case (2):
            return("two");
            break;
        case (3):
            return("three");
            break;
        case (4):
            return ("four");
            break;
        case (5):
            return ("five");
            break;
        case (6):
            return ("six");
            break;
        case (7):
            return ("seven");
            break;
        case (8):
            return("eight");
            break;
        case (9):
            return("nine");
            break;
        default:
            return("ERROR"); //this shouldnt be a reached state
            break;
    }
}
std::string teen_numbers(unsigned long input){
    switch (input)
    {
    case (11):
        return("eleven");
        break;
    case (12):
        return("twelve");
        break;
    case (13):
        return("thirteen");
        break;
    case (14):
        return("fourteen");
        break;
    case (15):
        return("fifteen");
        break;
    case (16):
        return("sixteen");
        break;
    case (17):
        return("seventeen");
        break;
    case (18):
        return("eigthteen");
        break;
    case (19):
        return("nineteen");
        break;
    default:
        return("ERROR");
        break;
    }
}
std::string div_by_ten(unsigned long input){
    switch (input)
    {
    case 10:
        return ("ten");
        break;
    case 20:
        return ("twenty");
        break;
    case 30:
        return ("thirty");
        break;
    case 40:
        return ("fourty");
        break;
    case 50:
        return ("fifty");
        break;
    case 60:
        return ("sixty");
        break;
    case 70:
        return ("seventy");
        break;
    case 80:
        return ("eighty");
        break;
    case 90:
        return ("ninety");
        break;
    default:
        return("ERROR");
        break;
    }
}
}  // namespace say
