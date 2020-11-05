#pragma once
#include <list>
#include <string>
#include "asema.h"
#include "Siirto.h"

// Vakioarvot nappulatyypeille.
enum
{
	VT,VR,VL,VD,VK,VS,
	MT,MR,ML,MD,MK,MS
};


class Nappula{

private:
	std::wstring unicode;
	int vari; // valkea = 0, musta = 1
	int _koodi; // VT, VR, MT tms.
public:
	Nappula(std::wstring, int, int);
	Nappula(){};

	virtual void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari) = 0; // virtual jotta myˆh‰inen sidonta k‰ytˆss‰


//	void setNimi(std::wstring);
//	std::wstring getNimi();
	void setUnicode(std::wstring unicode) { this->unicode = unicode; }
	std::wstring getUnicode();
	void setVari(int vari) { this->vari = vari; }
	int getVari();
	int getKoodi();
	void setKoodi(int koodi) { _koodi = koodi;  }
};

class Torni : public virtual Nappula { // virtual = kantaluokka perit‰‰n moniperinn‰ss‰ vain kerran!
public:
	Torni(std::wstring unicode, int vari, int koodi) : Nappula(unicode, vari, koodi) {} // alustuslista (yliluokan alustus)
	void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari);
};

class Ratsu : public Nappula {
public:
	Ratsu(std::wstring unicode, int vari, int koodi) : Nappula(unicode, vari, koodi) {}
	void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari);
};

class Lahetti : public virtual Nappula { // virtual = kantaluokka perit‰‰n moniperinn‰ss‰ vain kerran!
public:
	Lahetti(std::wstring unicode, int vari, int koodi) : Nappula(unicode, vari, koodi) {}
	void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari);
};

class Daami : public Lahetti, public Torni { // Moniperint‰!
public:
	Daami(std::wstring unicode, int vari, int koodi) : Nappula(unicode, vari, koodi), Lahetti(unicode, vari, koodi), Torni(unicode, vari, koodi) {
		//setUnicode(unicode);
		//setVari(vari);
		//setKoodi(koodi);
	}
	void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari);
};

class Kuningas : public Nappula {
public:
	Kuningas(std::wstring unicode, int vari, int koodi) : Nappula(unicode, vari, koodi) {}
	void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari);
};

class Sotilas : public Nappula {
public:
	Sotilas(std::wstring unicode, int vari, int koodi) : Nappula(unicode, vari, koodi) {}
	void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari);
private:
	void lisaaSotilaanKorotukset(Siirto*, std::list<Siirto>& lista, Asema*);
};


