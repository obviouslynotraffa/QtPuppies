#include "owner.h"



Owner::Owner(std::string n, std::string s, std::string p, unsigned int d, unsigned int m, unsigned int y ,
        std::string a, std::string h):
name(n), surname(s), phone(p), address(a), house_number(h), birth(Date(d,m,y))  {}


Owner::~Owner() {}


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

std::ostream& operator<<(std::ostream& os, const Owner& o){
    os<<o.getSurname()<<" "<<o.getName()<<", nato il "<<o.getBirthD();

    if(o.getAddress()!=""){
        os<<", residente a "<<o.getAddress();
        if(o.getHouseNumber() !="")
        os<<", "<<o.getHouseNumber();
    }

    os<<", con recapito telefonico: "<<o.getPhone()<<std::endl;

    return os;
}

