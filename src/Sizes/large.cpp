#include "large.h"

double Large::multiplier=1.15;

double Large::stayTax(const Date& d) const{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    Date today(ltm->tm_mday,1+(ltm->tm_mon),1900+ltm->tm_year);

    return ((today-d)*priceStay)*multiplier;
}



double Large::diet() const{
    return priceDiet*multiplier;
}



double Large::training() const{
    return priceTraining*multiplier;
}



double Large::walkDog() const{
    return priceWalking*multiplier;
}


double Large::bath() const {
    return priceBath*multiplier;
}


std::string Large::toString() const{
    std:: string l= "Large";
    return l;
}
