#ifndef JSONREPO_H
#define JSONREPO_H


#include <QList>

#include "../converter/json/Json.h"
#include "../datamapper/JsonFile.h"
#include "Dog/dog.h"

class JsonRepo{
private:
    JsonFile dataMapper;
    //std::vector<Dog*> dogs;
    std::vector<Owner*> owners;

public:
    JsonRepo(JsonFile dataMapper);

    static JsonRepo fromPath(const std::string path);
    const JsonFile& getDataMapper() const;
    //const std::vector<Dog*>& getRepoDog() const;
    const std::vector<Owner*>& getRepoOwner() const;
    const std::string& getPath() const;
    JsonRepo& setPath(const std::string path);


    JsonRepo& create(Owner* owns);
    Owner* read(std::string number) const;
    JsonRepo& update(Owner* owner);
    JsonRepo& remove(std::string number);
    std::vector<Owner*> readAll() const;
    JsonRepo& store();

};

#endif
