#ifndef OWNER_H
#define OWNER_H
#include <string>
#include "date.h"





class Owner{
    private:
        std::string name;
        std::string surname;
        std::string phone;
        std::string address;
        std::string house_number;
        Date birth;
    public:
        Owner(std::string n, std::string s, std::string p, unsigned int d, unsigned int m, unsigned int y ,
        std::string a="", std::string h="");
        ~Owner();


        std::string getName() const;
        std::string getSurname() const;
        std::string getPhone() const;
        std::string getAddress() const;
        std::string getHouseNumber() const;
        Date getBirthD() const;
};

std::ostream& operator<<(std::ostream& o, const Owner& p);



#endif
