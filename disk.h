 #ifndef DISK_H
 #define DISK_H

class Disk {
    public:
        Disk(double x, double y, double r) ;

        void move(double dx, double dy) ;
        double distance(Disk& d) ;

        double getX();
        double getY();
        double getRadius();
        void setX(double x);
        void setY(double y);
        
    private:
        double x, y, radius;
};

#endif