#include <iostream>
#include "Student.h"

int main()
{
	Student s1;
	s1.prikazPodataka();

	Student s2("Pera","Peric","2020210330",2020);
	s2.prikazPodataka();

	Student s3 = s2;
	s3.prikazPodataka();

	return 0;
}
