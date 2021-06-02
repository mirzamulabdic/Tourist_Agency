#pragma once
#include <vector>
#include "Smjestaj.h"
#include "Korisnik.h"
using std::vector;

class Admin : public Korisnik
{
public:
	vector<Smjestaj> Smjestaji;
	static int brojSmjestaja;
	void unosSmjestaja();
	void pretragaSmjestajaPoGradu();
	void pretragaSmjestajaPoCijeni();
	void pretragaSmjestajaPoKrevetima();
	void pretragaSmjestaja();
	void rezervisi(int a);
	void ispisSmjestaja();
	~Admin(); 
	Admin();
};

