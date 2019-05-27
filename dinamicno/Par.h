#pragma once

class CPar
{
public:
	int cena;
	int volumen;

	void odstej (CPar a);
	void sestej (CPar a, CPar b);
	CPar(int v, int c);

	CPar(void);
	~CPar(void);
};
