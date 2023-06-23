#include "breeding.h"

Breeding::Breeding(unsigned int d, unsigned int m, unsigned int y, std::string n,
                   Breed* b, bool vax, bool booked, bool purch, Breeding* mom, Breeding* dad):
                   Dog(d,m,y,n),breed(b), vax(vax), purchasable(purch), booked(booked) , mother(mom), father(dad){}

Breeding::~Breeding() {
    //delete breed;
}

Breed* Breeding::getBreed() const {
    return breed;
}


Breeding* Breeding::getFather() const {
    return father;
}

Breeding* Breeding::getMother() const{
    return mother;
}

bool Breeding::isBooked() const{
    return booked;
}


bool Breeding::isVax() const {
    return vax;
}


bool Breeding::isPurchasable() const {
    return purchasable;
}


Breeding* Breeding::setVax(const bool b){
    vax=b;
    return this;
}

Breeding* Breeding::setPurch(const bool b){
    purchasable=b;
    return this;
}

Breeding* Breeding::setBooked(const bool b){
    booked=b;
    return this;
}

Breeding* Breeding::setDad(Breeding* b){
    father=b;
    return this;
}


Breeding* Breeding::setMom(Breeding* b){
    mother=b;
    return this;
}

Breeding* Breeding::setBreed(Breed* p){
    breed=p;
    return this;
}



double Breeding::totPrice() const{
    Breed* br=getBreed();
    double tot=br->price();

    time_t now = time(0);
    tm *ltm = localtime(&now);

    Date today(ltm->tm_mday,1+(ltm->tm_mon),1900+ltm->tm_year);
    Date aux=getDate().addDays(180);

    while((aux<today) && (tot>600)){
        tot-=75;
        aux=aux.addDays(180);

    }
    if(tot>600)return tot;
    else return 600;


}

void Breeding::accept(DogVisitor& visitor){
    visitor.visitBreeding(*this);
}


