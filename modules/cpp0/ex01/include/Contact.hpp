#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
 public:
  Contact(void);
  ~Contact(void);

  void setFirstName(const std::string &input);
  void setLastName(const std::string &input);
  void setNickname(const std::string &input);
  void setPhoneNumber(const std::string &input);
  void setDarkestSecret(const std::string &input);

  const std::string &getFirstName() const;
  const std::string &getLastName() const;
  const std::string &getNickname() const;
  const std::string &getPhoneNumber() const;
  const std::string &getSecret() const;

 private:
  std::string _firstName;
  std::string _lastName;
  std::string _nickName;
  std::string _phoneNumber;
  std::string _darkestSecret;
};
#endif
