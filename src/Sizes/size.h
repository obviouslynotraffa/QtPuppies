#ifndef SIZE_H
#define SIZE_H
#include "Dog/date.h"


class Size{
    public:
    virtual double stayTax(const Date& d) const=0;
    virtual double bath() const=0;
    virtual double training() const=0;
    virtual double diet () const=0;
    virtual double walkDog() const=0;
    virtual ~Size();

    static unsigned int priceStay;
    static unsigned int priceBath;
    static unsigned int priceTraining;
    static unsigned int priceDiet;
    static unsigned int priceWalking;
};



#endif
