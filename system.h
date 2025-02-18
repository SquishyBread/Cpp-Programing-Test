#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include "disk.h"

class System {
    public:
        System(int N, double displacement,double radius, double box_size, int seed, bool normal);
        void step();
        void save(const std::string &filename);

    private:
        std::vector<Disk> disks;
        double boxSize;
        double displacement;
        std::mt19937 gen;
        std::uniform_real_distribution<double> uniformDist;
        std::normal_distribution<double> normalDist;
        bool isNormal;

        bool overlap(int i);
        void enforceBoundaries(Disk & disk);
        double uniform(double min, double max);
        double normal(double sigma);
};

#endif