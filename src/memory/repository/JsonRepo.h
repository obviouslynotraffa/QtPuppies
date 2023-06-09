#ifndef JSONREPO_H
#define JSONREPO_H


#include <QList>

#include "../converter/json/Json.h"
#include "../datamapper/JsonFile.h"
#include "Dog/dog.h"

class JsonRepo{
private:
    JsonFile dataMapper;
    std::vector<Dog*> dogs;
    std::vector<Owner*> owners;

public:
    JsonRepo(JsonFile dataMapper);
    ~JsonRepo();


    const JsonFile& getDataMapper() const;


    const std::vector<Dog*>& getRepoDog() const;
    const std::vector<Owner*>& getRepoOwner() const;


    static JsonRepo fromPath(const std::string path);
    JsonRepo& setPath(const std::string path);


    JsonRepo& create(Owner* owns);
    Owner* readOwner(std::string number) const;
    JsonRepo& removeOwner(Owner* ow);
    std::vector<Owner*> readAllOwners() const;


    JsonRepo& create(Dog* dog);
    Dog* readDog(std::string name) const;
    JsonRepo& removeDog(Dog* dog);
    std::vector<Dog*> readAllDogs() const;

    JsonRepo& store();

};

#endif
