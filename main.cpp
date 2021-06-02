#include <iostream>
#include "Korisnik.h"
#include "Admin.h"
#include "funkcije.h"
using namespace std;


int main() {
	
	std::shared_ptr<Admin> a(new Admin());
	std::shared_ptr<Smjestaj> s(new Smjestaj());
	std::shared_ptr<Korisnik> k(new Korisnik());

	int izbor, izbor1, izbor2;
	bool prijavljen = false;
	cout << "\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ DOBRODOSLI U MANAGEMENT SYSTEM TURISTICKE AGENCIJE ============|\n\n\t\t\t\t\t\t\t";
	cin.ignore();
	do {
		do {
			system("cls");

			uvodMeni();
			cin >> izbor;
			if (izbor == 1) {
				do {
					do {
						system("cls");
						adminMeni();
						cin >> izbor2;
						if (izbor2 == 1) {
							system("cls");
							a->unosSmjestaja();
							system("pause");
						}
						if (izbor2 == 2) {
							system("cls");
							if (a->Smjestaji.size() == 0) {
								cout << "\n\t\tZao nam je. Nema unesenih smjestaja!\n\n";
								system("pause");
							}
							else {
								a->ispisSmjestaja();
								system("pause");
							}
						}
						if (izbor2 == 3) {
							system("cls");
						}
					} while (izbor2 != 3);
				} while (izbor2 < 1 || izbor2>3);
			}

			if (izbor == 2) {
				system("cls");
				do {
					do {
						prviMeni();
						cin >> izbor1;
						if (izbor1 == 1) {
							system("cls");
							cin.ignore();
							k->registracija();
							system("cls");
						}

						if (izbor1 == 2 && k->getRegistrovan() == true) {
							bool prijavljen = false;
							system("cls");

							if (k->prijava() == true && prijavljen == false) {
								prijavljen = true;
								do {
									do {
										system("cls");
										korisnickiMeni();
										cin >> izbor2;
										if (izbor2 == 1) {
											system("cls");
											if (a->Smjestaji.size() == 0) {
												cout << "\n\t\tZao nam je. Nema unesenih smjestaja!\n\n";
												system("pause");
											}
											else {
												a->ispisSmjestaja();
												system("pause");
											}
										}
										if (izbor2 == 2) {
											system("cls");
											if (a->Smjestaji.size() == 0) {
												cout << "\n\t\tZao nam je. Nema unesenih smjestaja!\n\n";
												system("pause");
											}
											else {
												a->ispisSmjestaja();
												int rb, YN;
													do {
														cout << "\nUnesite sifru smjestaja za rezervaciju: ";
														cin >> rb;
														cin.ignore();
														cout << "Da li ste sigurni\n1.Da\n2.Ne\nIzbor: ";
														cin >> YN;
													} while (YN >= 2);
												a->rezervisi(rb);
												system("pause");
												cout << "\n\n";
											}
										}
										if (izbor2 == 3) {
											system("cls");
											a->pretragaSmjestaja();
										}
										if (izbor2 == 4) {
											system("cls");
											cin.ignore();
											k->ispisiPodatke();
											system("pause");
										}
										if (izbor2 == 5) {
											system("cls");
											k->promjenaPassworda();
											system("pause");
										}
										if (izbor2 == 6) {
											prijavljen = false;
											system("cls");
										}
									} while (izbor2 != 6);
								} while (izbor2 < 1 || izbor2>6);

							}
							else {
								system("cls");
								cout << "Netacan username ili password!\n\n";
								system("pause");
							}
						}
						else if (izbor1 == 2 && k->getRegistrovan() == false) {
							system("cls");
							cout << "\tMolimo registrujte se.\n";
						}
					} while (izbor1 != 3);
				} while (izbor1 < 1 || izbor1 > 3);
			}
			if (izbor == 3) {
				system("cls");
				cout << "=============================================================\n\n";
				cout << "\n\tHvala vam na kroistenju naseg programa.\n\tDovidjenja!\n\n";
				cout << "\n=============================================================\n\n";
				system("pause");
			}
		} while (izbor != 3);
	} while (izbor < 1 || izbor>3);

	return 0;
}