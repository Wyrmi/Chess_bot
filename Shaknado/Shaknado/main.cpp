#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include "kayttoliittyma.h"
#include "Siirto.h"
#include "asema.h"

using namespace std; 

int main()
{
	wcout << "HeippariShakki\n";
	wcout << "Tervetuloa pelaamaan!\n";
	int lopetus = 100;
	Asema asema; 
//	Kayttoliittyma kali(&asema);
	Kayttoliittyma::getInstance()->aseta_asema(&asema);

	Peli peli(Kayttoliittyma::getInstance()->
		kysyVastustajanVari());
	std::list<Siirto> lista;
	system("cls");
	int koneenVari = peli.getKoneenVari();

	while (lopetus != 0) {
		lista.clear();
		Kayttoliittyma::getInstance()->piirraLauta();
		// Tarkasta onko peli loppu?
		asema.annaLaillisetSiirrot(lista);
		if (lista.size() == 0) {
			lopetus = 0;
			std::wcout << "Peli loppui";
			continue;
		}
		Siirto siirto;
		if (asema.getSiirtovuoro() == koneenVari) {

			// KONE PÄÄTTÄÄ SIIRROSTA TÄSSÄ (TOTEUTETAAN MYÖHEMMIN)
			siirto = Kayttoliittyma::getInstance()->
				annaVastustajanSiirto();
		}
		else {
			// KYSY KÄYTTÄJÄN SIIRTO
			siirto = Kayttoliittyma::getInstance()->
				annaVastustajanSiirto();
		}
		asema.paivitaAsema(&siirto);
	}

/*	while (lopetus != 100){
		std::list<Siirto> lista;
		//laillisetSiirrot.annaKuninkaanLaillisetSiirrot(lista, new Ruutu(7, 5), &asema, peli.getKoneenVari());
		laillisetSiirrot.annaLaillisetSiirrot(&asema, lista);
		for (auto s : lista)
		{
			if (s.onkoLyhytLinna())
				std::wcout << "O-O";
			else if (s.onkoPitkälinna())
				std::wcout << "O-O-O";
			else
			{
				std::wcout << asema.lauta[s.getAlkuruutu().getSarake()][s.getAlkuruutu().getRivi()]->getNimi();
				std::wcout << s.getAlkuruutu().getSarake();
				std::wcout << s.getAlkuruutu().getRivi() << "-";

				std::wcout << s.getLoppuruutu().getSarake();
				std::wcout << s.getLoppuruutu().getRivi() << "\n";
			}
		}
		kali.piirraLauta();
		Siirto siirto = kali.annaVastustajanSiirto();
		asema.paivitaAsema(&siirto);
		double asemanArvo = evaluointi.evaluoi(&asema, &laillisetSiirrot);
		std::wcout << asemanArvo;
		system("cls");
	}*/
	
	return 0;
}