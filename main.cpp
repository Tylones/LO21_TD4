#include <iostream>
#include "automate.h"
#include "simulateur.h"
using namespace std;

int main()
{
	Automate a(30);
	std::cout<<"automate "<< a << std::endl;
	Etat e(22);
	e.setCellule(11,true);
	Simulateur s ((const Automate&) a,e, 6);
	cout << e << endl;
	for(int i = 0; i < 10; i++){
		s.next();
		cout << s.dernier() << endl;
	}
	return 0;
}
