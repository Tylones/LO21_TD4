#include "etat.h"
#include <stdexcept>
unsigned int Etat::getDimension() const
{
	return dimension;
}

bool Etat::getCellule(unsigned int n) const
{
	if(n > dimension - 1)
		throw std::out_of_range("Cellule hors du tableau");
	return tab[n];
}

void Etat::setCellule(unsigned int i, bool val)
{
	if(i > dimension - 1)
		throw std::out_of_range("Cellule hors du tableau");
	tab[i] = val;
}

Etat& Etat::operator=(const Etat &e)
{
	dimension = e.dimension;
	tab = new bool[dimension];
	for(int i = 0; i < dimension; i++)
		tab[i] = e.tab[i];
	return *this;
}

Etat::Etat(const Etat &e)
{
	this->dimension = e.dimension;
	this->tab = new bool(dimension);
	for(int i = 0; i < e.dimension; i++)
		this->tab[i] = e.tab[i];

}

Etat::Etat(unsigned int dim=0) : dimension(dim)
{
	tab = new bool(dimension);
	for(int i = 0; i < dimension; i++)
		tab[i] = false;
}

Etat::~Etat()
{
	delete tab;
}



std::ostream &operator<<(std::ostream &flux, Etat e)
{
	for(int i = 0; i < e.getDimension(); i++){
		if(e.getCellule(i))
			flux << "X";
		else
			flux << " ";
	}
	return flux;
}
