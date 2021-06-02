#pragma once
enum Stanje{zauzeto, slobodno};

class Smjestaj
{
private:
	int BrojSoba, BrojKupatila, BrojKreveta, sifraSobe;
	double cijena;
	static int brojac;
	char grad[20];
	Stanje stanje;

public:
	Smjestaj();
	void setBrojSoba();
	void setBrojKupatila();
	void setBrojKreveta();
	void setSifraSobe();
	void setCijena();
	void setGrad();
	void setStanje(int x);
	int getBrojSoba();
	int getBrojKupatila();
	int getBrojKreveta();
	int getSifraSobe();
	double getCijena();
	char* getGrad();
	Stanje getStanje();
	void unosSmjestaja();
	~Smjestaj();
};

