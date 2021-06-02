#include "Admin.h"
#include "Smjestaj.h"
#include <iostream>
#include <fstream>
using std::cin;
using std::cout;

int Admin::brojSmjestaja = 0;

void Admin::unosSmjestaja()
{
	cout << "\n==================================================================";
	cout << "\n\n=================\tUNOS SMJESTAJA\t\t==================";
	cout << "\n\n==================================================================\n\n";
	Smjestaj temp;
	temp.unosSmjestaja();
	Smjestaji.push_back(temp);
	brojSmjestaja++;
}

void Admin::pretragaSmjestajaPoGradu()
{
	if (Smjestaji.size() == 0) {
		cout << "\n\t\tZao nam je. Nema unesenih smjestaja!\n\n";
	}
	else {
		int br = 0;
		cin.ignore();
		char tGrad[20];
		cout << "\n\tUnesite naziv grada: ";
		cin.getline(tGrad, 20);

		cout << "----------------------------------------------------\n";
		cout << "\tSifra\tGrad\t\tBroj soba\tBroj kreveta\t\tCijena/noc\t\tStanje\n\n";
		for (int i = 0; i < Admin::brojSmjestaja; i++) {
			if (_strcmpi(Smjestaji[i].getGrad(), tGrad) == 0 && Smjestaji[i].getStanje() == slobodno) {
				br++;
				cout << "\t" << Smjestaji[i].getSifraSobe();
				cout << "\t" << Smjestaji[i].getGrad();
				cout << "\t\t" << std::left << Smjestaji[i].getBrojSoba();
				cout << "\t\t" << std::left << Smjestaji[i].getBrojKreveta();
				cout << "\t\t\t" << std::left << Smjestaji[i].getCijena();
				if (Smjestaji[i].getStanje() == 1) {
					cout << "\t\t\t" << std::left << "Slobodno\n";
				}
				else {
					cout << "\t\t\t" << std::left << "Zauzeto\n";
				}
				cout << "\n";
			}
		}

		if (br == 0) {
			cout << "\nZao nam je. Nije pronadjen ni jedan slobodan smjestaj u " << tGrad << "\n\n";
		}
		else {
			int rb, YN;
			cout << "Da li zelite rezervisati sobu?\n1.Da\n2.Ne\nIzbor: ";
			cin >> YN;

			if (YN == 2) {
				return;
			}
			else {


				do {
					cout << "\nUnesite sifru smjestaja za rezervaciju: ";
					cin >> rb;
					//cin.ignore();
					cout << "Da li ste sigurni\n1.Da\n2.Ne\nIzbor: ";
					cin >> YN;
				} while (YN == 2);
				this->rezervisi(rb);
			}
		}
	}
}

void Admin::pretragaSmjestajaPoCijeni()
{
	cin.ignore();
		double tCijena;
		cout << "\n\tUnesite cijenu sobe: ";
		cin >> tCijena;
		int br = 0;
		cout << "----------------------------------------------------\n";
		cout << "\tSifra\tGrad\t\tBroj soba\tBroj kreveta\t\tCijena/noc\t\tStanje\n\n";
		for (int i = 0; i < brojSmjestaja; i++) {
			if (Smjestaji[i].getCijena() <= tCijena && Smjestaji[i].getStanje()==slobodno) {
				br++;
				cout << "\t" << Smjestaji[i].getSifraSobe();
				cout << "\t" << Smjestaji[i].getGrad();
				cout << "\t\t" << std::left << Smjestaji[i].getBrojSoba();
				cout << "\t\t" << std::left << Smjestaji[i].getBrojKreveta();
				cout << "\t\t\t" << std::left << Smjestaji[i].getCijena();
				if (Smjestaji[i].getStanje() == 1) {
					cout << "\t\t\t" << std::left << "Slobodno\n";
				}
				else {
					cout << "\t\t\t" << std::left << "Zauzeto\n";
				}
				cout << "\n";
			}
		}
		if (br == 0) {
			cout << "\nZao nam je. Nije pronadjen ni jedan slobodan smjestaj po cijeni od " << tCijena << " KM. " << "\n\n";
		}
		else {
			int rb, YN;
			cout << "Da li zelite rezervisati sobu?\n1.Da\n2.Ne\nIzbor: ";
			cin >> YN;
			if (YN == 2) {
				return;
			}
			else {


				do {
					cout << "\nUnesite sifru smjestaja za rezervaciju: ";
					cin >> rb;
					//cin.ignore();
					cout << "Da li ste sigurni\n1.Da\n2.Ne\nIzbor: ";
					cin >> YN;
				} while (YN == 2);
				this->rezervisi(rb);
			}
		}
	}

