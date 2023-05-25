#include "JsonVisitor.h"

#include <QJsonArray>

QJsonObject JsonVisitor::getObj()const{
    return object;
}


void JsonVisitor::visit(const Boarding &boarding){
    /*
    QJsonObject boardingObj;
    boardingObj.insert("type", QJsonValue::fromVariant("boarding"));
    boardingObj.insert("date", QJsonValue::fromVariant(boarding.getDate().toString().c_str));
    boardingObj.insert("name", QJsonValue::fromVariant(boarding.getName().c_str));
    boardingObj.insert("size", QJsonValue::fromVariant(boarding.getSize()->toString().c_str));
    */

}


void JsonVisitor::visit(const Breeding &breeding){

}


void JsonVisitor::visit(const Owner &owner){


}
