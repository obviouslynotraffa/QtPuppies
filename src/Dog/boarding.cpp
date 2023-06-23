#include "boarding.h"

Boarding::Boarding(unsigned int d, unsigned int m, unsigned int y, std::string n, Size* s, Owner* o, std::string b,
        bool bath, bool training, bool diet, bool walking): Dog(d,m,y,n), size(s), owner(o), breed(b), bath(bath),
        training(training), diet(diet), walking(walking) {}

Boarding::~Boarding() {
    delete owner;
    //delete size;
}


Size* Boarding::getSize() const {
    return size;
}

Owner* Boarding::getOwner() const{
    return owner;
}

std::string Boarding::getBreed() const{
    return breed;
}


bool Boarding::didBath() const{
    return bath;
}

bool Boarding::didDiet() const{
    return diet;
}

bool Boarding::didTraining() const{
    return training;
}

bool Boarding::didWalking() const{
    return walking;
}



Boarding* Boarding::setBath(const bool &b){
    bath=b;
    return this;
}

Boarding* Boarding::setDiet(const bool &b){
    diet=b;
    return this;
}


Boarding* Boarding::setTraining(const bool &b){
    training=b;
    return this;
}



Boarding* Boarding::setWalking(const bool &b){
    walking=b;
    return this;
}


Boarding* Boarding::setBreed(const std::string& s){
    breed=s;
    return this;
}


Boarding* Boarding::setOwner(Owner* o){
    owner=o;
    return this;
}



Boarding* Boarding::setSize(Size* s){
    size=s;
    return this;
}




double Boarding::totPrice() const{
    double tot=0;
    Size* sz=getSize();

    if(didBath())tot+=sz->bath();
    if(didDiet())tot+=sz->diet();
    if(didTraining())tot+=sz->training();
    if(didWalking())tot+=sz->walkDog();
    tot+=sz->stayTax(getDate());
    return tot;
}

void Boarding::accept(DogVisitor& visitor){
    visitor.visitBoarding(*this);
}
