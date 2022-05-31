#include "AnimalInterface.h"

int main() {

    std::string dogName = "Karabas";
    auto animal_dog = AnimalFactory::Instance().CreateObject("Dog", dogName);

    animal_dog->eat();
    animal_dog->sleep();

    return 0;
}