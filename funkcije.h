#pragma once
#include <iostream>
using std::cout;
using std::cin;

void uvodMeni() {
	system("cls");
	cout << "\n\t\t   GLAVNI MENI\n";
	cout << "=============================================================";
	cout << "\n\n\t\t   1. Admin meni\n\n\t\t   2. Korisnicki meni\n\n\t\t   3. Izlaz iz programa";
	cout << "\n\n=============================================================\n";
	cout << "\n\nVas izbor: ";
}

void prviMeni() {
	cout << "\n\t\t   KORISNICKI MENI\n";
	cout << "=============================================================";
	cout << "\n\n\t\t   1. Registracija\n\n\t\t   2. Login\n\n\t\t   3. Povratak";
	cout << "\n\n=============================================================\n";
	cout << "\n\nVas izbor: ";
}

void adminMeni() {
	system("cls");
	cout << "\n\t\t   ADMIN MENI\n";
	cout << "=============================================================";
	cout << "\n\n\t\t   1. Unos smjestaja\n\n\t\t   2. Ispis smjestaja\n\n\t\t   3. Povratak";
	cout << "\n\n=============================================================\n";
	cout << "\n\nVas izbor: ";
}

void korisnickiMeni() {
	system("cls");
	cout << "\n\t\t   KORISNICKI MENI\n";
	cout << "=============================================================";
	cout << "\n\n\t\t   1. Ispis smjestaja\n\n\t\t   2. Rezervacija\n\n\t\t   3. Pretraga\n\n\t\t   4. Moji podaci";
	cout << "\n\n\t\t   5. Promjena passworda\n\n\t\t   6. Povratak";
	cout << "\n\n=============================================================\n";
	cout << "\n\nVas izbor: ";
}

void korisnickaPretraga() {
	system("cls");
	cout << "\n\t\t   PRETRAGA SMJESTAJA\n";
	cout << "=============================================================";
	cout << "\n\n\t\t   1. Pretraga po gradu\n\n\t\t   2. Pretraga po cijeni";
	cout << "\n\n\t\t   3. Pretraga po broju kreveta\n\n\t\t   4. Povratak";
	cout << "\n\n=============================================================\n";
	cout << "\n\nVas izbor: ";
}