#ifndef SMALL_H
#define SMALL_H
#include "size.h"
#include "Dog/date.h"

class Small: public Size {

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
