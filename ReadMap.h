/*
 * ReadMap.h
 *
 *  Created on: 16/04/2015
 *      Author: Daniel
 */

#ifndef READMAP_H_
#define READMAP_H_

#include<vector>
#include "Locals.h"

class ReadMap{
private:
	vector<Locals*> interestPoints;
	ifstream file;
public:
	ReadMap(string); //filename?
	Locals addInterestPoint(Locals ip); // return NULL if added, ip if false






};



#endif /* READMAP_H_ */
