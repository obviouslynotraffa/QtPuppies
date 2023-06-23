#ifndef JSONFILE_H
#define JSONFILE_H

#include "../converter/json/Json.h"
#include "Dog/boarding.h"
#include "Dog/breeding.h"
#include "Dog/owner.h"

class JsonFile{

private:
    std::string path;
    Json& converter;

public:
    JsonFile(const std::string& path, Json& converter);

    static JsonFile fromPath(const std::string& path);
    JsonFile& setPath(const std::string path);

    const Json& getConverter() const;
    const std::string& getPath() const;


    //JsonFile& store(const std::vector<Dog*> dogs);
    JsonFile& storeOwners(const std::vector<Owner*> owners);

    //std::vector<Dog*> loadDogs();
    std::vector<Owner*> loadOwners();

};


#endif
