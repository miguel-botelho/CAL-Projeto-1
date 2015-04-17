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
#include <sstream>

class ReadMap{
private:
	vector<Locals*> interestPoints;
	vector<string> lines;
	vector<int> attractionLines;
public:
	ReadMap(); //filename?
	bool loadFile(string filename);
	Locals addInterestPoint(Locals ip); // return NULL if added, ip if false
	vector<string> getLines();
	vector<int> getAttractionLines();
	bool loadInterestPoints();
	pair<long,long> loadInterestPointCoord(int line);
	vector<Locals*> getInterestPoints();
	string getCoordWord(string text,int begin);
	string getNodeID(string text,int begin);
	long double stringToDouble(string d);
	long stoi(string num);
	pair<double,double> getCoordsInterestPoints(string id);






};





#endif /* READMAP_H_ */
