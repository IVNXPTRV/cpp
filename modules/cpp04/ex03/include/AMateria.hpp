#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
 public:
  AMateria();
  virtual ~AMateria();

  AMateria(std::string const& type);

  const std::string& getType() const;

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);

 protected:
  std::string _type;
  void setType(const std::string& type);
};

#endif
