#include "bulldog.h"

double Bulldog::p=1500;

double Bulldog::price() const{
    return p;
}

std::string Bulldog::toString() const{
    std::string b = "Bulldog";
    return b;
}
