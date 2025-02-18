#include <iostream>
#include <string>
#include "system.h"


/**
 * @brief Entry point of the program.
 *
 * This function initializes the program and manages execution.
 */
int main(int argc, char* argv[]) {

    //default values
    //N = 20
    //maxDisplacment = 0.6
    //dt = 0.5
    //L = 20

    std::cout << "Number of disks: " << atoi(argv[1]) << "\n";
    std::cout << "Max displacement: " << atof(argv[2]) << "\n";
    std::cout << "Time step: " << atof(argv[3]) << "\n";
    std::cout << "Box length: " << atof(argv[4]) << "\n";


    // number of disks
    int N = atoi(argv[1]);
    double maxDisplacement  = atof(argv[2]);
    double dt = atof(argv[3]);
    double L = atof(argv[4]);

    // initialise the system
    System system(N, maxDisplacement,dt,L,1234);

    // total number of iterations
    int iterations = N*500;

    for (int i = 0; i < iterations; ++i) {
        // move one disk
        system.step();
        // save a configuration
        system.save("confs/conf"+std::to_string(i));
    }
    return 0;
}