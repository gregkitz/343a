#ifndef _CLASSICS_H
#define _CLASSICS_H
#include "dvdmedia.h"


class Classic : public DvdMedia {



public:
	Classic(); 
	Classic(string a, string b, string c, string d) : DvdMedia(a, b, c, d){}
	Classic(int a, int b, string c) {
		releaseMonth = a; 
		year = b; 
		mainActor = c; 

	} 

private:

	int releaseMonth; 
	string mainActor; 



};




#endif