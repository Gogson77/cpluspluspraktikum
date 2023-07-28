// Definicija klase vremenskih intervala
#include <iostream>

using namespace std;

class kVreme
{
public:
	long t = 0; // vreme u sekundama

	friend kVreme fVreme(int h, int m, int s);				// Sastavljanje vremena
	friend kVreme fVreme(long  s);					// Sekunde u vreme
	friend int fSati(kVreme v);						// Sati u vremenu
	friend int fMinuti(kVreme v);					// Minute u vremenu
	friend int fSekundi(kVreme v);					// Sekunde u vremenu
	friend long fVremeUSek(kVreme v);				// Vreme u sekunde

	friend kVreme operator + (const kVreme& v);			// +v
	friend kVreme operator - (const kVreme& v);			// -v
	friend kVreme operator + (const kVreme& v, const kVreme& w);	// v + w
	friend kVreme operator - (const kVreme& v, const kVreme& w);	// v - w
	friend kVreme operator * (const kVreme& v, const int k);		// v * w
	friend kVreme operator / (const kVreme& v, const int k);		// v / w
	kVreme operator ++ () { ++t; return *this; }					// ++ t
	kVreme operator ++ (int) { kVreme w = *this; t++; return w; }		// t ++
	kVreme operator -- () { --t; return *this; }					// -- t
	kVreme operator -- (int) { kVreme w = *this; t--; return w; }			// t --

	kVreme operator += (kVreme v) { t += v.t; return *this; }			// t += v			kVreme operator -= (kVreme v) {t-=v.t; return *this;}			// t -= v
	kVreme operator *= (int k) { t *= k; return *this; }				// t *= v
	kVreme operator /= (int k) { t /= k; return *this; }				// t /= v

	friend int operator <  (const kVreme& v, const kVreme& w); 		// v < w
	friend int operator <= (const kVreme& v, const kVreme& w); 		// v <= w
	friend int operator >  (const kVreme& v, const kVreme& w); 		// v > w
	friend int operator >= (const kVreme& v, const kVreme& w);		// v >= w
	friend int operator == (const kVreme& v, const kVreme& w); 		// v = = w
	friend int operator != (const kVreme& v, const kVreme& w); 		// v != w

	friend istream& operator >> (istream& d, kVreme& v);			// Čitanje
	friend ostream& operator << (ostream& d, const kVreme& v);		// Ispisivanje
};


// Definicije funkcija koje su neposredno ugradjene u kod

inline kVreme fVreme(int h, int m, int s)
{
	kVreme v; v.t = ((h * 60 + m) * 60 + s); return v;
}

inline kVreme fVreme(long s)
{
	kVreme v; v.t = s; return v;
}

inline int fSati(kVreme v) { return v.t / 3600; }
inline int fMinuti(kVreme v) { return (v.t / 60) % 60; }
inline int fSekundi(kVreme v) { return v.t % 60; }
inline long fVremeUSek(kVreme v) { return v.t; }

inline kVreme operator + (const kVreme& v) { return v; }
inline kVreme operator - (const kVreme& v) { kVreme w; w.t = -v.t; return w; }
inline kVreme operator + (const kVreme& v, const kVreme& w)
{
	kVreme zbir; zbir.t = v.t + w.t; return zbir;
}
inline kVreme operator - (const kVreme& v, const kVreme& w)
{
	kVreme razlika; razlika.t = v.t - w.t; return razlika;
}
inline kVreme operator * (const kVreme& v, const int k)
{
	kVreme proizvod; proizvod.t = v.t * k; return proizvod;
}
inline kVreme operator / (const kVreme& v, const int k)
{
	kVreme kolicnik; kolicnik.t = v.t / k; return kolicnik;
}

inline int operator <  (const kVreme& v, const kVreme& w) { return v.t < w.t; }
inline int operator <= (const kVreme& v, const kVreme& w) { return v.t <= w.t; }
inline int operator >  (const kVreme& v, const kVreme& w) { return v.t > w.t; }
inline int operator >= (const kVreme& v, const kVreme& w) { return v.t >= w.t; }
inline int operator == (const kVreme& v, const kVreme& w) { return v.t == w.t; }
inline int operator != (const kVreme& v, const kVreme& w) { return v.t != w.t; }