#include <list>
#include <string>
#include "asema.h"
#include "nappula.h"


using namespace std;

Nappula::Nappula(wstring unicode, int vari, int koodi){
//	this->nimi = nimi;
	this->unicode = unicode;
	this->vari = vari;
	this->_koodi = koodi;
}

//wstring Nappula::getNimi(){
//	return nimi;
//}
wstring Nappula::getUnicode(){
	return unicode;
}
int Nappula::getVari(){
	return vari;
}

int Nappula::getKoodi() {
	return _koodi;
}


void Torni::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	int lahtoruutuY = ruutu->getRivi();
	int lahtoruutuX = ruutu->getSarake();

	int lahtoruudunNappulanVari;
	int tuloruudunNappulanVari;

	lahtoruudunNappulanVari = asema->lauta[lahtoruutuX][lahtoruutuY]->getVari();
	// vaakarivi ruudusta eteenp‰in
	for (int i = lahtoruutuX + 1; i < 8; i++) {
		// Jos tyhj‰ ruutu niin lis‰t‰‰n listaan
		if (asema->lauta[i][lahtoruutuY] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(i, lahtoruutuY)));
		}
		else if (asema->lauta[i][lahtoruutuY] != NULL) {
			// Jos oma nappula niin poistutaan for silmukasta. Ei lis‰t‰ listaan
			// Tarkistetaan ett‰ jos l‰htˆruudussa olevan nappulan v‰ri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
			tuloruudunNappulanVari = asema->lauta[i][lahtoruutuY]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
				break;
			}
			// jos vastujan nappula niin poistutaan for silmukasta. Lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(i, lahtoruutuY)));
				break;
			}
		}
	}
	// vaakarivi ruudusta taaksep‰in
	for (int i = lahtoruutuX - 1; i >= 0; i--) {
		// Jos tyhj‰ ruutu niin lis‰t‰‰n listaan
		if (asema->lauta[i][lahtoruutuY] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(i, lahtoruutuY)));
		}
		else if (asema->lauta[i][lahtoruutuY] != NULL) {
			// Jos oma nappula niin poistutaan for silmukasta. Ei lis‰t‰ listaan
			// Tarkistetaan ett‰ jos l‰htˆruudussa olevan nappulan v‰ri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
			tuloruudunNappulanVari = asema->lauta[i][lahtoruutuY]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
				break;
			}
			// jos vastujan nappula niin poistutaan for silmukasta. Lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(i, lahtoruutuY)));
				break;
			}
		}
	}
	// pystyrivi ruudusta eteenp‰in
	for (int i = lahtoruutuY + 1; i < 8; i++) {
		// Jos tyhj‰ ruutu niin lis‰t‰‰n listaan
		if (asema->lauta[lahtoruutuX][i] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX, i)));
		}
		else if (asema->lauta[lahtoruutuX][i] != NULL) {
			// Jos oma nappula niin poistutaan for silmukasta. Ei lis‰t‰ listaan
			// Tarkistetaan ett‰ jos l‰htˆruudussa olevan nappulan v‰ri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX][i]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
				break;
			}
			// jos vastujan nappula niin poistutaan for silmukasta. Lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX, i)));
				break;
			}
		}
	}
	// pystyrivi ruudusta taaksep‰in
	for (int i = lahtoruutuY - 1; i >= 0; i--) {
		// Jos tyhj‰ ruutu niin lis‰t‰‰n listaan
		if (asema->lauta[lahtoruutuX][i] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX, i)));
		}
		else if (asema->lauta[lahtoruutuX][i] != NULL) {
			// Jos oma nappula niin poistutaan for silmukasta. Ei lis‰t‰ listaan
			// Tarkistetaan ett‰ jos l‰htˆruudussa olevan nappulan v‰ri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX][i]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
				break;
			}
			// jos vastujan nappula niin poistutaan for silmukasta. Lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX, i)));
				break;
			}
		}
	}
	// testausta varten
	// Huom. uuden standardin mukaista c++ koodia, auto-m‰‰re antaa k‰‰nt‰j‰n p‰‰tell‰ luokan, k‰ytt‰‰ iteraattoreita
	/*for (auto s : lista)
	{
	std::wcout << L"Torni";
	std::wcout << s.getAlkuruutu().getSarake();
	std::wcout << s.getAlkuruutu().getRivi() << "-";

	std::wcout << s.getLoppuruutu().getSarake();
	std::wcout << s.getLoppuruutu().getRivi() << "\n";
	}*/
}

