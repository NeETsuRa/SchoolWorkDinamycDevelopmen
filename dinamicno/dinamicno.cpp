// dinamicno.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Par.h"
#include <iostream>
#include <vector>
using namespace std;

bool vsebuje (vector <CPar> a, CPar b){
	for (int i=0; i<a.size(); i++){
		if (a[i].cena==b.cena && a[i].volumen==b.volumen)
			return true;
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "vnesi stevilo elementov: " << endl;
	int n;
	cin >> n;
	cout << "vnesi volumen: " << endl;
	int V;
	cin >> V;
	vector <CPar> v;
	CPar h;
	for (int i=0; i<n; i++){
		cout << "vnesi volumen " << i << "-tega predmeta:" << endl;
		cin >> h.volumen;
		cout << "vnesi ceno " << i << "-tega predmeta:" << endl;
		cin >> h.cena;
		cout << endl;
		v.push_back(h);
	}
//Faza 1
	vector <CPar> z;
	vector <CPar> *s;
	s=new vector <CPar> [n+1];
	h.cena=0;
	h.volumen=0;

	s[0].push_back(h);
	
	for (int i=1; i<n+1; i++){
		for (int j=0; j<s[i-1].size(); j++){
			h.sestej(v[i-1],s[i-1][j]);
			if (h.volumen <= V)
				z.push_back(h);
		}
		for (int j=0; j<s[i-1].size(); j++){
			s[i].push_back(s[i-1][j]);
		}
		for (int j=0; j<z.size(); j++){
			if (vsebuje(s[i], z[j]));
				s[i].push_back(z[j]);
		}
		z.empty();
	}

// faza 2
	// najveè vreden par shranim v h
	h.volumen=s[n][0].volumen;
	h.cena=s[n][0].cena;
	for (int i=0; i<s[n].size(); i++)
		if (s[n][i].volumen > h.volumen){
			h.volumen = s[n][i].volumen;
			h.cena = s[n][i].cena;
		}


	//iskanje rešitve
	int* polje;
	polje = new int [n+1];
	//rešitev brez izbranih elementov
	for (int i=1; i<n+1; i++)
		polje [i]=0;

	for (int i=(n-1); i>=0; i--){
		if (!vsebuje(s[i],h)){
			polje[i+1]=1;
			h.cena = h.cena-v[i].cena;
			h.volumen = h.volumen-v[i].volumen;
		}
	}

	for (int i=1; i<n+1; i++)
		cout << polje[i] << " ";
	cout << endl;
	cout << s[n][s[n].size()-1].volumen << h.volumen << s[n].size() << endl;



	delete [] s;
	delete [] polje;
	cin.ignore();
	cin.get();
	return 0;
}

