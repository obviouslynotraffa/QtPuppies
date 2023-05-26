#include "dog.h"

Dog::Dog(unsigned int d, unsigned int m, unsigned int y, std::string n): date(Date(d,m,y)), name(n) {}

Dog::~Dog(){}

Date Dog::getDate() const{
    return date;
}

std::string Dog::getName() const{
    return name;
}

Dog* Dog::setDate(const Date& d){
    date=d;
    return this;
}

Dog* Dog::setName(const std::string& s){
    name=s;
    return this;
}


