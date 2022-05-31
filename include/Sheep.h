#ifndef SHEEP_H_
#define SHEEP_H_

#include "AnimalInterface.h"

class Sheep : public AnimalInterface {

public:
    Sheep(const std::string& name);
    ~Sheep() = default;

    void eat() override;
    void sleep() override;

private:
    std::string m_name;
};

namespace {
    AnimalInterface* CreateSheep(const std::string& name) {
        return new Sheep(name);
    }

    const bool SHEEP_REGISTERED = AnimalFactory::Instance().Register("Sheep", CreateSheep);
}

#endif // SHEEP_H_