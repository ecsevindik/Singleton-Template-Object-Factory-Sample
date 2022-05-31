#include <iostream>

#include "Dog.h"

Dog::Dog(const std::string& name)
: m_name(name) {}

void Dog::eat() {
    std::cout << "Dog " << m_name << " eats" << std::endl;
}

void Dog::sleep() {
    std::cout << "Dog " << m_name << " sleeps" << std::endl;
}