#include "Contact.hpp"

Contact::Contact(void)
    : _firstName(""),
      _lastName(""),
      _nickName(""),
      _phoneNumber(""),
      _darkestSecret("") {
  return;
}

Contact::~Contact(void) { return; }

void Contact::setFirstName(const std::string &input) {
  this->_firstName = input;
  return;
}
void Contact::setLastName(const std::string &input) {
  this->_lastName = input;
  return;
}
void Contact::setNickname(const std::string &input) {
  this->_nickName = input;
  return;
}
void Contact::setPhoneNumber(const std::string &input) {
  this->_phoneNumber = input;
  return;
}
void Contact::setDarkestSecret(const std::string &input) {
  this->_darkestSecret = input;
  return;
}
