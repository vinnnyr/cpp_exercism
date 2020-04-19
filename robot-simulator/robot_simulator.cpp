#include "robot_simulator.h"

namespace robot_simulator {

Robot::Robot(){
    //default constructor
    position = {0,0};
    bearing = Bearing::NORTH;
}  

Robot::Robot(std::pair <int,int> position_,Bearing bearing_){
    //constructor when start position specified.
    position = position_;
    bearing = bearing_;
}

void Robot::turn_right(){
    //this seems really inefficient. I think I want to have direction as angle, and just add 90 deg, 
    //but the tests force me to use an enum class
    switch(bearing){
        case Bearing::NORTH : bearing = Bearing::EAST; break; //these breaks are important in cpp
        case Bearing::EAST : bearing = Bearing::SOUTH; break;
        case Bearing::SOUTH : bearing = Bearing::WEST; break;
        case Bearing::WEST : bearing = Bearing::NORTH; break;
    }
}
void Robot::turn_left(){
    // same inefficiency as turn_right()
    switch(bearing){
        case Bearing::NORTH : bearing = Bearing::WEST; break;
        case Bearing::EAST : bearing = Bearing::NORTH; break;
        case Bearing::SOUTH : bearing = Bearing::EAST; break;
        case Bearing::WEST : bearing = Bearing::SOUTH; break;
    }
}

std::pair <int,int> Robot::get_position() const {
    return position;
}
Bearing Robot::get_bearing() const {
    return bearing; 
}
}  // namespace robot_simulator
