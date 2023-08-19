#pragma once
class kLekovi
{
	char pSifra[15];
	char pNaziv[20];
public:
	kLekovi() {}
	float fFormirajCenu(float pFabCena, float pProc, float pRabat) const;
	virtual void  fUpisivanje();
	virtual void  fIspisivanje() const;
	virtual int  fKupovina(int pDana) { return 0; }
	~kLekovi() {}
};
