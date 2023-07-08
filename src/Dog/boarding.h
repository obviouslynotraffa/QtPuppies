#ifndef BOARDING_H
#define BOARDING_H
#include "./sizes/size.h"
#include "dog.h"
#include "owner.h"


class Boarding: public Dog{
    private:
        Size* size;
        Owner* owner;
        std::string breed;
        bool bath;
        bool training;
        bool diet;
        bool walking;
    public:
        Boarding(unsigned int d, unsigned int m, unsigned int y, std::string n, Size* s, Owner* o, std::string b,
        bool bath, bool training, bool diet, bool walking);
        ~Boarding();

        Size* getSize() const;
        Owner* getOwner() const;
        std::string getBreed() const;

        bool didBath() const;
        bool didTraining() const;
        bool didDiet() const;
        bool didWalking() const;


        Boarding* setBath(const bool& b);
        Boarding* setTraining(const bool& b);
        Boarding* setDiet(const bool& b);
        Boarding* setWalking(const bool& b);
        Boarding* setBreed(const std::string& s);
        Boarding* setSize(Size* s);
        Boarding* setOwner(Owner* o);


        double totPrice() const;

        void accept(DogVisitor& visitor);

};


#endif
