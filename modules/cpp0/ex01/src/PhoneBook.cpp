#include "PhoneBook.hpp"

#include <iostream>

PhoneBook::PhoneBook() { return; }

PhoneBook::~PhoneBook() { return; }

std::string PhoneBook::_trimBlank(std::string str) {
  std::string blank = " \t\n\r\v\f";
  size_t start;
  size_t end;

  start = str.find_first_not_of(blank);
  end = str.find_last_not_of(blank);
  if (start == std::string::npos) return (std::string());
  if (start == end) return (str);
  return (str.substr(start, end - start + 1));
}

bool PhoneBook::_isValidName(std::string input) {
  for (std::string::const_iterator it = input.begin(); it != input.end();
       ++it) {
    char c = *it;
    if (!std::isalpha(static_cast<unsigned char>(c)) && c != '-' && c != ' ') {
      std::cout << "Latin latters, '-' and spaces are allowed. Try again."
                << std::endl
                << "> ";
      return false;
    }
  }
  return true;
}

bool PhoneBook::_isValidNumber(std::string input) {
  for (std::string::const_iterator it = input.begin(); it != input.end();
       ++it) {
    char c = *it;
    if (!std::isdigit(static_cast<unsigned char>(c))) {
      std::cout << "Only digits are allowed. Try again." << std::endl << "> ";
      return false;
    }
  }
  return true;
}

std::string PhoneBook::_getInput(std::string const prompt,
                                 bool (*isValid)(std::string input)) {
  std::string input;

  std::cout << "Please enter " << prompt << ":" << std::endl << "> ";
  while (true) {
    input.clear();
    if (!std::getline(std::cin, input)) {
      std::cin.clear();
    }
    PhoneBook::_trimBlank(input);
    if (input.empty()) {
      std::cout << "Empty input is not allowed. Try again." << std::endl
                << "> ";
      continue;
    }
    if (isValid(input)) break;
  }
  return (input);
}

void PhoneBook::addContact(void) {
  Contact *contact;

  std::cout << "Don't use whitespaces, empty lines, other breaking characters "
               "or bad words. "
               "Please be nice."
            << std::endl;
  PhoneBook::_count += 1;
  contact = &PhoneBook::_contactList[_count % MAX_CONTACTS];
  contact->setFirstName(
      PhoneBook::_getInput("a first name", &PhoneBook::_isValidName));
  contact->setLastName(
      PhoneBook::_getInput("a last name", &PhoneBook::_isValidName));
  contact->setNickname(
      PhoneBook::_getInput("a nickname", &PhoneBook::_isValidName));
  contact->setPhoneNumber(
      PhoneBook::_getInput("a phone number", &PhoneBook::_isValidNumber));
  contact->setDarkestSecret(
      PhoneBook::_getInput("a darkest secret", &PhoneBook::_isValidName));
}

void PhoneBook::searchContact(void) {
  std::cout << std::endl
            << "+-------------- Search Menu ----------------+" << std::endl
            << std::endl;
  if (PhoneBook::_count == NO_CONTACTS) {
    std::cout << "No contacts in record. Please ADD a contact first."
              << std::endl;
    return;
  }
  PhoneBook::_displayContactTable();
  PhoneBook::_getInput("the index of the contact to display",
                       &PhoneBook::_isValidNumber);
}
