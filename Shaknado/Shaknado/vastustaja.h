#pragma once
#include <string>
class Vastustaja{
public:
	Vastustaja(std::wstring);
	std::wstring getNimimerkki();
private:
	std::wstring nimimerkki;
};