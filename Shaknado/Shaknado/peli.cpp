#include "peli.h"
using namespace std;
Peli::Peli(int ihmisenVari){
	if (ihmisenVari == 0) {
		koneenVari = 1;
	}
	else {
		koneenVari = 0;
	}
}

int Peli::getKoneenVari(){
	return koneenVari;
}