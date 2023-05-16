#include "breeding.h"

Breeding::Breeding(unsigned int d, unsigned int m, unsigned int y, std::string n, Breed* b, Breeding* mom, Breeding* dad)
: Dog(d,m,y,n),breed(b), mother(mom), father(dad), vax(false), purchasable(false), booked(false) {}

Breeding::~Breeding() {}

Breed* Breeding::getBreed() const {
    return breed;
}

bool Breeding::isPurchasable() const {

    if(!isBooked()){
        time_t now = time(0);
        tm *ltm = localtime(&now);

        Date today(ltm->tm_mday,1+(ltm->tm_mon),1900+ltm->tm_year);

        if(today<getDate().addDays(90)) return false;
        else return true;

    }else return false;
}

bool Breeding::isVax() const {
    return vax;
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

void Breeding::setVax(bool b){
    vax=b;
}

void Breeding::setPurch(bool b){
    purchasable=b;
}

void Breeding::setDad(Breeding* b){
    father=b;
}


void Breeding::setMom(Breeding* b){
    mother=b;
}

void Breeding::setBreed(Breed* p){
    breed=p;
}

void Breeding::setBooked(bool b){
    booked=b;
}




double Breeding::totPrice() const{
    Breed* b=getBreed();
    double tot=b->price();
    std::cout<<tot<<std::endl;

    time_t now = time(0);
    tm *ltm = localtime(&now);

    Date today(ltm->tm_mday,1+(ltm->tm_mon),1900+ltm->tm_year);
    Date aux=getDate().addDays(90).addDays(180);
    while((aux<today) && (tot>500)){
        tot-=75;
        aux=aux.addDays(180);

    }
    if(tot>500)return tot;
    else return 500;


}

void Breeding::accept(DogVisitor& visitor){
    visitor.visitBreeding(*this);
}

/*
void Breeding::cucciolata(int n, int g, int m, int a, Breeding* mom, Breeding* dad, Breed* b){
    for(int i=0;i<n;i++){
        std::string x;
        std::cout<<"Nome del cane: ";
        std::cin>>x;
        Breeding* x= new Breeding(g,m,a,x,false, false, b, mom, dad);


    }
}*/
