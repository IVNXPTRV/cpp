#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>

#include "Character.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  int _templatesSize;
  AMateria* _templates[MAX_SLOTS];

  void _deleteTemplates();
  void _copyTemplates(const MateriaSource& src);

 public:
  MateriaSource();
  MateriaSource(const MateriaSource& other);
  MateriaSource& operator=(const MateriaSource& other);
  virtual ~MateriaSource();

  virtual void learnMateria(AMateria*);
  virtual AMateria* createMateria(std::string const& type);
};

#endif
