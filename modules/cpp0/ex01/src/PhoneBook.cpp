#include "PhoneBook.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook() { return; }

PhoneBook::~PhoneBook() { return; }

std::string PhoneBook::_trimBlank(std::string str) {
  std::string blank = " \t\n\r\v\f";
  size_t start;
  size_t end;

  start = str.find_first_not_of(blank);
  end = str.find_last_not_of(blank);
  if (start == std::string::npos) {
    return (std::string());
  }
  if (start == end) return (str);
  return (str.substr(start, end - start + 1));
}

bool PhoneBook::_isValidName(std::string input) {
  for (std::string::const_iterator it = input.begin(); it != input.end();
       ++it) {
    char c = *it;
    if (!std::isalpha(static_cast<unsigned char>(c)) && c != '-' && c != ' ') {
      std::cout << "Only latin latters, '-' and spaces are allowed. Try again."
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

  if (std::cin.eof()) exit(EXIT_SUCCESS);
  std::cout << "Please enter " << prompt << ":" << std::endl << "> ";
  while (true) {
    input.clear();
    if (!std::getline(std::cin, input)) {
      break;
    }
    input = PhoneBook::_trimBlank(input);
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
  PhoneBook::_index += 1;
  if (PhoneBook::_index == MAX_CONTACTS) {
    PhoneBook::_index = 0;
  }
  contact = &PhoneBook::_contactList[_index];
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

void PhoneBook::_printColumn(std::string str) {
  if (str.length() > 9) {
    str.resize(9);
    str.append(".");
  }
  std::cout << std::setw(10) << std::right << str << "|";
}

void PhoneBook::_displayContactTable(void) {
  int i = 0;
  Contact *contact;
  std::cout << "+----------+----------+----------+----------+" << std::endl
            << "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
            << "+----------+----------+----------+----------+" << std::endl;
  while (i < MAX_CONTACTS) {
    contact = &PhoneBook::_contactList[i];
    if (contact->isEmpty()) break;
    std::cout << "|";
    PhoneBook::_printColumn(std::string(1, (char)(i + '0')));
    PhoneBook::_printColumn(contact->getFirstName());
    PhoneBook::_printColumn(contact->getLastName());
    PhoneBook::_printColumn(contact->getNickname());
    std::cout << std::endl;
    i++;
  }
  std::cout << "+----------+----------+----------+----------+" << std::endl;
  std::cout << std::endl;
}

bool PhoneBook::_isValidIndex(std::string str, int &index) {
  std::stringstream ss(str);
  ss >> index;
  return (!ss.fail() && ss.eof() && (index >= 0 && index <= 7) &&
          !PhoneBook::_contactList[index].isEmpty());
}

void PhoneBook::_searchContactByIndex(void) {
  std::string index_str;
  int index_num;
  do {
    index_str =
        PhoneBook::_getInput("the valid index of the contact to display",
                             &PhoneBook::_isValidNumber);
  } while (!PhoneBook::_isValidIndex(index_str, index_num));
  std::cout << std::endl
            << "First Name: "
            << PhoneBook::_contactList[index_num].getFirstName() << std::endl;
  std::cout << "Last Name: " << PhoneBook::_contactList[index_num].getLastName()
            << std::endl;
  std::cout << "Nickname: " << PhoneBook::_contactList[index_num].getNickname()
            << std::endl;
  std::cout << "Phone Number: "
            << PhoneBook::_contactList[index_num].getPhoneNumber() << std::endl;
  std::cout << "Darkest Secret: "
            << PhoneBook::_contactList[index_num].getSecret() << std::endl;
  std::cout << std::endl;
}

void PhoneBook::searchContact(void) {
  std::cout << std::endl
            << "+-------------- Search Menu ----------------+" << std::endl
            << std::endl
            << std::endl;
  if (PhoneBook::_index == NO_CONTACTS) {
    std::cout << "No contacts in record. Please ADD a contact first."
              << std::endl;
    return;
  }
  PhoneBook::_displayContactTable();
  PhoneBook::_searchContactByIndex();
}
