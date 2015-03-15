#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include "klasy.h"

using namespace std;

int main()
{
	int power=1;
	while(power==1)
	{
	cout<<"----------------------"<<endl;
	cout<<"Wybierz opcje."<<endl<<"1.Dodaj pracownika."<<endl<<"2.Usun pracownika"<<endl<<"3.Policz sumaryczna kwote na pensje."<<endl<<"4.Wyjdz."<<endl;

	vector<Pracownik>lista;
	vector<Kierownik>listak;
	lista.clear();
	listak.clear();
	ifstream plik;
	plik.open("listaPracownikow.txt");

	if (plik!=NULL)
	{
		while(!plik.eof())
		{
			string a, b, c, d;
			int e,f;
			plik>>a;
			if(a=="KIEROWNIK")
			{
				plik>>f;
				plik>>b;
				plik>>c;
				plik>>e;
				plik>>d;
				Kierownik x;
				x.ustawStan(a);
				x.ustawPrac(f);
				x.ustawImie(b);
				x.ustawNazw(c);
				x.ustawStaz(e);
				x.ustawAdres(d);
				listak.push_back(x);
			}
			else
			{
				plik>>b;
				plik>>c;
				plik>>e;
				plik>>d;
				Pracownik x;
				x.ustawStan(a);
				x.ustawImie(b);
				x.ustawNazw(c);
				x.ustawStaz(e);
				x.ustawAdres(d);
				lista.push_back(x);
			}
		}
	}
	plik.close();

	
	int wybor=0;
	cin>>wybor;
	cin.ignore(100,'\n');

	switch(wybor)
	{
	case 1:
		{
			string praco;
			cout<<"Podaj stanowisko pracownika: ";
			cin>>praco;
			if(praco=="KIEROWNIK")
			{
				Kierownik nowy;
				nowy=dodajPracK();			
				nowy.ustawStan(praco);
				listak.push_back(nowy);
			}
			else
			{
				Pracownik nowy;
				nowy=dodajPrac();
				nowy.ustawStan(praco);
				lista.push_back(nowy);
			}

			ofstream plik1;
			plik1.open("listaPracownikow.txt");
			for(int i=0; i<lista.size(); i++)
			{
				plik1<<lista[i].outStan()<<" "<<lista[i].outImie()<<" "<<lista[i].outNazw()<<" "<<lista[i].outStaz()<<" "<<lista[i].outAdres()<<endl;
			}
			for(int i=0; i<listak.size()-1; i++)
			{
				plik1<<listak[i].outStan()<<" "<<listak[i].outPrac()<<" "<<listak[i].outImie()<<" "<<listak[i].outNazw()<<" "<<listak[i].outStaz()<<" "<<listak[i].outAdres()<<endl;
			}
			plik1<<(listak.back()).outStan()<<" "<<(listak.back()).outPrac()<<" "<<(listak.back()).outImie()<<" "<<(listak.back()).outNazw()<<" "<<(listak.back()).outStaz()<<" "<<(listak.back()).outAdres();
			plik1.close();
			break;
		}
	case 2:
		{
			string a, b, c;
			cout<<"Podaj dane pracownika do usuniecia. Imie: ";
			cin>>a;
			cout<<"Nazwisko: ";
			cin>>b;
			cout<<"Stanowisko: ";
			cin>>c;

			if(c=="KIEROWNIK")
			{
				for(int i=0; i<listak.size(); i++)
				{
					if((listak[i].outImie()).compare(a)==0 && (listak[i].outNazw()).compare(b)==0)
						listak.erase(listak.begin()+i);
				}
			}
			else
			{
				for(int i=0; i<lista.size(); i++)
				{
					if((lista[i].outImie()).compare(a)==0 && (lista[i].outNazw()).compare(b)==0 && (lista[i].outStan()).compare(c)==0)
						lista.erase(lista.begin()+i);
				}

			}

			ofstream plik1;
			plik1.open("listaPracownikow.txt");
			for(int i=0; i<lista.size(); i++)
			{
				plik1<<lista[i].outStan()<<" "<<lista[i].outImie()<<" "<<lista[i].outNazw()<<" "<<lista[i].outStaz()<<" "<<lista[i].outAdres()<<endl;
			}
			for(int i=0; i<listak.size()-1; i++)
			{
				plik1<<listak[i].outStan()<<" "<<listak[i].outPrac()<<" "<<listak[i].outImie()<<" "<<listak[i].outNazw()<<" "<<listak[i].outStaz()<<" "<<listak[i].outAdres()<<endl;
			}
			plik1<<(listak.back()).outStan()<<" "<<(listak.back()).outPrac()<<" "<<(listak.back()).outImie()<<" "<<(listak.back()).outNazw()<<" "<<(listak.back()).outStaz()<<" "<<(listak.back()).outAdres();		
			plik1.close();
			break;
		}
	case 3:
		{
			int pensjaSuma=0;

			for(int i=0; i<lista.size(); i++)
			{
				if(lista[i].outStan()=="PREZES")
					pensjaSuma+=20000;
				else if(lista[i].outStan()=="PRACOWNIK")
				{
					pensjaSuma+=2000+(75*lista[i].outStaz());
					if((lista[i].outAdres()).find("Poznan")!=0)
						pensjaSuma+=100;
				}
				else if(lista[i].outStan()=="PORTIER")
					pensjaSuma+=1500;
			}

			for(int i=0; i<listak.size(); i++)
			{
				pensjaSuma+=5000+(100*listak[i].outStaz())+(50*listak[i].outPrac());
			}

			cout<<"Sumaryczna pensja firmy wynosi: "<<pensjaSuma<<endl;

			break;
		}
	case 4:
		{
			power=0;
			break;
		}
	default:
		{
			cout<<"Nie ma operacji o podanym numerze."<<endl;
		}
	}
	}
	return 0;
}