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

void Contact::setFirstName(const std::string& input) {
  this->_firstName = input;
  return;
}
void Contact::setLastName(const std::string& input) {
  this->_lastName = input;
  return;
}
void Contact::setNickname(const std::string& input) {
  this->_nickName = input;
  return;
}
void Contact::setPhoneNumber(const std::string& input) {
  this->_phoneNumber = input;
  return;
}
void Contact::setDarkestSecret(const std::string& input) {
  this->_darkestSecret = input;
  return;
}

bool Contact::isEmpty(void) const {
  if (this->_firstName.empty() || this->_lastName.empty() ||
      this->_nickName.empty() || this->_phoneNumber.empty() ||
      this->_darkestSecret.empty())
    return (true);
  return (false);
}

const std::string& Contact::getFirstName() const { return (this->_firstName); }

const std::string& Contact::getLastName() const { return (this->_lastName); };

const std::string& Contact::getNickname() const { return (this->_nickName); }

const std::string& Contact::getPhoneNumber() const {
  return (this->_phoneNumber);
}

const std::string& Contact::getSecret() const { return (this->_darkestSecret); }
