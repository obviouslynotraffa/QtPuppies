#include "Reader.h"

#include "sizes/large.h"
#include "sizes/medium.h"
#include "sizes/small.h"

#include "breeds/amstaff.h"
#include "breeds/bulldog.h"

/*
const QList<Dog*> Reader::getListDog()const{
    return dogList;
}
*/

const QList<Owner*> Reader::getListOwner()const{
    return ownerList;
}


/*
Reader& Reader::clearDog(){
    dogList.clear();
    return *this;
}

*/

Reader& Reader::clearOwner(){
    ownerList.clear();
    return *this;
}


/*
Dog* Reader::readDog(const QJsonObject& object){

    QJsonValue type = object.value("type");

    if (type.isUndefined()) {
            throw std::invalid_argument("Missing item type.");
    }

    if(type.toString().compare("breeding")==0){
        dogList.append(readBreeding(object));
    }

    else if(type.toString().compare("boarding")==0){
        dogList.append(readBoarding(object));
    }

    return dogList.last();

}
*/


Owner* Reader::readOwner(const QJsonObject& object){

    QJsonValue type = object.value("type");

    if (type.isUndefined()) {
        throw std::invalid_argument("Missing item type.");
    }



    if(type.toString().compare("owner")){
        ownerList.append(readOwner(object));
    }

    return ownerList.last();

}


Owner* Reader::readOwner(const QJsonObject &object) const{
    return new Owner(object.value("name").toString().toStdString(),
                     object.value("surname").toString().toStdString(),
                     object.value("phone").toString().toStdString(),
                     object.value("day").toInt(),
                     object.value("month").toInt(),
                     object.value("year").toInt(),
                     object.value("address").toString().toStdString(),
                     object.value("house_number").toString().toStdString());
}

/*
Dog* Reader::readBoarding(const QJsonObject &object) const{

    QString sizeDog=object.value("size").toString();

    Size*s;


    if(sizeDog=="small") s= new Small();
    else if(sizeDog=="medium") s= new Medium();
    else if (sizeDog=="large") s = new Large();

    return new Boarding(
                object.value("day").toInt(),
                object.value("month").toInt(),
                object.value("year").toInt(),
                object.value("name").toString().toStdString(),
                s,
                nullptr,
                object.value("breed").toString().toStdString(),
                object.value("bath").toBool(),
                object.value("training").toBool(),
                object.value("diet").toBool(),
                object.value("walks").toBool()
                );
}


Dog* Reader::readBreeding(const QJsonObject &object) const{

    QString breedDog=object.value("breed").toString();

    Breed* b;

    if(breedDog=="bulldog") b= new Bulldog();
    else if (breedDog=="amstaff") b= new AmStaff();


    return new Breeding(
                object.value("day").toInt(),
                object.value("month").toInt(),
                object.value("year").toInt(),
                object.value("name").toString().toStdString(),
                b,
                object.value("vax").toBool(),
                object.value("purch").toBool(),
                object.value("booked").toBool(),
                nullptr,
                nullptr
                );
}
*/
