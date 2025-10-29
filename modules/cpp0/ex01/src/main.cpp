#include <stdlib.h>

#include <iostream>

#include "PhoneBook.hpp"

bool getInput(std::string& input) {
  std::cout << "Type your command: ADD, SEARCH or EXIT." << std::endl << "> ";
  if (!std::getline(std::cin, input) || input == "EXIT") {
    return (false);
  } else
    return (true);
}

void parseInput(std::string& input) {
  if (input == "ADD") {
    PhoneBook::addContact();
  } else if (input == "SEARCH") {
    PhoneBook::searchContact();
  } else
    std::cout << "Valid commands: ADD, SEARCH, EXIT. Try again." << std::endl;
  return;
}

void runLoop(void) {
  std::string input;

  while (getInput(input)) {
    parseInput(input);
  }

  return;
}

void printWelcomeMessage(void) {
  std::cout << "Welcome to the PhoneBook!" << std::endl;

  return;
}

void printFarewellMessage(void) {
  std::cout << "Thank you for using the PhoneBook. Come again soon!"
            << std::endl;
  return;
}

int PhoneBook::_count = NO_CONTACTS;
Contact PhoneBook::_contactList[MAX_CONTACTS];

int runPhoneBook(void) {
  PhoneBook phoneBook;

  printWelcomeMessage();
  runLoop();
  printFarewellMessage();
  return (EXIT_SUCCESS);
}

int main(void) { return (runPhoneBook()); }
