#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#define MAX_CONTACTS 8
#define NO_CONTACTS -1

class PhoneBook {
 public:
  PhoneBook(void);
  ~PhoneBook(void);

  static void addContact(void);
  static void searchContact(void);

 private:
  static int _count;
  static Contact _contactList[8];

  static std::string _getInput(std::string const prompt,
                               bool (*isValid)(std::string input));
  static bool _isValidName(std::string input);
  static bool _isValidNumber(std::string input);
  static std::string _trimBlank(std::string str);
};
#endif