void Ratsu::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	int lahtoruutuY = ruutu->getRivi();
	int lahtoruutuX = ruutu->getSarake();

	int lahtoruudunNappulanVari;
	int tuloruudunNappulanVari;

	lahtoruudunNappulanVari = asema->lauta[lahtoruutuX][lahtoruutuY]->getVari();

	// Pit‰‰ huomioida ett‰ kokeiltavat ruudut ovat viel‰ laudalla
	if (lahtoruutuX + 1 < 8 && lahtoruutuY + 2 < 8) {
		if (asema->lauta[lahtoruutuX + 1][lahtoruutuY + 2] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY + 2)));
		}
		else if (asema->lauta[lahtoruutuX + 1][lahtoruutuY + 2] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX + 1][lahtoruutuY + 2]->getVari();
			// jos oman v‰rinen niin lis‰t‰‰n tˆrmayslistaan
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
			}
			// jos vastujan nappula niin lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY + 2)));
			}
		}
	}
	if (lahtoruutuX + 1 < 8 && lahtoruutuY - 2 >= 0) {
		if (asema->lauta[lahtoruutuX + 1][lahtoruutuY - 2] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY - 2)));
		}
		else if (asema->lauta[lahtoruutuX + 1][lahtoruutuY - 2] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX + 1][lahtoruutuY - 2]->getVari();
			// jos oman v‰rinen niin lis‰t‰‰n tˆrmayslistaan
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
			}
			// jos vastujan nappula niin lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY - 2)));
			}
		}
	}
	if (lahtoruutuX - 1 >= 0 && lahtoruutuY + 2 < 8) {
		if (asema->lauta[lahtoruutuX - 1][lahtoruutuY + 2] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 1, lahtoruutuY + 2)));
		}
		else if (asema->lauta[lahtoruutuX - 1][lahtoruutuY + 2] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX - 1][lahtoruutuY + 2]->getVari();
			// jos oman v‰rinen niin lis‰t‰‰n tˆrmayslistaan
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
			}
			// jos vastujan nappula niin lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 1, lahtoruutuY + 2)));
			}
		}
	}
	if (lahtoruutuX - 1 >= 0 && lahtoruutuY - 2 >= 0) {
		if (asema->lauta[lahtoruutuX - 1][lahtoruutuY - 2] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 1, lahtoruutuY - 2)));
		}
		else if (asema->lauta[lahtoruutuX - 1][lahtoruutuY - 2] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX - 1][lahtoruutuY - 2]->getVari();
			// jos oman v‰rinen niin lis‰t‰‰n tˆrmayslistaan
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
			}
			// jos vastujan nappula niin lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 1, lahtoruutuY - 2)));
			}
		}
	}
	if (lahtoruutuX + 2 < 8 && lahtoruutuY + 1 < 8) {
		if (asema->lauta[lahtoruutuX + 2][lahtoruutuY + 1] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 2, lahtoruutuY + 1)));
		}
		else if (asema->lauta[lahtoruutuX + 2][lahtoruutuY + 1] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX + 2][lahtoruutuY + 1]->getVari();
			// jos oman v‰rinen niin lis‰t‰‰n tˆrmayslistaan
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
			}
			// jos vastujan nappula niin lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 2, lahtoruutuY + 1)));
			}
		}
	}
	if (lahtoruutuX + 2 < 8 && lahtoruutuY - 1 >= 0) {
		if (asema->lauta[lahtoruutuX + 2][lahtoruutuY - 1] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 2, lahtoruutuY - 1)));
		}
		else if (asema->lauta[lahtoruutuX + 2][lahtoruutuY - 1] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX + 2][lahtoruutuY - 1]->getVari();
			// jos oman v‰rinen niin lis‰t‰‰n tˆrmayslistaan
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
			}
			// jos vastujan nappula niin lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 2, lahtoruutuY - 1)));
			}
		}
	}
	if (lahtoruutuX - 2 >= 0 && lahtoruutuY + 1 < 8) {
		if (asema->lauta[lahtoruutuX - 2][lahtoruutuY + 1] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 2, lahtoruutuY + 1)));
		}
		else if (asema->lauta[lahtoruutuX - 2][lahtoruutuY + 1] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX - 2][lahtoruutuY + 1]->getVari();
			// jos oman v‰rinen niin lis‰t‰‰n tˆrmayslistaan
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
			}
			// jos vastujan nappula niin lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 2, lahtoruutuY + 1)));
			}
		}
	}
	if (lahtoruutuX - 2 >= 0 && lahtoruutuY - 1 >= 0) {
		if (asema->lauta[lahtoruutuX - 2][lahtoruutuY - 1] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 2, lahtoruutuY - 1)));
		}
		else if (asema->lauta[lahtoruutuX - 2][lahtoruutuY - 1] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX - 2][lahtoruutuY - 1]->getVari();
			// jos oman v‰rinen niin lis‰t‰‰n tˆrmayslistaan
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
			}
			// jos vastujan nappula niin lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 2, lahtoruutuY - 1)));
			}
		}
	}
	/*for (auto s : lista)
	{
	std::wcout << L"Ratsu";
	std::wcout << s.getAlkuruutu().getSarake();
	std::wcout << s.getAlkuruutu().getRivi() << "-";

	std::wcout << s.getLoppuruutu().getSarake();
	std::wcout << s.getLoppuruutu().getRivi() << "\n";
	}*/
}

