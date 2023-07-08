#include "owner.h"



Owner::Owner(std::string n, std::string s, std::string p, unsigned int d, unsigned int m, unsigned int y ,
        std::string a, std::string h):
name(n), surname(s), phone(p), address(a), house_number(h), birth(Date(d,m,y))  {}


Owner::~Owner() {
}


std::string Owner::getName() const{
    return name;
}


std::string Owner::getSurname() const{
    return surname;
}


std::string Owner::getPhone() const{
    return phone;
}

std::string Owner::getHouseNumber() const{
    return house_number;
}

std::string Owner::getAddress() const{
    return address;
}


Date Owner::getBirthD() const{
    return birth;
}




Owner* Owner::setName(const std::string &s){
    name=s;
    return this;
}


Owner* Owner::setSurname(const std::string &s){
    surname=s;
    return this;
}


Owner* Owner::setPhone(const std::string &s){
    phone=s;
    return this;
}


Owner* Owner::setAddress(const std::string &s){
    address=s;
    return this;
}


Owner* Owner::setHouseNumber(const std::string &s){
    house_number=s;
    return this;
}


Owner* Owner::setBirthday(const Date &d){
    birth=d;
    return this;
}


