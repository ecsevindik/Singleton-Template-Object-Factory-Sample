#ifndef DOG_H_
#define DOG_H_

#include "AnimalInterface.h"

class Dog : public AnimalInterface {
public:

    Dog(const std::string& name);
    ~Dog() = default;

    void eat() override;
    void sleep() override;

private:
    std::string m_name;
};

namespace {
    AnimalInterface* CreateDog(const std::string& name) {
        return new Dog(name);
    }

    const bool DOG_REGISTERED = AnimalFactory::Instance().Register("Dog", CreateDog);
}

#endif // DOG_H_