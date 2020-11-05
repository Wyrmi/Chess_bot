#include <iostream>
#include "asema.h"
#include "nappula.h"
#include "ruutu.h"

Nappula* Asema::vk = new Kuningas(L"\u2654", 0, VK);
Nappula* Asema::vd = new Daami(L"\u2655", 0, VD);
Nappula* Asema::vt = new Torni(L"\u2656", 0, VT);
Nappula* Asema::vl = new Lahetti(L"\u2657", 0, VL);
Nappula* Asema::vr = new Ratsu(L"\u2658", 0, VR);
Nappula* Asema::vs = new Sotilas(L"\u2659", 0, VS);

Nappula* Asema::mk = new Kuningas(L"\u265A", 1, MK);
Nappula* Asema::md = new Daami(L"\u265B", 1, MD);
Nappula* Asema::mt = new Torni(L"\u265C", 1, MT);
Nappula* Asema::ml = new Lahetti(L"\u265D", 1, ML);
Nappula* Asema::mr = new Ratsu(L"\u265E", 1, MR);
Nappula* Asema::ms = new Sotilas(L"\u265F", 1, MS);

Asema::Asema(){
	// Ensin alustetaan kaikki laudan ruudut nappulla "NULL", koska muuten ruuduissa satunnaista tauhkaa
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			lauta[i][j] = NULL;
	// Asetetaan alkuaseman mukaisesti nappulat ruuduille
	lauta[0][0] = vt;
	lauta[1][0] = vr;
	lauta[2][0] = vl;
	lauta[3][0] = vd;
	lauta[4][0] = vk;
	lauta[5][0] = vl;
	lauta[6][0] = vr;
	lauta[7][0] = vt;

	lauta[0][1] = vs;
	lauta[1][1] = vs;
	lauta[2][1] = vs;
	lauta[3][1] = vs;
	lauta[4][1] = vs;
	lauta[5][1] = vs;
	lauta[6][1] = vs;
	lauta[7][1] = vs;

	lauta[0][7] = mt;
	lauta[1][7] = mr;
	lauta[2][7] = ml;
	lauta[3][7] = md;
	lauta[4][7] = mk;
	lauta[5][7] = ml;
	lauta[6][7] = mr;
	lauta[7][7] = mt;

	lauta[0][6] = ms;
	lauta[1][6] = ms;
	lauta[2][6] = ms;
	lauta[3][6] = ms;
	lauta[4][6] = ms;
	lauta[5][6] = ms;
	lauta[6][6] = ms;
	lauta[7][6] = ms;
	// Kunkun testausta varten
	/*lauta[7][5] = vk; 
	lauta[5][5] = mt;
	lauta[4][3] = ml;
	lauta[3][3] = vs;*/

	//lauta[4][4] = vr;

	siirtovuoro = 0;
	onkoValkeaKuningasLiikkunut = false;
	onkoMustaKuningasLiikkunut = false;
	onkoValkeaDTliikkunut = false;
	onkoValkeaKTliikkunut = false;
	onkoMustaDTliikkunut = false;
	onkoMustaKTliikkunut = false;

}
float Asema::evaluoi() {
	float ev = 0;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (lauta[i][j] != NULL) {
				switch (lauta[i][j]->getKoodi())
				{
				case VK:
				case MK:
					break;
				case MD:
					ev = ev - daamiEv;
					break;
				case VD:
					ev = ev + daamiEv;
					break;
				case MT:
					ev = ev - torniEv;
					break;
				case VT:
					ev = ev + torniEv;
					break;
				case ML:
					ev = ev - lahettiEv;
					break;
				case VL:
					ev = ev + lahettiEv;
					break;
				case VR:
					ev = ev + ratsuEv;
					break;
				case MR:
					ev = ev - ratsuEv;
					break;
				case VS:
					ev = ev + sotilasEv;
					break;
				case MS:
					ev = ev - sotilasEv;
					break;
				default:
					break;
				}
			}
		}
	}
	return ev;
}
void Asema::paivitaAsema(Siirto *siirto) {

	// Kaksoisaskel-lippu on oletusarvoisesti pois päältä.
	// Asetetaan myöhemmin, jos tarvii.
	this->kaksoisaskelSarakkeella = -1;

	//Tarkastetaan on siirto lyhyt linna
	if (siirto->onkoLyhytLinna()) {
		if (siirtovuoro == 0) {
			lauta[4][0] = NULL; // kuninkaan paikalle tyhjä
			lauta[6][0] = vk; // kuningas uudelle paikalle
			lauta[7][0] = NULL; // tornin paikalle tyhjä
			lauta[5][0] = vt; // torni uudella paikalle
		}
		if (siirtovuoro == 1) {
			lauta[4][7] = NULL; // kuninkaan paikalle tyhjä
			lauta[6][7] = vk; // kuningas uudelle paikalle
			lauta[7][7] = NULL; // tornin paikalle tyhjä
			lauta[5][7] = vt; // torni uudella paikalle
		}
	}

	// onko pitkä linna
	else if (siirto->onkoPitkälinna()) {
		if (siirtovuoro == 0) {
			lauta[4][0] = NULL; // kuninkaan paikalle tyhjä
			lauta[2][0] = vk; // kuningas uudelle paikalle
			lauta[0][0] = NULL; // tornin paikalle tyhjä
			lauta[3][0] = vt; // torni uudella paikalle
		}
		if (siirtovuoro == 1) {
			lauta[4][7] = NULL; // kuninkaan paikalle tyhjä
			lauta[2][7] = vk; // kuningas uudelle paikalle
			lauta[0][7] = NULL; // tornin paikalle tyhjä
			lauta[3][7] = vt; // torni uudella paikalle
		}

	}
	else {// Kaikki muut siirrot

		int alkuRiviInt;
		int alkuSarakeInt;
		int loppuRiviInt;
		int loppuSarakeInt;

		//Ottaa siirron alkuruudussa olleen nappulan talteen 
		alkuRiviInt = siirto->getAlkuruutu().getRivi();
		alkuSarakeInt = siirto->getAlkuruutu().getSarake();
		Nappula* nappula = lauta[alkuSarakeInt][alkuRiviInt];

		//Laittaa talteen otetun nappulan uuteen ruutuun
		loppuRiviInt = siirto->getLoppuruutu().getRivi();
		loppuSarakeInt = siirto->getLoppuruutu().getSarake();

		// Tarkistetaan oliko sotilaan kaksoisaskel
		// (asetetaan kaksoisaskel-lippu)
		if
		(
			(lauta[alkuSarakeInt][alkuRiviInt]->getKoodi() == VS || lauta[alkuSarakeInt][alkuRiviInt]->getKoodi() == MS) &&
			(alkuRiviInt - loppuRiviInt == 2 || alkuRiviInt - loppuRiviInt == -2)
		)
			kaksoisaskelSarakkeella = alkuSarakeInt;

		// Ohestalyönti on tyhjään ruutuun. Vieressä oleva (sotilas) poistetaan.
		if
		(
			(lauta[alkuSarakeInt][alkuRiviInt]->getKoodi() == VS || lauta[alkuSarakeInt][alkuRiviInt]->getKoodi() == MS) &&
			(alkuSarakeInt != loppuSarakeInt) &&
			(lauta[loppuSarakeInt][loppuRiviInt] == NULL)
		)
			lauta[loppuSarakeInt][alkuRiviInt] = NULL;

		//// Katsotaan jos nappula on sotilas ja rivi on päätyrivi niin ei vaihdeta nappulaa 
		////eli alkuruutuun laitetaan null ja loppuruudussa on jo kliittymän laittama nappula MIIKKA, ei taida minmaxin kanssa hehkua?
		//if ((nappula->getKoodi() == VS || nappula->getKoodi() == MS) && (loppuRiviInt == 0 || loppuRiviInt == 7)) {
		//	lauta[alkuSarakeInt][alkuRiviInt] = NULL;
		//}
		////muissa tapauksissa alkuruutuun null ja loppuruutuun sama alkuruudusta lähtenyt nappula
		//else {
		lauta[alkuSarakeInt][alkuRiviInt] = NULL;
		lauta[loppuSarakeInt][loppuRiviInt] = nappula;
		if (siirto->miksikorotetaan != NULL)
			lauta[loppuSarakeInt][loppuRiviInt] = siirto->miksikorotetaan;
//		}
		// katsotaan jos liikkunut nappula on kuningas niin muutetaan onkoKuningasLiikkunut arvo (molemmille väreille)
		if (nappula->getKoodi() == VK) {
			onkoValkeaKuningasLiikkunut = true;
		}
		if (nappula->getKoodi() == MK) {
			onkoMustaKuningasLiikkunut = true;
		}
		// katsotaan jos liikkunut nappula on torni niin muutetaan onkoTorniLiikkunut arvo (molemmille väreille ja molemmille torneille)
		if (nappula->getKoodi() == VT && alkuSarakeInt == 7 && alkuRiviInt == 0) {
			onkoValkeaKTliikkunut = true;
		}
		if (nappula->getKoodi() == VT && alkuSarakeInt == 0 && alkuRiviInt == 0) {
			onkoValkeaDTliikkunut = true;
		}
		if (nappula->getKoodi() == MT && alkuSarakeInt == 7 && alkuRiviInt == 7) {
			onkoMustaKTliikkunut = true;
		}
		if (nappula->getKoodi() == VT && alkuSarakeInt == 0 && alkuRiviInt == 7) {
			onkoMustaDTliikkunut = true;
		}

		//päivitetään siirtovuoro
		if (siirtovuoro == 0)
			siirtovuoro = 1;
		else
			siirtovuoro = 0;
	}
}
/*Nappula Asema::annaNappulaRuudusta(Ruutu *ruutu){
	int sarake = ruutu->getSarake();
	int rivi = ruutu->getRivi();
	return *lauta[rivi][sarake];
}*/

