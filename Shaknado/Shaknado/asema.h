#pragma once
#include <list>
#include <string>
#include "siirto.h"

class Nappula;

class MinMaxPaluu {
public:
	float evaluointiArvo;
	Siirto parasSiirto;
};

class Asema{

public:
	//Konstruktori luo alkuaseman laudalle
	//Valkea väri = 0, musta väri = 1
	Asema();
	Nappula* lauta[8][8];
	static Nappula* vk;
	static Nappula* vd;
	static Nappula* vt;
	static Nappula* vl;
	static Nappula* vr;
	static Nappula* vs;

	static Nappula* mk;
	static Nappula* md;
	static Nappula* mt;
	static Nappula* ml;
	static Nappula* mr;
	static Nappula* ms;


	void paivitaAsema(Siirto*);
	void annaLaillisetSiirrot(std::list<Siirto>& lista);
	int getSiirtovuoro();
	void setSiirtovuoro(int);
	int kaksoisaskelSarakkeella = -1;
	float evaluoi();

	MinMaxPaluu maxi(int syvyys);
	MinMaxPaluu mini(int syvyys);

	
private:

	float daamiEv = 9;
	float torniEv = 5;
	float lahettiEv = 3.25;
	float ratsuEv = 3;
	float sotilasEv = 1;
	int siirtovuoro;
	bool onkoRuutuUhattu(Ruutu*, int vastustajanVari);
	bool onkoValkeaKuningasLiikkunut;
	bool onkoMustaKuningasLiikkunut;
	bool onkoValkeaDTliikkunut;
	bool onkoValkeaKTliikkunut;
	bool onkoMustaDTliikkunut;
	bool onkoMustaKTliikkunut;
};