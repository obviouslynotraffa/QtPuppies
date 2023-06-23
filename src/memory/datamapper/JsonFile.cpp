#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>
#include <iostream>

#include "JsonFile.h"
#include "../converter/json/Reader.h"


JsonFile::JsonFile(const std::string &path, Json &converter)
    : path(path), converter(converter)
{
}


JsonFile JsonFile::fromPath(const std::string &path){
    Reader reader;
    Json converter(reader);
    JsonFile data_mapper(path, converter);
    return data_mapper;
}


JsonFile& JsonFile::setPath(const std::string path){
    this->path=path;
    return *this;
}


const std::string& JsonFile::getPath() const{
    return path;
}


const Json& JsonFile::getConverter() const{
    return converter;
}


/*
JsonFile& JsonFile::storeDogs(const std::vector<Dog *> dogs){
    QJsonArray json_items;

    for( auto it=dogs.begin(); it!=dogs.end(); it++)
    {
        json_items.push_back(converter.fromObject(**dogs));
    }

    QJsonDocument document(json_items);
    QFile json_file(path.c_str());
    json_file.open(QFile::WriteOnly);
    json_file.write(document.toJson());
    json_file.close();
    return *this;
}
*/

JsonFile& JsonFile::storeOwners(const std::vector<Owner*> owners){
    QJsonArray json_items;

    for( auto it=owners.begin(); it!=owners.end(); it++)
    {
        json_items.push_back(converter.fromObject(**it));
    }

    QJsonDocument document(json_items);
    QFile json_file(path.c_str());
    json_file.open(QFile::WriteOnly);
    json_file.write(document.toJson());
    json_file.close();
    return *this;
}

/*

std::vector<Dogs*> JsonFile::loadDogs(){

    std::vector<Dogs*> dogs;
    QFile json_file(path.c_str());
    json_file.open(QFile::ReadOnly);
    QByteArray data = json_file.readAll();
    json_file.close();
    QJsonDocument document= QJsonDocument::fromJson(data);
    QJsonArray json_items=document.array();

    for(const QJsonValue& value: json_items){
        QJsonObject json_object = value.toObject();
        dogs.push_back(converter.toDogObject(json_object));
    }
    return dogs;
}
*/


std::vector<Owner*> JsonFile::loadOwners(){

    std::vector<Owner*> owners;
    QFile json_file(path.c_str());
    json_file.open(QFile::ReadOnly);
    QByteArray data = json_file.readAll();
    json_file.close();
    QJsonDocument document= QJsonDocument::fromJson(data);
    QJsonArray json_items=document.array();

    for(const QJsonValue& value: json_items){
        QJsonObject json_object = value.toObject();
        owners.push_back(converter.toOwnerObject(json_object));
    }
    return owners;
}

