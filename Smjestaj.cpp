#include "Smjestaj.h"
#include <iostream>

using std::cout;
using std::cin;
int Smjestaj::brojac = 1;

Smjestaj::Smjestaj()
{
	this->BrojSoba = 3;
	this->BrojKupatila = 2;
	this->BrojKreveta = 10;
	this->sifraSobe = 1234;
	this->stanje = zauzeto;
}

void Smjestaj::setBrojSoba()
{
	cout << "\n\tUnesite broj soba: ";
	cin >> this->BrojSoba;
	cin.ignore();
}

void Smjestaj::setBrojKupatila()
{
	cout << "\n\tUnesite broj kupatila: ";
	cin >> this->BrojKupatila;
	cin.ignore();
}

void Smjestaj::setBrojKreveta()
{
	cout << "\n\tUnesite broj kreveta: ";
	cin >> this->BrojKreveta;
	cin.ignore();
}

void Smjestaj::setSifraSobe()
{
	this->sifraSobe = brojac;
	brojac++;
}

void Smjestaj::setCijena()
{
	cout << "\n\tUnesite cijenu nocenja: ";
	cin >> this->cijena;
	cin.ignore();
}

void Smjestaj::setGrad()
{
	cout << "\n\tUnesite naziv grada u kojem se nalazi smjestaj: ";
	cin.getline(this->grad, 20);
}

void Smjestaj::setStanje(int x)
{
	if (x==1)
	{
		stanje = zauzeto;
	}
	else
	{
		stanje = slobodno;
	}
}

int Smjestaj::getBrojSoba()
{
	return this->BrojSoba;
}

int Smjestaj::getBrojKupatila()
{
	return this->BrojKupatila;
}

int Smjestaj::getBrojKreveta()
{
	return this->BrojKreveta;
}

int Smjestaj::getSifraSobe()
{
	return this->sifraSobe;
}

double Smjestaj::getCijena()
{
	return this->cijena;
}

char* Smjestaj::getGrad()
{
	return this->grad;
}

Stanje Smjestaj::getStanje()
{
	return this->stanje;
}

void Smjestaj::unosSmjestaja()
{
	setSifraSobe();
	setBrojSoba();
	setBrojKupatila();
	setBrojKreveta();
	setCijena();
	setGrad();
	int biraj;
	cout << "\n\tUnesite stanje smjestaja: \n\t 1. Zauzeto \n\t 2. Slobodno\n";
	do {
		cout << "Vas izbor: ";
		cin >> biraj;
	} while (biraj < 1 || biraj>2);
	setStanje(biraj);
	cout << "\nSmjestaj uspjesno unesen!\n\n";
	cin.ignore();
}

Smjestaj::~Smjestaj()
{
}
