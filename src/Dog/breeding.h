#ifndef BREEDING_H
#define BREEDING_H
#include <string>
#include "dog.h"
#include "./breeds/breed.h"


class Breeding: public Dog{
    private:
        Breed* breed;
        Breeding* mother;
        Breeding* father;
        bool vax;
        bool purchasable ;
        bool booked;
    public:
        Breeding(unsigned int d, unsigned int m, unsigned int y, std::string n, Breed* b, Breeding* mom=nullptr, Breeding* dad=nullptr);
        ~Breeding();

        Breeding* getFather() const;
        Breeding* getMother() const;
        Breed* getBreed() const;

        bool isVax() const;
        bool isPurchasable() const;
        bool isBooked() const;

        Breeding* setBooked(const bool& b);
        Breeding* setVax(const bool& b);
        Breeding* setPurch(const bool& b);
        Breeding* setDad(Breeding* b);
        Breeding* setMom(Breeding* b);
        Breeding* setBreed(Breed* p);

        double totPrice() const;

        void accept(DogVisitor& visitor);
};


#endif
