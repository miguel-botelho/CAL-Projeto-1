/*
 * ReadMap.cpp
 *
 *  Created on: 16/04/2015
 *      Author: Daniel
 */
#include"ReadMap.h"
#include <fstream>
#include <stack>

ReadMap::ReadMap(){

}

bool ReadMap::loadFile(string filename){

	ifstream file;
	file.open(filename.c_str());

	if(!file.is_open())
		return false;


	int line_pos = 0;

	while(!file.eof()){
		string text;
		getline(file,text);
		if(text.find("<relation")!=-1)
			break;
		lines.push_back(text);
		if(text.find("attraction") !=-1){
			attractionLines.push_back(line_pos);
		}
		line_pos++;
	}
	file.close();
	loadInterestPoints();
	return true;
}


vector<string> ReadMap::getLines(){
	return lines;
}

vector<int> ReadMap::getAttractionLines(){
	return attractionLines;
}

bool ReadMap::loadInterestPoints(){
	bool cond = true;
	for(int i = 0; i < attractionLines.size();i++ ){
		int line_pos = attractionLines.at(i);
		string name;
		pair<int,int> coords = loadInterestPointCoord(line_pos);
		while(cond){
			int pos = lines.at(line_pos).find("name");
			if(pos !=-1){ // encontra a palavra name
				pos+=9; //somar a tamanho de NAME +
				while(true){
					char letter = lines.at(line_pos).at(pos);
					if(letter == '"'){
						cond = false;
						break;
					}
					name+= letter;
					pos++;

				}
			}
			line_pos--;
		}
		cond = true;
		interestPoints.push_back(new Locals(name,0,0));
	}
}

pair<int,int> ReadMap:: loadInterestPointCoord(int line){

	pair<int,int> coord;
	//primeiro = lat segund = lon
	while(true){
		int lat=lines.at(line).find("lat");
		int lon =lines.at(line).find("lon");
		if(lat !=-1 && lon!=-1 ){ //encontrou lat e long
			string primeiro = getCoordWord(lines.at(line),lat);
			string segundo = getCoordWord(lines.at(line),lon);
			coord.first=
		}
		line--;
	}
}

vector<Locals*> ReadMap::getInterestPoints(){
	return interestPoints;
}

string ReadMap::getCoordWord(string text,int begin){
	begin+=2;
	string result;
	while(true){
		if(text.at(begin)=='"')
			break;
		result+= text.at(begin);
		begin++;
	}
	return result;
}

long double stringToDouble(string d) {
    long double parteDecimal = 0;
    int parteInteira = 0;
    int contador = 0;
    int digit = 0;
    double ret;
    bool negativo = false;

    if (d[0] == '-') {
        negativo = true;
        digit++;
    }

    while (d[digit] != '.') {
        parteInteira *= 10;
        parteInteira += d[digit] - 48; //Conversoes ASCII -> decimal
        digit++;
    }

    digit++;

    while (digit < d.size()) {
        parteDecimal *= 10;
        parteDecimal += d[digit] - 48; //Conversoes ASCII -> decimal
        contador++;
        digit++;
    }

    parteDecimal /= pow(10, contador);

    ret = parteInteira + parteDecimal;
    if (negativo) {
        ret = -ret;
    }

    return ret;
}



