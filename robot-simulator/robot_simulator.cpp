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

std::pair <int,int> Robot::get_position() const {
    return position;
}
Bearing Robot::get_bearing() const {
    return bearing; 
}
}  // namespace robot_simulator
