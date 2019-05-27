#include "StdAfx.h"
#include "Par.h"

CPar::CPar(void)
{
}

CPar::~CPar(void)
{
}

void CPar::odstej (CPar a){
	volumen=volumen-a.volumen;
	cena=cena-a.cena;
}
CPar::CPar(int v, int c){
	volumen=v;
	cena=c;
}

void CPar::sestej(CPar a, CPar b){
	volumen=a.volumen+b.volumen;
	cena=a.cena+b.cena;

}


