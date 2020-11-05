#pragma once
#include "asema.h"
#include "siirto.h"
#include "nappula.h"
#include "peli.h"

class Kayttoliittyma{

public:

	void aseta_asema(Asema* asema) { this->asema = asema;  }
	Asema* asema;

	void piirraLauta();
	Siirto annaVastustajanSiirto();
	int kysyVastustajanVari();
	//Nappula annaSiirtynytNappula();

	static Kayttoliittyma* getInstance();
private:
	Kayttoliittyma() {}
	Kayttoliittyma(Asema* asema) { this->asema = asema; }

	Siirto siirto;
	std::wstring siirtoString;
	std::wstring siirtynytNappulaString;
	Ruutu *lahtoRuutu;

	static Kayttoliittyma* instance; // osoitin luokan ainoaan olioon
};