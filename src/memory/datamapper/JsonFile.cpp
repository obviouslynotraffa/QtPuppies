#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>
#include <iostream>
#include <QIODevice>
#include <QMessageBox>

#include "JsonFile.h"
#include "../converter/json/Reader.h"

JsonFile::JsonFile(const std::string path, Json &converter)
    : path(path), converter(converter)
{

}

JsonFile JsonFile::fromPath(const std::string &path){
    Reader reader;
    Json converter(reader);
    JsonFile data_mapper(path, converter);
    return data_mapper;
}

JsonFile& JsonFile::setPath(const std::string &path){
    this->path=path;
    return *this;
}

const Json& JsonFile::getConverter() const{
    return converter;
}


JsonFile& JsonFile::store(const std::vector<Dog*> dogs, const std::vector<Owner *> owners){

    QJsonArray json_data;


    for(auto it = owners.begin(); it!=owners.end();it++){
        json_data.push_back(converter.fromOwner(**it));
    }

    for(auto it = dogs.begin(); it!=dogs.end(); it++){
        json_data.push_back(converter.fromDog(**it));
    }

    QJsonDocument document(json_data);
    QFile json_file(path.c_str());
    if(json_file.open(QIODevice::WriteOnly))
    {
        json_file.write(document.toJson());
        json_file.close();
    }
    else
    {
        qCritical() << "Could not open file";
        qCritical() <<json_file.errorString();
    }

    return *this;
}




std::vector<Dog*> JsonFile::loadDogs(){
    std::vector<Dog*> dogs;

    QFile json_file(path.c_str());
    if(json_file.open(QIODevice::ReadOnly))
    {
        QByteArray data = json_file.readAll();
        json_file.close();
        QJsonDocument document = QJsonDocument::fromJson(data);
        QJsonArray json_data = document.array();

        for(const QJsonValue& value : json_data){

                QJsonObject json_object = value.toObject();
                QJsonValue type = json_object.value("type");

                if(type.toString().compare("boarding")==0 || type.toString().compare("breeding")==0)
                {
                    dogs.push_back(converter.toDogObject(json_object));

                }


        }
    }
    else
    {
        qCritical() << "Could not open file";
        qCritical() <<json_file.errorString();
    }


    return dogs;

}



std::vector<Owner*> JsonFile::loadOwners(){
    std::vector<Owner*> owners;

    QFile json_file(path.c_str());

    json_file.open(QIODevice::ReadOnly);
    QByteArray data = json_file.readAll();
    json_file.close();
    QJsonDocument document = QJsonDocument::fromJson(data);
    QJsonArray json_data = document.array();

    for(const QJsonValue& value : json_data){

            QJsonObject json_object = value.toObject();
            QJsonValue type = json_object.value("type");

            if(type.toString().compare("owner")==0)
            {
                owners.push_back(converter.toOwnerObject(json_object));
            }

    }

    return owners;

}
