#ifndef AUTOMATE_H
#define AUTOMATE_H
#include <string>
#include <bitset>
#include <iostream>
#include "etat.h"

using namespace std;

class Automate
{
private:
	short unsigned int numero;
	std::string numeroBit;
public:
	Automate();
	Automate(short unsigned int num);
	Automate(string s);
	unsigned short getNumero() const;
	std::string getNumeroBit() const;
	void appliquerTransition(const Etat& dep, Etat& dest) const;
};


std::ostream &operator<<(std::ostream &flux, Automate a);
#endif // AUTOMATE_H
