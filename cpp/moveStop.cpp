#include <lcm/lcm-cpp.hpp>
#include "/home/pi/WebBot/lib/exlcm/command_t.hpp"

#include <string>

int main(int argc, char ** argv)
{
    lcm::LCM lcm;
    if(!lcm.good())
        return 1;

    exlcm::command_t my_command;
    my_command.command = "STP";

    lcm.publish("COMMANDS", &my_command);

    return 0;
}
