#include "vastustaja.h"
using namespace std;
Vastustaja::Vastustaja(wstring nimimerkki){
	this->nimimerkki = nimimerkki;
}

wstring Vastustaja::getNimimerkki(){
	return nimimerkki;
}