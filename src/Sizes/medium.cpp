#include "medium.h"

double Medium::multiplier=1.10;

double Medium::stayTax(const Date& d) const{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    Date today(ltm->tm_mday,1+(ltm->tm_mon),1900+ltm->tm_year);

    return ((today-d)*priceStay)*multiplier;
}



double Medium::diet() const{
    return priceDiet*multiplier;
}



double Medium::training() const{
    return priceTraining*multiplier;
}



double Medium::walkDog() const{
    return priceWalking*multiplier;
}


double Medium::bath() const {
    return priceBath*multiplier;
}

