#include "small.h"

double Small::multiplier=1.05;

double Small::stayTax(const Date& d) const{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    Date today(ltm->tm_mday,1+(ltm->tm_mon),1900+ltm->tm_year);

    return ((today-d)*priceStay)*multiplier;
}



double Small::diet() const{
    return priceDiet*multiplier;
}



double Small::training() const{
    return priceTraining*multiplier;
}



double Small::walkDog() const{
    return priceWalking*multiplier;
}


double Small::bath() const {
    return priceBath*multiplier;
}

