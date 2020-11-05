#pragma once
#include "ruutu.h"

class Nappula;

class Siirto{
public:
	Siirto(Ruutu, Ruutu);
	Siirto(){}
	Siirto(bool, bool); // Poikkeus siirto linnoitusta varten
	Ruutu getAlkuruutu();
	Ruutu getLoppuruutu();
	bool onkoLyhytLinna();
	bool onkoPitkälinna();
	Nappula* miksikorotetaan = 0; 

private:
	Ruutu alkuRuutu;
	Ruutu loppuRuutu;

	bool lyhytLinna;
	bool pitkalinna;
};