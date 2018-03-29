#ifndef ETAT_H
#define ETAT_H
#include <iostream>

class Etat
{
private:
	unsigned int dimension;
	bool* tab;
public:
	Etat(Etat const& e);
	Etat(unsigned int);
	~Etat();
	unsigned int getDimension() const;
	bool getCellule(unsigned int) const;
	void setCellule(unsigned int, bool);
	Etat& operator=(const Etat& e);

};

std::ostream& operator<<(std::ostream &flux, Etat e);


#endif // ETAT_H
