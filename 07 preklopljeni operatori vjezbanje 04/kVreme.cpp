#include "kVreme.h"
#include <iostream>

istream& operator >> (istream& d, kVreme& v)
{
	int h=0, m=0, s=0; d >> h >> s; v = fVreme(h, m, s); return d;
}

ostream& operator << (ostream& d, const kVreme& v)
{
	kVreme w = v;
	if (w.t < 0) { d << "-"; w = -w; }
	return d << fSati(w) << ":" << fMinuti(w) << ":" << fSekundi(w);
}
