#include "say.h"

namespace say {
std::string in_english(unsigned long input){
    if (input==0){
        return "zero"; //zero is a special case
    }
    else if (input >= TRILLION){
        throw std::domain_error("ERROR"); //per readme requirements
        return {};
    }
    else if (input > 0){
        return processNumbers(input); //helper function to do the math, and to ensure we don't get caught in the "zero" case
    }
    else {
        throw std::domain_error("ERROR"); // if other weird things happen
        return {};
    }
}
std::string processNumbers(unsigned long input){
    if(input >= 1000000000){
        return powersOfTen(input,1000000000,"billion");
        }
    if(input >= 1000000){
        return powersOfTen(input,1000000,"million");
        }
    else if(input >= 1000){
        return powersOfTen(input,1000,"thousand");
        }
    else if(input >= 100){
        return powersOfTen(input,100,"hundred");
        }
    else if (input< 100){
        return(getHundredAndUnder(input));
    }
    else{
        throw std::domain_error("ERROR");
        return {};//not sure how you would get here
    }
}
std::string powersOfTen(unsigned long input,unsigned long ten,std::string tenString){
    // This takes in the number, the power of ten, and the english representation of that power of ten and then starts the recursion
    // Example powersOfTen(1450,1000,"thousand") -- we want to break up the number 1450 into groups of 1000s
    unsigned long nTens = std::floor(input/ten);
    unsigned long remainderTens = input % ten;
    std::string space = "";
    if(remainderTens!=0){ //if there is a remainder, then this space is needed.
        space = " ";
    }
    return processNumbers(nTens) +" "+tenString+ space +processNumbers(remainderTens);
}
std::string getHundredAndUnder(unsigned long input){
    if (input < 10) 
    {
        return numbers_under_ten(input);
    }
    else if (input % 10 == 0){ //then this is a nice even number
        return div_by_ten(input);
    }
    else if ((10 < input) && (input < 20)) //the teen numbers in english are odd
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
            return {}; // the real string zero is handled somewhere else
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
            throw std::domain_error("ERROR");
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
        throw std::domain_error("ERROR");
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
        return ("forty");
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
    case 100:
        return("hundred");
        break;
    default:
        throw std::domain_error("ERROR");
        return("ERROR");
        break;
    }
}
}  // namespace say
