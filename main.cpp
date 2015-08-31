#include <iostream>
#include <cstdlib>
#include "program_options.hpp"

int main(int argc, char** argv){
    //define an object to use
    Program_options po;

    //add the required options and specify if the value
    //of that option will be data or if its just a flag option
    //data options are like "-value 1234"
    //flags options are like "-flag", if the option appears in the argv its value is true
    po.add_option("-i",po.type_data);
    po.add_option("-d",po.type_data);
    po.add_option("-s",po.type_data);
    po.add_option("-b",po.type_flag);

    //parse the args to find and set values
    po.parse_args(argc,argv);

    //to get a option value first check if it has been set
    if (po.is_set("-i"))
        //you have to specify the type of the value when you request it
        //supported types are double, int, long, long long, float, string, bool
        std::cout << "value of -i (int): " << po.get_option<int>("-i") << std::endl;
    if (po.is_set("-d"))
        std::cout << "value of -d (double): " << po.get_option<double>("-d") << std::endl;
    if (po.is_set("-s"))
        std::cout << "value of -s (string): " << po.get_option<std::string>("-s") << std::endl;
    if (po.is_set("-b"))
        //is better to just ask if "-b" is set
        std::cout << "value of -b (bool): true" << std::endl;
    return 0;
}
