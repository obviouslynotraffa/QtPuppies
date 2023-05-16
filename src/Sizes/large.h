#ifndef LARGE_H
#define LARGE_H
#include "size.h"
#include "Dog/date.h"


class Large: public Size {

    private:
    static double multiplier;
    public:
         double stayTax(const Date& d) const;
         double bath() const;
         double training() const;
         double diet () const;
         double walkDog() const;
};


#endif
