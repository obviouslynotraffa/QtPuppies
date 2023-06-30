#include "JsonVisitor.h"



QJsonObject JsonVisitor::getObject()const {
    return object;
}


void JsonVisitor::visitBoarding(Boarding &boarding){

    QJsonObject boardingObject;

    boardingObject.insert("type", QJsonValue::fromVariant("boarding"));
    boardingObject.insert("day", QJsonValue::fromVariant(boarding.getDate().getDay()));
    boardingObject.insert("month", QJsonValue::fromVariant(boarding.getDate().getMonth()));
    boardingObject.insert("year", QJsonValue::fromVariant(boarding.getDate().getYear()));
    boardingObject.insert("name", QJsonValue::fromVariant(boarding.getName().c_str()));
    boardingObject.insert("size", QJsonValue::fromVariant(boarding.getSize()->toString().c_str()));
    boardingObject.insert("owner", QJsonValue::fromVariant(boarding.getOwner()->getPhone().c_str()));
    boardingObject.insert("breed", QJsonValue::fromVariant(boarding.getBreed().c_str()));
    boardingObject.insert("bath", QJsonValue::fromVariant(boarding.didBath()));
    boardingObject.insert("training", QJsonValue::fromVariant(boarding.didTraining()));
    boardingObject.insert("diet", QJsonValue::fromVariant(boarding.didDiet()));
    boardingObject.insert("walking", QJsonValue::fromVariant(boarding.didWalking()));

    object = boardingObject;
}


void JsonVisitor::visitBreeding(Breeding &breeding){

    QJsonObject breedingObject;
    breedingObject.insert("type", QJsonValue::fromVariant("breeding"));
    breedingObject.insert("day", QJsonValue::fromVariant(breeding.getDate().getDay()));
    breedingObject.insert("month", QJsonValue::fromVariant(breeding.getDate().getMonth()));
    breedingObject.insert("year", QJsonValue::fromVariant(breeding.getDate().getYear()));
    breedingObject.insert("name", QJsonValue::fromVariant(breeding.getName().c_str()));
    breedingObject.insert("breed", QJsonValue::fromVariant(breeding.getBreed()->toString().c_str()));
    breedingObject.insert("vax", QJsonValue::fromVariant(breeding.isVax()));
    breedingObject.insert("purch", QJsonValue::fromVariant(breeding.isPurchasable()));
    breedingObject.insert("booked", QJsonValue::fromVariant(breeding.isBooked()));

    if(breeding.getMother() && breeding.getFather())
    {
        breedingObject.insert("mother",QJsonValue::fromVariant(breeding.getMother()->getName().c_str()));
        breedingObject.insert("father",QJsonValue::fromVariant(breeding.getFather()->getName().c_str()));
    }
    else
    {
        breedingObject.insert("mother",QJsonValue::fromVariant(""));
        breedingObject.insert("father",QJsonValue::fromVariant(""));
    }



    object = breedingObject;

}
