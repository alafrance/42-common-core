#ifndef MateriaSource_HPP
#define MateriaSource_HPP
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(MateriaSource const& src);
	virtual ~MateriaSource();
	virtual void		learnMateria(AMateria*);
	virtual AMateria*	createMateria(std::string const &type);
	MateriaSource& operator=(MateriaSource const& rhs);
private:
	AMateria	**_materia;
};

#endif