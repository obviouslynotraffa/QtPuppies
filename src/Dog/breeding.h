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


        bool isVax() const;
        bool isPurchasable() const;
        Breed* getBreed() const;
        double totPrice() const;
        bool isBooked() const;

        void setBooked(bool b);
        void setVax(bool b);
        void setPurch(bool b);
        void setDad(Breeding* b);
        void setMom(Breeding* b);
        void setBreed(Breed* p);

        void accept(DogVisitor& visitor);
};


#endif