void Lahetti::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	int lahtoruutuY = ruutu->getRivi();
	int lahtoruutuX = ruutu->getSarake();

	int lahtoruudunNappulanVari;
	int tuloruudunNappulanVari;

	int j;

	lahtoruudunNappulanVari = asema->lauta[lahtoruutuX][lahtoruutuY]->getVari();

	// viistorivi ruudusta oikealle ylˆs
	for (int i = lahtoruutuX + 1; i < 8; i++) {
		// j arvo asetetaan vain silmukan ensimm‰isell‰ kierroksella alkuarvoon
		if (i == lahtoruutuX + 1) {
			j = lahtoruutuY + 1;
		}
		if (j < 0 || j > 7 || i < 0 || i > 7) {
			break;
		}
		// Jos tyhj‰ ruutu niin lis‰t‰‰n listaan
		if (asema->lauta[i][j] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
		}
		else if (asema->lauta[i][j] != NULL) {
			// Jos oma nappula niin poistutaan for silmukasta. Ei lis‰t‰ listaan
			// Tarkistetaan ett‰ jos l‰htˆruudussa olevan nappulan v‰ri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
			tuloruudunNappulanVari = asema->lauta[i][j]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
				break;
			}
			// jos vastujan nappula niin poistutaan for silmukasta. Lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
				break;
			}

		}
		j++;
	}

	// viistorivi ruudusta oikealle alas
	for (int i = lahtoruutuX + 1; i < 8; i++) {
		// j arvo asetetaan vain silmukan ensimm‰isell‰ kierroksella alkuarvoon
		if (i == lahtoruutuX + 1) {
			j = lahtoruutuY - 1;
		}
		if (j < 0 || j > 7 || i < 0 || i > 7) {
			break;
		}
		// Jos tyhj‰ ruutu niin lis‰t‰‰n listaan
		if (asema->lauta[i][j] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
		}
		else if (asema->lauta[i][j] != NULL) {
			// Jos oma nappula niin poistutaan for silmukasta. Ei lis‰t‰ listaan
			// Tarkistetaan ett‰ jos l‰htˆruudussa olevan nappulan v‰ri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
			tuloruudunNappulanVari = asema->lauta[i][j]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
				break;
			}
			// jos vastujan nappula niin poistutaan for silmukasta. Lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
				break;
			}
		}

		j--;
	}

	// viistorivi ruudusta vasemmalle ylˆs
	for (int i = lahtoruutuX - 1; i >= 0; i--) {
		// j arvo asetetaan vain silmukan ensimm‰isell‰ kierroksella alkuarvoon
		if (i == lahtoruutuX - 1) {
			j = lahtoruutuY + 1;
		}
		if (j < 0 || j > 7 || i < 0 || i > 7) {
			break;
		}
		// Jos tyhj‰ ruutu niin lis‰t‰‰n listaan
		if (asema->lauta[i][j] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
		}
		else if (asema->lauta[i][j] != NULL) {
			// Jos oma nappula niin poistutaan for silmukasta. Ei lis‰t‰ listaan
			// Tarkistetaan ett‰ jos l‰htˆruudussa olevan nappulan v‰ri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
			tuloruudunNappulanVari = asema->lauta[i][j]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
				break;
			}
			// jos vastujan nappula niin poistutaan for silmukasta. Lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
				break;
			}
		}

		j++;
	}
	// viistorivi ruudusta vasemmalle alas
	for (int i = lahtoruutuX - 1; i >= 0; i--) {
		// j arvo asetetaan vain silmukan ensimm‰isell‰ kierroksella alkuarvoon
		if (i == lahtoruutuX - 1) {
			j = lahtoruutuY - 1;
		}
		if (j < 0 || j > 7 || i < 0 || i > 7) {
			break;
		}
		// Jos tyhj‰ ruutu niin lis‰t‰‰n listaan
		if (asema->lauta[i][j] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
		}
		else if (asema->lauta[i][j] != NULL) {
			// Jos oma nappula niin poistutaan for silmukasta. Ei lis‰t‰ listaan
			// Tarkistetaan ett‰ jos l‰htˆruudussa olevan nappulan v‰ri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
			tuloruudunNappulanVari = asema->lauta[i][j]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
				break;
			}
			// jos vastujan nappula niin poistutaan for silmukasta. Lis‰t‰‰n listaan
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
				break;
			}
		}

		j--;
	}
	// testausta varten
	// Huom. uuden standardin mukaista c++ koodia, auto-m‰‰re antaa k‰‰nt‰j‰n p‰‰tell‰ luokan, k‰ytt‰‰ iteraattoreita
	/*for (auto s : lista)
	{
	std::wcout << L"L‰hetti";
	std::wcout << s.getAlkuruutu().getSarake();
	std::wcout << s.getAlkuruutu().getRivi() << "-";

	std::wcout << s.getLoppuruutu().getSarake();
	std::wcout << s.getLoppuruutu().getRivi() << "\n";
	}*/
}

