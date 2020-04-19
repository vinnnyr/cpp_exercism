#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H
// #define NORTH int 0
// #define EAST int 90
// #define SOUTH int 180
// #define WEST int 270

#include <utility>

namespace robot_simulator {
    enum struct Bearing {
        NORTH , EAST, SOUTH, WEST
        };
    class Robot{
    public:
        std::pair <int,int> get_position() const;
        Bearing get_bearing() const;
        Robot(); // default
        Robot(std::pair <int,int> position, Bearing bearing);
    private:
        std::pair <int,int> position;
        Bearing bearing;
};
}  // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H