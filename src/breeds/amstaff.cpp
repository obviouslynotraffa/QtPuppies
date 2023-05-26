#include "amstaff.h"

double AmStaff::p=900;

double AmStaff::price() const{
    return p;
}

std::string AmStaff::toString() const{
    std::string b = " AmStaff ";
    return b;
}
