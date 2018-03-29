
#include "automate.h"
#include<cmath>

unsigned short Automate::getNumero() const
{
	return numero;
}

std::string Automate::getNumeroBit() const
{
	return numeroBit;
}

void Automate::appliquerTransition(const Etat &dep, Etat &dest) const
{

	for(unsigned int i = 0; i < dep.getDimension(); i++){
		int config_init = 0;

		if(i != 0)
			config_init += 4 * dep.getCellule(i-1);

		config_init += 2 * dep.getCellule(i);

		if(i < dep.getDimension() - 1)
			config_init += 1 * dep.getCellule(i+1);
		switch(config_init){
		case 0:
			dest.setCellule(i,(numero & 0b00000001) == 0b00000001);
			break;
		case 1:
			dest.setCellule(i,(numero & 0b00000010) == 0b00000010);
			break;
		case 2:
			dest.setCellule(i,(numero & 0b00000100) == 0b00000100);
			break;
		case 3:
			dest.setCellule(i,(numero & 0b00001000) == 0b00001000);
			break;
		case 4:
			dest.setCellule(i,(numero & 0b00010000) == 0b00010000);
			break;
		default:
			dest.setCellule(i,(numero & 0b00100000) == 0b00100000);
			break;
		}
	}
}

Automate::Automate()
{

}

Automate::Automate(unsigned short num) : numero(num)
{
	numeroBit = std::bitset< 8 >( num ).to_string();
	cout << numeroBit << endl;

}

Automate::Automate(string s) : numeroBit(s)
{
	numero = 0;
	numeroBit.at(0);
	for(int i = 7, j = 0; i >= 0; i--, j++){
		if(numeroBit.at(i)==49){
			numero+=pow(2,j);
		}
	}
	cout << "Automate : \n string : " << numeroBit << "\n numero : " << numero << endl;
}





ostream &operator<<(ostream &flux, Automate a)
{
	flux << a.getNumeroBit();
	return flux;
}
