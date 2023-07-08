#include "Reader.h"

#include "sizes/large.h"
#include "sizes/medium.h"
#include "sizes/small.h"

#include "breeds/amstaff.h"
#include "breeds/bulldog.h"


const std::vector<Dog*> Reader::getDogs() const{
    return dogs;
}

const std::vector<Owner*> Reader::getOWners()const{
    return owners;
}



Reader& Reader::clearCache(){
    dogs.clear();
    owners.clear();
    return *this;
}


void Reader::read(const QJsonObject &object){
    QJsonValue type = object.value("type");

    if(!type.isUndefined()){

        if(type.toString().compare("boarding") == 0){
            dogs.push_back(readBoarding(object));

        }
        else if (type.toString().compare("owner") == 0){
            owners.push_back(readOwner(object));

        }
        else if(type.toString().compare("breeding") == 0){
            dogs.push_back(readBreeding(object));
        }
    }
}


Dog* Reader::readBoarding(const QJsonObject &object) const{

    Size* size=nullptr;
    std::string s= object.value("size").toString().toStdString();

    if(s=="Large"){
        size = new Large();
    }
    else if(s=="Medium"){
        size = new Medium();
    }
    else if(s=="Small"){
        size= new Small();
    }


    Owner* owner=nullptr;
    std::string phone = object.value("owner").toString().toStdString();

    for(auto it = owners.begin(); it!=owners.end(); it++){
        if(phone==(*it)->getPhone()){
            owner = *it;
        }
    }


    return new Boarding(
                object.value("day").toInt(),
                object.value("month").toInt(),
                object.value("year").toInt(),
                object.value("name").toString().toStdString(),
                size,
                owner,
                object.value("breed").toString().toStdString(),
                object.value("bath").toBool(),
                object.value("training").toBool(),
                object.value("diet").toBool(),
                object.value("walking").toBool()
                );
}



Dog* Reader::readBreeding(const QJsonObject &object) const{


    Breed* breed=nullptr;
    std::string br=object.value("breed").toString().toStdString();

    if(br=="Bulldog"){
        breed= new Bulldog();
    }
    else if(br=="AmStaff"){

        breed= new AmStaff();
    }


    std::string momString=object.value("mother").toString().toStdString();
    Breeding* momPointer=nullptr;

    std::string dadString=object.value("father").toString().toStdString();
    Breeding* dadPointer=nullptr;

    if(momString!=""){
        for(Dog* dog : dogs)
        {
            Breeding* isBreeding=dynamic_cast<Breeding*>(dog);
            if(isBreeding && isBreeding->getName()==momString)
            {
                momPointer=isBreeding;
            }
        }
    }

    if(dadString!=""){
        for(Dog* dog : dogs)
        {
            Breeding* isBreeding=dynamic_cast<Breeding*>(dog);
            if(isBreeding && isBreeding->getName()==dadString)
            {
                dadPointer=isBreeding;
            }
        }
    }



    return new Breeding(
                object.value("day").toInt(),
                object.value("month").toInt(),
                object.value("year").toInt(),
                object.value("name").toString().toStdString(),
                breed,
                object.value("vax").toBool(),
                object.value("booked").toBool(),
                object.value("purch").toBool(),
                momPointer,
                dadPointer);
}



Owner* Reader::readOwner(const QJsonObject &object) const{
    return new Owner(
                object.value("name").toString().toStdString(),
                object.value("surname").toString().toStdString(),
                object.value("phone").toString().toStdString(),
                object.value("day").toInt(),
                object.value("month").toInt(),
                object.value("year").toInt(),
                object.value("address").toString().toStdString(),
                object.value("house_number").toString().toStdString()
                );
}
