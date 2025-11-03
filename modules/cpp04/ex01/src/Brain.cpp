#include "Brain.hpp"

#include <cmath>
#include <iostream>

static const std::string className = "Brain";

Brain::Brain() {
  std::cout << className << " Default Constructor is called" << std::endl;
  const std::string ideas[] = {"I am hungry",   "I want to play",
                               "I need to pee", "I want pets!",
                               "RAWRRRR",       "..."};
  for (int i = 0; i < NUM_IDEAS; i++)
    this->ideas[i] = ideas[(rand() + (long long)this) % 6];
}

Brain::Brain(const Brain& other) {
  for (int i = 0; i < NUM_IDEAS; i++) {
    this->ideas[i] = other.getIdea(i);
  }
  std::cout << className << " Copy Constructor is called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
  std::cout << className << " Copy Assignemnt is called" << std::endl;
  if (this == &other) return *this;
  for (int i = 0; i < NUM_IDEAS; i++) {
    this->ideas[i] = other.getIdea(i);
  }
  return *this;
}

Brain::~Brain() {
  std::cout << className << " Destructor is called" << std::endl;
}

const std::string& Brain::getIdea(unsigned int index) const {
  return this->ideas[index % 6];
}
