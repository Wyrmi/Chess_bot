#include "siirto.h"

Siirto::Siirto(Ruutu alkuRuutu, Ruutu loppuRuutu){
	this->alkuRuutu = alkuRuutu;
	this->loppuRuutu = loppuRuutu;
	this->lyhytLinna = false;
	this->pitkalinna = false;
}

Siirto::Siirto(bool lyhytLinna, bool pitkaLinna) {
	this->lyhytLinna = lyhytLinna;
	this->pitkalinna = pitkaLinna;
}

Ruutu Siirto::getAlkuruutu(){
	return alkuRuutu;
}
Ruutu Siirto::getLoppuruutu(){
	return loppuRuutu;
}
bool Siirto::onkoLyhytLinna() {
	return this->lyhytLinna;
}
bool Siirto::onkoPitkälinna() {
	return this->pitkalinna;
}