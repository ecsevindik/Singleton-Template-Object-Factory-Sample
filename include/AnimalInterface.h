#ifndef ANIMALINTERFACE_H_
#define ANIMALINTERFACE_H_

#include <string>

#include "ObjectFactory.h"

struct AnimalInterface {
    virtual ~AnimalInterface() {}
    virtual void eat() = 0;
    virtual void sleep() = 0;
};

// Define object factory here
using CreateAnimal = AnimalInterface* (*)(const std::string&);

using AnimalFactory = ObjectFactory<AnimalInterface, std::string, CreateAnimal>;

#endif // ANIMALINTERFACE_H_