int Asema::getSiirtovuoro() {
	return this->siirtovuoro;
}
void Asema::setSiirtovuoro(int vuoro) {
	this->siirtovuoro = vuoro;
}

void Asema::annaLaillisetSiirrot(std::list<Siirto>& lista) {
	int vari = this->getSiirtovuoro();

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//Ei kysele tyhjiltä ruuduilta nappulan nimeä
			if (this->lauta[i][j] == NULL) {
				continue;
			}
			if (this->lauta[i][j]->getVari() != vari) {
				continue;
			}
			this->lauta[i][j]->annaSiirrot(lista, &Ruutu(i, j), this, vari); // myöhäinen sidonta!
		}
	}
}

bool Asema::onkoRuutuUhattu(Ruutu* ruutu, int vastustajanVari) {
	std::list<Siirto> vastustajaSiirrotLista;
	//Väreittäin käydään läpi kaikki ruudut ja niissä olevan nappulan siirrot kerätään vastustajan siirtolistaan
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->lauta[i][j] == NULL) {
				continue;
			}
			if (this->lauta[i][j]->getVari() == vastustajanVari)
				this->lauta[i][j]->annaSiirrot(vastustajaSiirrotLista, &Ruutu(i, j), this, vastustajanVari); // myöh.sidonta
		}
	}
	// Käydään vastustajaSiirtoLista läpi ja jos sieltä löytyy tarkasteltava ruutu niin tiedetään sen olevan uhattu
	bool ruutuOk = true;
	for (auto s : vastustajaSiirrotLista)
	{
		if (ruutu->getSarake() == s.getLoppuruutu().getSarake() && ruutu->getRivi() == s.getLoppuruutu().getRivi()) {
			ruutuOk = false;
			break;
		}
	}
	return ruutuOk;
}

