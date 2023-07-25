#include <iostream>

using namespace std;

int x;

class kSpoljasnja 
{
public:
	int y;
	class kUnutrasnja 
	{
		void funkcija(int i, kSpoljasnja* pok) 
		{
			//y = 0; //greska
			pok->y = i;
			::x = 0;
			x = i;

		}	
	};
};

void main()
{
	kSpoljasnja oS;
	//kUnutrasnja oU; // greska
	kSpoljasnja::kUnutrasnja oU;
}