void Daami::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	this->Lahetti::annaSiirrot(lista, ruutu, asema, vari);
	this->Torni::annaSiirrot(lista, ruutu, asema, vari);
	/*for (auto s : lista)
	{
	std::wcout << L"Daami";
	std::wcout << s.getAlkuruutu().getSarake();
	std::wcout << s.getAlkuruutu().getRivi() << "-";

	std::wcout << s.getLoppuruutu().getSarake();
	std::wcout << s.getLoppuruutu().getRivi() << "\n";
	}*/
}

void Kuningas::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	/*perusidea on ett‰ kaikki viereiset ruudut ovat sallittuja. kuten tornilla ja l‰hetill‰,
	oman nappulan p‰‰lle ei voi menn‰ ja vastustajan nappulan voi syˆd‰.

	Kaikki muu kuninkaaseen liittyv‰ tarkistus tehd‰‰n eripaikassa*/


	int lahtoruutuY = ruutu->getRivi();
	int lahtoruutuX = ruutu->getSarake();

	int lahtoruudunNappulanVari;
	int tuloruudunNappulanVari;

	lahtoruudunNappulanVari = asema->lauta[lahtoruutuX][lahtoruutuY]->getVari();


	// K‰yd‰‰n perussiirtojen tyhj‰t ruudut l‰pi 
	// Pit‰‰ tarkistaa ett‰ ehdokas ruutu viel‰ laudalla
	if (lahtoruutuX + 1 < 8) {
		if (asema->lauta[lahtoruutuX + 1][lahtoruutuY] == NULL) {

			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY)));


		}
		else if (asema->lauta[lahtoruutuX + 1][lahtoruutuY] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX + 1][lahtoruutuY]->getVari();
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY)));
			}


		}
	}

	if (lahtoruutuX + 1 < 8 && lahtoruutuY + 1 < 8) {
		if (asema->lauta[lahtoruutuX + 1][lahtoruutuY + 1] == NULL) {

			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY + 1)));

		}
		else if (asema->lauta[lahtoruutuX + 1][lahtoruutuY + 1] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX + 1][lahtoruutuY + 1]->getVari();
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {

				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY + 1)));

			}
		}
	}

	if (lahtoruutuX + 1 < 8 && lahtoruutuY - 1 >= 0) {
		if (asema->lauta[lahtoruutuX + 1][lahtoruutuY - 1] == NULL) {

			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY - 1)));

		}
		else if (asema->lauta[lahtoruutuX + 1][lahtoruutuY - 1] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX + 1][lahtoruutuY - 1]->getVari();
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {

				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY - 1)));

			}
		}
	}

	if (lahtoruutuX - 1 >= 0) {
		if (asema->lauta[lahtoruutuX - 1][lahtoruutuY] == NULL) {

			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 1, lahtoruutuY)));

		}
		else if (asema->lauta[lahtoruutuX - 1][lahtoruutuY] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX - 1][lahtoruutuY]->getVari();
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {

				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 1, lahtoruutuY)));

			}
		}
	}

	if (lahtoruutuX - 1 >= 0 && lahtoruutuY + 1 < 8) {
		if (asema->lauta[lahtoruutuX - 1][lahtoruutuY + 1] == NULL) {

			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 1, lahtoruutuY + 1)));

		}
		else if (asema->lauta[lahtoruutuX - 1][lahtoruutuY + 1] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX - 1][lahtoruutuY + 1]->getVari();
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {

				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 1, lahtoruutuY + 1)));

			}
		}
	}

	if (lahtoruutuX - 1 >= 0 && lahtoruutuY - 1 >= 0) {
		if (asema->lauta[lahtoruutuX - 1][lahtoruutuY - 1] == NULL) {

			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 1, lahtoruutuY - 1)));

		}
		else if (asema->lauta[lahtoruutuX - 1][lahtoruutuY - 1] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX - 1][lahtoruutuY - 1]->getVari();
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {

				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 1, lahtoruutuY - 1)));

			}
		}
	}

	if (lahtoruutuY + 1 < 8) {
		if (asema->lauta[lahtoruutuX][lahtoruutuY + 1] == NULL) {

			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX, lahtoruutuY + 1)));

		}
		else if (asema->lauta[lahtoruutuX][lahtoruutuY + 1] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX][lahtoruutuY + 1]->getVari();
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {

				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX, lahtoruutuY + 1)));

			}
		}
	}

	if (lahtoruutuY - 1 >= 0) {
		if (asema->lauta[lahtoruutuX][lahtoruutuY - 1] == NULL) {

			lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX, lahtoruutuY - 1)));

		}
		else if (asema->lauta[lahtoruutuX][lahtoruutuY - 1] != NULL) {
			tuloruudunNappulanVari = asema->lauta[lahtoruutuX][lahtoruutuY - 1]->getVari();
			if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {

				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX, lahtoruutuY - 1)));

			}
		}
	}
}

