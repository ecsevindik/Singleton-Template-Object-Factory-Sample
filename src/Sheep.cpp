#include <iostream>

#include "Sheep.h"

Sheep::Sheep(const std::string& name)
: m_name(name) {}

void Sheep::eat() {
    std::cout << "Sheep " << m_name << " eats" << std::endl;
}

void Sheep::sleep() {
    std::cout << "Sheep " << m_name << " sleeps" << std::endl;
}