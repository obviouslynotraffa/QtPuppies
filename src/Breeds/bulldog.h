#ifndef BULLDOG_H
#define BULLDOG_H
#include "breed.h"

class Bulldog: public Breed{
    private:
        static double p;
    public:
        double price() const;
        std::string toString() const;
};


#endif