void Sotilas::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	int lahtoruutuY = ruutu->getRivi();
	int lahtoruutuX = ruutu->getSarake();
	int lahtoruudunNappulanVari;
	int tuloruudunNappulanVari;
	lahtoruudunNappulanVari = asema->lauta[lahtoruutuX][lahtoruutuY]->getVari();

	// jos sotilas rivill‰ 2 ja sotilas valkea tai sotilas rivill‰ 7 ja sotilas musta sill‰ on kaksois askel mahdollisuus
	// muilla riveill‰ sotilaalla yksˆis aske
	// sotilas voi myˆs syˆd‰ etuviistoon ruudustaan
	// sotilas voi korottua jos se saavuttaa rivin 8 valkeilla ja vastaavasti rivin 1 mustilla
	/*
	// valkea rivill‰ 2
	if (lahtoruutuY == 1 && lahtoruudunNappulanVari == 0) {
		for (int i = lahtoruutuY + 1; i < lahtoruutuY + 3; i++) {
			// Jos tyhj‰ ruutu niin lis‰t‰‰n listaan
			if (asema->lauta[lahtoruutuX][i] == NULL) {
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX, i)));
			}else if (asema->lauta[lahtoruutuX][3] != NULL) {
				if (lahtoruutuX + 1 < 8) { // tarkastetaan ett‰ pysyt‰‰n laudalla
					if (asema->lauta[lahtoruutuX + 1][lahtoruutuY + 1] != NULL) {
						// Tarkistetaan ett‰ jos l‰htˆruudussa olevan nappulan v‰ri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
						tuloruudunNappulanVari = asema->lauta[lahtoruutuX + 1][lahtoruutuY + 1]->getVari();
						if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
						}
						// jos vastujan nappula niin poistutaan for silmukasta. Lis‰t‰‰n listaan
						if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
							if (lahtoruutuY < 6)
								lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY + 1)));
							else
								lisaaSotilaanKorotukset(&Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY + 1)), lista, asema);
						}
					}
				}
			}else
				break;
		}
	}

	// musta rivill‰ 7
	if (lahtoruutuY == 6 && lahtoruudunNappulanVari == 1) {
		for (int i = lahtoruutuY - 1; i > lahtoruutuY - 3; i--) {
			// Jos tyhj‰ ruutu niin lis‰t‰‰n listaan
			if (asema->lauta[lahtoruutuX][i] == NULL) {
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX, i)));
			}else if(asema->lauta[lahtoruutuX][5] != NULL) {
				if (lahtoruutuX + 1 < 8) { // tarkastetaan ett‰ pysyt‰‰n laudalla
					if (asema->lauta[lahtoruutuX + 1][lahtoruutuY - 1] != NULL) {
						// Tarkistetaan ett‰ jos l‰htˆruudussa olevan nappulan v‰ri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
						tuloruudunNappulanVari = asema->lauta[lahtoruutuX + 1][lahtoruutuY - 1]->getVari();
						if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
						}
						// jos vastujan nappula niin poistutaan for silmukasta. Lis‰t‰‰n listaan
						if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
							if (lahtoruutuY > 1)
								lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY - 1)));
							else
								lisaaSotilaanKorotukset(&Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY - 1)), lista, asema);
						}
					}
				}
			}else
				break;
		}
	}
	*/
	// perusruudut valkeille (lahtoruutuY == 2 || lahtoruutuY == 3 || lahtoruutuY == 4 || lahtoruutuY == 5 || lahtoruutuY == 6) && 
	if ((lahtoruutuY != 7 || lahtoruutuY != 0) && lahtoruudunNappulanVari == 0) {
		//siirtym‰t eteenp‰in
		if (asema->lauta[lahtoruutuX][lahtoruutuY + 1] == NULL) {
			if (lahtoruutuY < 6)
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX, lahtoruutuY + 1)));
			else
				lisaaSotilaanKorotukset(&Siirto(*ruutu, Ruutu(lahtoruutuX, lahtoruutuY + 1)), lista, asema);
		}
		//syˆnnit viistoon
		if (lahtoruutuX + 1 < 8) { // tarkastetaan ett‰ pysyt‰‰n laudalla
			if (asema->lauta[lahtoruutuX + 1][lahtoruutuY + 1] != NULL) {
				// Tarkistetaan ett‰ jos l‰htˆruudussa olevan nappulan v‰ri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
				tuloruudunNappulanVari = asema->lauta[lahtoruutuX + 1][lahtoruutuY + 1]->getVari();
				if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
				}
				// jos vastujan nappula niin poistutaan for silmukasta. Lis‰t‰‰n listaan
				if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
					if (lahtoruutuY < 6)
						lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY + 1)));
					else
						lisaaSotilaanKorotukset(&Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY + 1)), lista, asema);
				}
			}
		}
		if (lahtoruutuX - 1 >= 0) {
			if (asema->lauta[lahtoruutuX - 1][lahtoruutuY + 1] != NULL) {
				// Tarkistetaan ett‰ jos l‰htˆruudussa olevan nappulan v‰ri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
				tuloruudunNappulanVari = asema->lauta[lahtoruutuX - 1][lahtoruutuY + 1]->getVari();
				if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
				}
				// jos vastustajan nappula niin lis‰t‰‰n listaan
				if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
					if (lahtoruutuY < 6)
						lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 1, lahtoruutuY + 1)));
					else
						lisaaSotilaanKorotukset(&Siirto(*ruutu, Ruutu(lahtoruutuX - 1, lahtoruutuY + 1)), lista, asema);
				}
			}
		}
	}
	// perusruudut mustille (lahtoruutuY == 5 || lahtoruutuY == 4 || lahtoruutuY == 3 || lahtoruutuY == 2 || lahtoruutuY == 1)
	if ((lahtoruutuY != 7 || lahtoruutuY != 0) && lahtoruudunNappulanVari == 1) {
		//siirtym‰t eteenp‰in
		if (asema->lauta[lahtoruutuX][lahtoruutuY - 1] == NULL) {
			if (lahtoruutuY > 1)
				lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX, lahtoruutuY - 1)));
			else
				lisaaSotilaanKorotukset(&Siirto(*ruutu, Ruutu(lahtoruutuX, lahtoruutuY - 1)), lista, asema);
		}
		//syˆnnit viistoon
		if (lahtoruutuX + 1 < 8) { // tarkastetaan ett‰ pysyt‰‰n laudalla
			if (asema->lauta[lahtoruutuX + 1][lahtoruutuY - 1] != NULL) {
				// Tarkistetaan ett‰ jos l‰htˆruudussa olevan nappulan v‰ri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
				tuloruudunNappulanVari = asema->lauta[lahtoruutuX + 1][lahtoruutuY - 1]->getVari();
				if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
				}
				// jos vastujan nappula niin poistutaan for silmukasta. Lis‰t‰‰n listaan
				if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
					if (lahtoruutuY > 1)
						lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY - 1)));
					else
						lisaaSotilaanKorotukset(&Siirto(*ruutu, Ruutu(lahtoruutuX + 1, lahtoruutuY - 1)), lista, asema);
				}
			}
		}
		if (lahtoruutuX - 1 >= 0) {
			if (asema->lauta[lahtoruutuX - 1][lahtoruutuY - 1] != NULL) {
				// Tarkistetaan ett‰ jos l‰htˆruudussa olevan nappulan v‰ri on sama kuin tarkastelun alaisessa ruudussa, niin silloin on oma nappula
				tuloruudunNappulanVari = asema->lauta[lahtoruutuX - 1][lahtoruutuY - 1]->getVari();
				if (lahtoruudunNappulanVari == tuloruudunNappulanVari) {
				}
				// jos vastujan nappula niin poistutaan for silmukasta. Lis‰t‰‰n listaan
				if (lahtoruudunNappulanVari != tuloruudunNappulanVari) {
					if (lahtoruutuY > 1)
						lista.push_back(Siirto(*ruutu, Ruutu(lahtoruutuX - 1, lahtoruutuY - 1)));
					else
						lisaaSotilaanKorotukset(&Siirto(*ruutu, Ruutu(lahtoruutuX - 1, lahtoruutuY - 1)), lista, asema);
				}
			}
		}
	}

	// Ohestalyˆnti on mahdollinen, jos jollain sarakkeella on viimeksi
	// tapahtunut sotilaan kaksoisaskel.
	if (asema->kaksoisaskelSarakkeella != -1)
	{
		if (vari == 0 && lahtoruutuY == 4)
		{
			if (asema->lauta[asema->kaksoisaskelSarakkeella][4] && asema->lauta[asema->kaksoisaskelSarakkeella][4]->getKoodi() == MS)
				lista.push_back(Siirto(*ruutu, Ruutu(asema->kaksoisaskelSarakkeella, 5)));
		}
		if (vari == 1 && lahtoruutuY == 3)
		{
			if (asema->lauta[asema->kaksoisaskelSarakkeella][3] && asema->lauta[asema->kaksoisaskelSarakkeella][3]->getKoodi() == VS)
				lista.push_back(Siirto(*ruutu, Ruutu(asema->kaksoisaskelSarakkeella, 2)));
		}
	}
}


void Sotilas::lisaaSotilaanKorotukset(Siirto* siirto, std::list<Siirto>& lista, Asema* asema) {
}





