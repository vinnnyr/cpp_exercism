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
void Robot::advance(){
    // Coordinate system is 
    //          (+x)
    //          ^ 
    //          | 
    //          o ---> (+y)
    switch(bearing)
    {
    case Bearing::NORTH:
        position.second = position.second + 1; //y + 1
        break;
    case Bearing::EAST:
        position.first = position.first + 1; //x+1 
        break;
    case Bearing::WEST:
        position.first = position.first - 1; //x-1
        break;
    case Bearing::SOUTH:
        position.second = position.second - 1; //y - 1
        break;
    }
}
void Robot::execute_sequence(std::string seq){
    for(unsigned int i = 0; i < seq.length(); i++){
        switch (seq[i])
        {
        case 'R':
            turn_right();
            break;
        case 'L':
            turn_left();
            break;
        case 'A':
            advance();
            break;
        default:
            break;
        }
    }
}

std::pair <int,int> Robot::get_position() const {
    return position;
}
Bearing Robot::get_bearing() const {
    return bearing; 
}
}  // namespace robot_simulator
