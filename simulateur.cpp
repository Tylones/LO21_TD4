#include "simulateur.h"



Simulateur::Simulateur(const Automate &a, unsigned int buf) : automate(a), nbMaxEtats(buf), rang(0)
{
	etats = new Etat*[nbMaxEtats];
	etats[0] = new Etat(10);
}

Simulateur::Simulateur(const Automate &a, const Etat& e, unsigned int buf) : automate(a), nbMaxEtats(buf), rang(0)
{
	depart = &e;
	etats = new Etat*[buf];
	for(int i = 0; i < buf; i++)
		etats[i] = new Etat(e.getDimension());
	reset();

}

Simulateur::~Simulateur()
{
	for(int i = 0; i < nbMaxEtats; i++)
		delete etats[i];
	delete etats;
}

void Simulateur::next()
{
	if(etats[(rang+1)%nbMaxEtats] == NULL)
		etats[(rang+1)%nbMaxEtats] = new Etat(etats[(rang)%nbMaxEtats]->getDimension());
	automate.appliquerTransition(*etats[rang%nbMaxEtats],*etats[(rang+1)%nbMaxEtats]);
	rang++;
}

void Simulateur::run(unsigned int nb)
{
	for(int i = 0; i < nb; i++)
		next();
}

void Simulateur::reset()
{
	rang = 0;
	*etats[0] = *depart;

}

const Etat &Simulateur::dernier()
{
	return *etats[(rang%nbMaxEtats)];
}

unsigned int Simulateur::getRangDernier()
{
	return rang;
}
