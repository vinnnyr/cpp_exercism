#include "gigasecond.h"

namespace gigasecond {
ptime advance(ptime inputTime){
    
    return inputTime+seconds(1E9);
}
}  // namespace gigasecond