MinMaxPaluu Asema::maxi(int syvyys) {
	std::list<Siirto> lista;
	Ruutu kuninkaanRuutu;
	this->annaLaillisetSiirrot(lista);
	double arvo;
	Asema uusiAsema;
	Siirto parasSiirto;
	MinMaxPaluu paluu;
	// Tarkasta onko matti tai patti, jos on niin poistu asap, matti -100000, patti 0
	if (lista.size() == 0) {
		//selvitä kuninkaan ruutu
		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				if (this->lauta[x][y] != NULL) {
					if (this->lauta[x][y]->getKoodi() == VK) {
						kuninkaanRuutu.setSarake(x);
						kuninkaanRuutu.setRivi(y);
					}
				}
			}
		}
		//matti
		if (this->onkoRuutuUhattu(&kuninkaanRuutu, 1)) {
			paluu.evaluointiArvo = -1000000;
			return paluu;
		}
		//patti
		if (!this->onkoRuutuUhattu(&kuninkaanRuutu, 1)) {
			paluu.evaluointiArvo = 0;
			return paluu;
		}
	}
	// Jos ei ole matti tai patti niin käy pelipuuta läpi rekursiivisesti
	if (syvyys == 0) { // rekursion kanta
		paluu.evaluointiArvo = this->evaluoi();
		return 	paluu;
	}
	double maximi = -100000; // iso arvo jotta varmasti paranee
	for (auto s : lista) {
		uusiAsema = *this;
		uusiAsema.paivitaAsema(&s);
		arvo = uusiAsema.mini(syvyys - 1).evaluointiArvo;
		if (arvo > maximi) {
			maximi = arvo;
			parasSiirto = s;
		}
	}
	paluu.evaluointiArvo = maximi;
	paluu.parasSiirto = parasSiirto;
	return paluu;
}
MinMaxPaluu Asema::mini(int syvyys) {
	std::list<Siirto> lista;
	Ruutu kuninkaanRuutu;
	this->annaLaillisetSiirrot(lista);
	double arvo;
	Asema uusiAsema;
	Siirto parasSiirto;
	MinMaxPaluu paluu;
	// Tarkasta onko matti tai patti, jos on niin poistu asap, matti -100000, patti 0
	if (lista.size() == 0) {
		//selvitä kuninkaan ruutu
		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				if (this->lauta[x][y] != NULL) {
					if (this->lauta[x][y]->getKoodi() == MK) {
						kuninkaanRuutu.setSarake(x);
						kuninkaanRuutu.setRivi(y);
					}
				}
			}
		}
		//matti
		if (this->onkoRuutuUhattu(&kuninkaanRuutu, 0)) {
			paluu.evaluointiArvo = 1000000;
			return paluu;
		}
		//patti
		if (!this->onkoRuutuUhattu(&kuninkaanRuutu, 0)) {
			paluu.evaluointiArvo = 0;
			return paluu;
		}
	}
	// Jos ei ole matti tai patti niin käy pelipuuta läpi rekursiivisesti
	if (syvyys == 0) { // rekursion kanta
		paluu.evaluointiArvo = this->evaluoi();
		//paluu.parasSiirto = MITÄ
		return 	paluu;
	}
	double minimi = 100000; // iso arvo jotta varmasti paranee
	for (auto s : lista) {
		uusiAsema = *this;
		uusiAsema.paivitaAsema(&s);
		arvo = uusiAsema.maxi(syvyys - 1).evaluointiArvo;
		if (arvo < minimi) {
			minimi = arvo;
			parasSiirto = s;
		}
	}
	paluu.evaluointiArvo = minimi;
	paluu.parasSiirto = parasSiirto;
	return paluu;
}