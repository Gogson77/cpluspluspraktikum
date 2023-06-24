#pragma once
#include <string>
typedef enum eStimulans {
	Da, Ne
};

class kTakmicenje
{
public:
	string pUcesnik;
	int pMjesto;
	int pOsnova;
	float pVrijednost;
	eStimulans pDoping;
	kTakmicenje( 
		string pU,
		int pM,
		int pO,
		float pV,
		eStimulans pD
	);
	int fNagrada();
	~kTakmicenje();
};

