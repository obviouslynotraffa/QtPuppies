#ifndef AMSTAFF_H
#define AMSTAFF_H
#include "breed.h"

class AmStaff: public Breed{
    private:
        static double p;
    public:
        double price() const;
        std::string toString() const;
};


#endif
