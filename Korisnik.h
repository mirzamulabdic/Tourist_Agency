#pragma once
class Korisnik
{
private:
	char username[20], password[20], ime[10], prezime[20];
	bool registrovan;
	
public:
	void setUsername();
	void setPassword();
	void setIme();
	void setPrezime();
	char* getUsername();
	char* getPassword();
	char* getIme();
	char* getPrezime();
	bool getRegistrovan();
	void registracija();
	bool prijava();
	virtual void ispisiPodatke();
	virtual void promjenaPassworda();
	Korisnik();
	~Korisnik();
};

