#include "AnimalInterface.h"

int main() {

    std::string dogName = "Karabas";
    auto animalDog = AnimalFactory::Instance().CreateObject("Dog", dogName);

    animalDog->eat();
    animalDog->sleep();

    std::string sheepName = "Dolly";
    auto animalSheep = AnimalFactory::Instance().CreateObject("Sheep", sheepName);

    animalSheep->sleep();
    animalSheep->eat();

    return 0;
}