#pragma once

class Ruutu{
public:
	Ruutu(int, int);
	Ruutu() {}
	int getRivi();
	int getSarake();
	void setRivi(int);
	void setSarake(int);
private:
	int sarake;
	int rivi;
};