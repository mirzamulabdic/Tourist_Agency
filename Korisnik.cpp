#include "Korisnik.h"
#include <iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cout;

void Korisnik::setUsername()
{
	cout << "\tUnesite username: ";
	cin.getline(this->username, 20);
	cout << "\n\n";
}

void Korisnik::setPassword()
{
	cout << "\tUnesite password: ";
	cin.getline(this->password, 20);
	cout << "\n\n";
}

void Korisnik::setIme()
{
	cout << "\tUnesite ime: ";
	cin.getline(this->ime, 10);
	cout << "\n\n";
}

void Korisnik::setPrezime()
{
	cout << "\tUnesite prezime: ";
	cin.getline(this->prezime, 20);
	cout << "\n\n";
}

char* Korisnik::getUsername()
{
	return this->username;
}

char* Korisnik::getPassword()
{
	return this->password;
}

char* Korisnik::getIme()
{
	return this->ime;
}

char* Korisnik::getPrezime()
{
	return this->prezime;
}

bool Korisnik::getRegistrovan()
{
	return this->registrovan;
}

void Korisnik::registracija()
{	
	cout << "\n\t\t   DOBRODOSLI U REGISTRACIONI SISTEM\n";
	cout << "=============================================================\n\n";

	if (getRegistrovan() == false)
	{
		setIme();
		setPrezime();
		setUsername();
		setPassword();
		this->registrovan = true;
	}

	std::ofstream file("login.txt");
	file << this->getUsername() << std::endl << getPassword();
	file.close();
	cout << "Uspjesna registracija!\n\n";
	cout << "=============================================================\n";
	system("pause");
}

bool Korisnik::prijava()
{
	std::string user, pass;

	cout << "\n\t\t   PRIJAVA\n";
	cout << "=============================================================\n\n";

	if (getRegistrovan() == true)
	{
		cout << "\tUsername: ";
		cin >> user;
		cout << "\n\n\tPassword: ";
		cin >> pass;

		if (getUsername() == user & getPassword() == pass)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		system("cls");
		cout << "\n\tMolimo izvrsite registraciju!\n\n";
		system("pause");
	}
}

void Korisnik::ispisiPodatke()
{
	cout << "\n\t\t   VASI PODACI\n";
	cout << "=============================================================\n\n";
	cout << "\tIme: " << getIme();
	cout << "\n\n\tPrezime: " << getPrezime();
	cout << "\n\n\tUsername: " << getUsername();
	cout << "\n\n\tPassword: " << getPassword();
	cout << "\n\n=============================================================\n";

}

void Korisnik::promjenaPassworda()
{
	system("cls");
	cout << "\n\t\t   PROMJENA PASSWORDA\n";
	cout << "=============================================================\n\n";

	std::string passwordTemp, pw, un;
	cout << "\tUnesite stari password: ";
	cin >> passwordTemp;
	std::ifstream read("login.txt");
	getline(read, un);
	getline(read, pw);
	read.close();

	if (passwordTemp == pw) {
		cin.ignore();
		do {
			cout << "\n";
			this->setPassword();
			if (this->password == passwordTemp) {
				cout << "Pasword isti kao stari!\n";
			}
		} while (this->password == passwordTemp);
		std::ofstream file("login.txt");
		file << this->getUsername() << std::endl << this->getPassword();
		file.close();
		cout << "Uspjesno ste postavili vas novi password!\n";
		cout << "\n=============================================================\n\n";
	}
	else
	{
		cout << "\nNeispravan stari password!\n";
	}
}

Korisnik::Korisnik()
{
	strcpy_s(this->ime, "Niko");
	strcpy_s(this->prezime, "Nikic");
	strcpy_s(this->username, "User");
	strcpy_s(this->password, "Password");
	this->registrovan = false;
}

Korisnik::~Korisnik()
{
	remove("login.txt");
}
