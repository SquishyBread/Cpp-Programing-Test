#include <fstream>
#include "system.h"
#include "disk.h"

System::System(int N, double displacement,double radius, double boxSize, int seed) {

        this->boxSize= boxSize;
        this-> uniformDist = std::uniform_real_distribution<double>(0, 1);
        this-> normalDist = std::normal_distribution<double>(0.0, 1);
        this->displacement=displacement;
        gen = std::mt19937(seed);
        
        int nSide = static_cast<int>(boxSize/ (2*radius));

        for (int i = 0; i < nSide && disks.size() < N; ++i) {
            for (int j = 0; j < nSide && disks.size() < N; ++j) {
                disks.push_back(Disk(radius + i * 2*radius, radius + j * 2*radius, radius));
            }
        }
    }   

bool System::overlap(int i){
    for (int j = 0; j < disks.size(); ++j) {
        if (i!=j && disks[i].distance(disks[j]) < (disks[i].getRadius() + disks[j].getRadius()) ) {
            return true;
        }
    }
    return false;
}

void System::step() {
    for (size_t i = 0; i<disks.size(); ++i) 
    {
        int selected_disk = std::rand() % disks.size();
        double oldx = disks[selected_disk].getX();
        double oldy = disks[selected_disk].getY();
        //double dx = uniform(-displacement, displacement);
        //double dy = uniform(-displacement, displacement);
        double dx = normal(displacement);
        double dy = normal(displacement);
        this->disks[selected_disk].move(dx, dy);
        
        enforceBoundaries(disks[selected_disk]);

        if (overlap(selected_disk)){
            disks[selected_disk].setX(oldx);
            disks[selected_disk].setY(oldy);
        }
       
    }
}
void System::enforceBoundaries(Disk & disk) {
        if (disk.getX() < disk.getRadius()) disk.setX(disk.getRadius());
        if (disk.getX() > boxSize - disk.getRadius()) disk.setX(boxSize - disk.getRadius());
        if (disk.getY() < disk.getRadius()) disk.setY(disk.getRadius());
        if (disk.getY() > boxSize - disk.getRadius()) disk.setY(boxSize - disk.getRadius());
    }

double System::uniform (double min, double max){
    return (max-min)*this->uniformDist(gen)+min;
}

double System::normal(double sigma){
    return sigma * this->normalDist(gen);
}

void System::save(const std::string &filename){
    // save state of disks to file
    std::ofstream outFile(filename);
    outFile<<disks.size()<<std::endl;
    outFile<<"Comment"<<std::endl;
    for (Disk& disk : disks) {
      outFile<<"A "<<disk.getX()<<" "<<disk.getY()<<" "<<disk.getRadius()<<std::endl;

    }
    outFile.close();
    
}