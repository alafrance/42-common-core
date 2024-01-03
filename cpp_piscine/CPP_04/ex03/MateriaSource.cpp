#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
/* CANONICAL FORM */
MateriaSource::MateriaSource(void){
	_materia = new AMateria*[4];
	for (int i = 0 ; i < 4 ; i++)
		_materia[i] = NULL;
}

MateriaSource::~MateriaSource(void){
	for (int i = 0 ; i < 4 ; i++)
		if (_materia[i])
			delete _materia[i];
	delete[] _materia;
}

MateriaSource::MateriaSource(MateriaSource const& src){
	*this = src;
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& rhs){
	for (int i = 0 ; i < 4 ; i++)
	{
		if (_materia[i])
			delete _materia[i];
		_materia[i] = rhs._materia[i]->clone();
	}
	return *this;
}
/* ACCESSORS */

/* MAIN */

void MateriaSource::learnMateria(AMateria* materia) {

	for (int i = 0 ; i < 4 ; i++)
		if (!_materia[i])
		{
			_materia[i] = materia;
			return ;
		}
}

AMateria*	MateriaSource::createMateria(std::string const &type) {
	for (int i = 0 ; i < 4 ; i++)
	{
		if (_materia[i] && type == _materia[i]->getType())
			return _materia[i]->clone();
	}
	return (NULL);
}