void Admin::pretragaSmjestajaPoKrevetima()
{
		cin.ignore();
		int tKrevet;
		cout << "\n\tUnesite broj kreveta: ";
		cin >> tKrevet;
		int br = 0;
		cout << "----------------------------------------------------\n";
		cout << "\tSifra\tGrad\t\tBroj soba\tBroj kreveta\t\tCijena/noc\t\tStanje\n\n";
		for (int i = 0; i < brojSmjestaja; i++) {
			if (Smjestaji[i].getBrojKreveta() == tKrevet && Smjestaji[i].getStanje() == slobodno) {
				br++;
				cout << "\t" << Smjestaji[i].getSifraSobe();
				cout << "\t" << Smjestaji[i].getGrad();
				cout << "\t\t" << std::left << Smjestaji[i].getBrojSoba();
				cout << "\t\t" << std::left << Smjestaji[i].getBrojKreveta();
				cout << "\t\t\t" << std::left << Smjestaji[i].getCijena();
				if (Smjestaji[i].getStanje() == 1) {
					cout << "\t\t\t" << std::left << "Slobodno\n";
				}
				else {
					cout << "\t\t\t" << std::left << "Zauzeto\n";
				}
				cout << "\n";
			}
		}
		if (br == 0) {
			cout << "\nZao nam je. Nije pronadjen ni jedan slobodan smjestaj sa " << tKrevet << " kreveta. " << "\n\n";
		}
		else {
			int rb, YN;
			cout << "Da li zelite rezervisati sobu?\n1.Da\n2.Ne\nIzbor: ";
			cin >> YN;

			if (YN == 2) {
				return;
			}
			else {
				do {
					cout << "\nUnesite sifru smjestaja za rezervaciju: ";
					cin >> rb;
					cout << "Da li ste sigurni\n1.Da\n2.Ne\nIzbor: ";
					cin >> YN;
				} while (YN == 2);
				this->rezervisi(rb);
			}
		}
	}

void Admin::pretragaSmjestaja()
{
	int izbor;
	if (Smjestaji.size() == 0) {
		cout << "\n\t\tZao nam je. Nema unesenih smjestaja!\n\n";
		system("pause");
	}
	else
	{
		do {
			do {
				system("cls");
				cout << "\n\t\t   PRETRAGA SMJESTAJA\n";
				cout << "=============================================================";
				cout << "\n\t1.Pretraga po gradu\n";
				cout << "\t2.Pretraga po cijeni\n";
				cout << "\t3.Pretraga po broju kreveta\n";
				cout << "\t4.Izlaz\n";
				cout << "Izbor: ";
				cin >> izbor;
				if (izbor == 1) {
					system("cls");
					this->pretragaSmjestajaPoGradu();
					system("pause");
				}
				if (izbor == 2) {
					system("cls");
					this->pretragaSmjestajaPoCijeni();
					system("pause");
				}
				if (izbor == 3) {
					system("cls");
					this->pretragaSmjestajaPoKrevetima();
					system("pause");
				}
				if (izbor == 4) {
					system("cls");
				}
			} while (izbor != 4);
		} while (izbor < 1 || izbor>4);
	}
}

void Admin::rezervisi(int a)
{
	int br = 0;
	std::ofstream rezervacija("Potvrda Rezervacije.txt");
	try {
		for (int i = 0; i < Admin::brojSmjestaja; i++) {
			if (Smjestaji[i].getSifraSobe() == a && Smjestaji[i].getStanje() == slobodno) {
				br++;
				rezervacija << "Hvala vam na rezervaciji nase sobe u " << Smjestaji[i].getGrad() << "\n";
				rezervacija << "Sifra sobe " << Smjestaji[i].getSifraSobe();
				rezervacija << "\nCijena smjestaja/noc je " << Smjestaji[i].getCijena() << "KM.\n";
				rezervacija << "\n\n[OVAJ DOKUMENT PREDSTAVLJA POTVRDU VASE REGISTRACIJE TE GA ISPRINTANOG PRILAZETE PRILIKOM CHECK INa]\n\n";
				Smjestaji[i].setStanje(1);
				rezervacija.close();
				break;
			}
		}
		if (br == 0) {
			throw 505;
		}
	}
	catch (...) {
		cout << "\nZao nam je! Nismo u mogucnosti rezervisati izabrani smjestaj za vas.\n";
	}
	if(br > 0) {
		cout << "\nRezervacija je uspjesna!\n";
		cout << "Pogledajte dokument Potvrda Rezervacije.txt\n\n";
	}
}

void Admin::ispisSmjestaja()
{
	int br = 0;
	cout << "\n==================================================================";
	cout << "\n\n=================\tISPIS SMJESTAJA\t\t==================";
	cout << "\n\n==================================================================\n\n";
	cout << "------------------------------------------------------------------------------------------------------\n\n";
	cout << "\tSifra\tGrad\t\tBroj soba\tBroj kreveta\t\tCijena/noc\t\tStanje\n\n";
	for (int i = 0; i < brojSmjestaja; i++) {
		br++;
		cout << "\t" << Smjestaji[i].getSifraSobe() << "\t" << Smjestaji[i].getGrad() << "\t\t"<<std::left<< Smjestaji[i].getBrojSoba();
		cout << "\t\t" << std::left << Smjestaji[i].getBrojKreveta() << "\t\t\t" << std::left << Smjestaji[i].getCijena();
		if (Smjestaji[i].getStanje() == 1) cout << "\t\t\t" << std::left << "Slobodno\n";
		else cout << "\t\t\t" << std::left << "Zauzeto\n";
	}


	cout << "\n------------------------------------------------------------------------------------------------------\n\n";
	if (br == 0) {
		cout << "\nNema unesenih smjestaja!\n";
	}
}

Admin::~Admin()
{
}

Admin::Admin()
{
}
