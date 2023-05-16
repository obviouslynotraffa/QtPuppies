#include "dog.h"

Dog::Dog(unsigned int d, unsigned int m, unsigned int y, std::string n): date(Date(d,m,y)), name(n) {}

Dog::~Dog(){}

Date Dog::getDate() const{
    return date;
}

std::string Dog::getName() const{
    return name;
}

void Dog::setDate(const Date& d){
    date=d;
}

void Dog::setName(std::string s){
    name=s;
}

std::ostream& operator<<(std::ostream& o, const Dog& d){
    return o<<d.getName();
}
