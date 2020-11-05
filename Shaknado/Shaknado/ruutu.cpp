
#include "ruutu.h"


Ruutu::Ruutu(int sarake, int rivi){
	this->rivi = rivi;
	this->sarake = sarake;
}

int Ruutu::getRivi(){
	return rivi;
}
int Ruutu::getSarake(){
	return sarake;
}
void Ruutu::setRivi(int rivi) {
	this->rivi = rivi;
}
void Ruutu::setSarake(int sarake) {
	this->sarake = sarake;
}