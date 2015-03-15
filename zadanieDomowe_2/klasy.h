#ifndef KLASY_H
#define KLASY_H

class Pracownik
{
protected:
	std::string stanowisko;
	std::string imie;
	std::string nazwisko;
	int staz;
	std::string adres;
public:
	void pensja();
	void ustawStan(std::string a);
	void ustawImie(std::string a);
	void ustawNazw(std::string a);
	void ustawStaz(int a);
	void ustawAdres(std::string a);

	std::string outStan();
	std::string outImie();
	std::string outNazw();
	int outStaz();
	std::string outAdres();
};

class Kierownik: public Pracownik
{
private:
	int pracownicy;
public:
	void ustawPrac(int a);
	int outPrac();
};

Pracownik dodajPrac();
Kierownik dodajPracK();

#endif