#ifndef SIMULATEUR_H
#define SIMULATEUR_H
#include "automate.h"
#include "etat.h"

class Simulateur
{
private:
	const Automate& automate;
	const Etat* depart = nullptr;
	Etat** etats = nullptr;
	int nbMaxEtats;
	int rang;
public:
	Simulateur(const Automate& a, unsigned int buf = 2);
	Simulateur(const Automate &a, const Etat& e ,unsigned int buf = 2);
	~Simulateur();
	void next();
	void run(unsigned int nb);
	void reset();
	const Etat& dernier();
	unsigned int getRangDernier();

};

#endif // SIMULATEUR_H
