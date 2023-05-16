#ifndef DOG_H
#define DOG_H
#include "date.h"
#include "dogvisitor.h"



class Dog{
    private:
        Date date;
        std::string name;
    public:
        Dog(unsigned int d, unsigned int m, unsigned int y, std::string n);
        virtual ~Dog();

        virtual double totPrice() const = 0;

        Date getDate() const;
        std::string getName() const;

        void setDate(const Date& d);
        void setName(std::string n);

        virtual void accept(DogVisitor& visitor)=0;
};

std::ostream& operator<<(std::ostream& o, const Dog& d);

#endif
