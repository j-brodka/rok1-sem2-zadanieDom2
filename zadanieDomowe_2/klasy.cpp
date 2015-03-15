#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
#include <functional>
#include "klasy.h"

using namespace std;

void Pracownik::ustawStan(string a)
{
	stanowisko=a;
}
void Pracownik::ustawImie(string a)
{
	imie=a;
}
void Pracownik::ustawNazw(string a)
{
	nazwisko=a;
}
void Pracownik::ustawStaz(int a)
{
	staz=a;
}
void Pracownik::ustawAdres(string a)
{
	adres=a;
}
void Kierownik::ustawPrac(int a)
{
	pracownicy=a;
}
string Pracownik::outStan()
{
	return stanowisko;
}
string Pracownik::outImie()
{
	return imie;
}
string Pracownik::outNazw()
{
	return nazwisko;
}
int Pracownik::outStaz()
{
	return staz;
}
string Pracownik::outAdres()
{
	return adres;
}
int Kierownik::outPrac()
{
	return pracownicy;
}


Pracownik dodajPrac()
{
	string a, b, c;
	int e;
	Pracownik x;
	cout<<"Imie: ";
	cin>>a;
	cout<<"Nazwisko: ";
	cin>>b;
	cout<<"Lata stazu: ";
	cin>>e;
	cout<<"Adres (ulica_numerDomu_kod-pocztowy_miejscowosc)";
	cin>>c;
	x.ustawImie(a);
	x.ustawNazw(b);
	x.ustawStaz(e);
	x.ustawAdres(c);
	return x;
}
Kierownik dodajPracK()
{
	string a, b, c;
	int e,f;
	Kierownik x;
	cout<<"Imie: ";
	cin>>a;
	cout<<"Nazwisko: ";
	cin>>b;
	cout<<"Lata stazu: ";
	cin>>f;
	cout<<"Adres (ulica_numerDomu_kod-pocztowy_miejscowosc): ";
	cin>>c;
	cout<<"Liczba pracownikow, ktorymi zarzadza: ";
	cin>>e;
	x.ustawPrac(e);
	x.ustawImie(a);
	x.ustawNazw(b);
	x.ustawStaz(f);
	x.ustawAdres(c);
	return x;
}

