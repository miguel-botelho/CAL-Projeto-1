/*
 * ReadMap.cpp
 *
 *  Created on: 16/04/2015
 *      Author: Daniel
 */
#include"ReadMap.h"
#include <fstream>
#include <stack>
#include <string>
#include<cmath>
#include<iostream>

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
	for(int i = 0; i < attractionLines.size();i++){

		pair<long,long> coords = loadInterestPointCoord(attractionLines.at(i));
		interestPoints.at(i)->setLatitude(coords.first);
		interestPoints.at(i)->setLongitude(coords.second);
	}
}

pair<long,long> ReadMap:: loadInterestPointCoord(int line){

	pair<long,long> coord;
	//primeiro = lat segund = lon
	while(true){
		long lat=lines.at(line).find("lat");
		long lon =lines.at(line).find("lon");


		if(lat !=-1 && lon!=-1 ){ //encontrou lat e long
			lat+=3;
			lon+=3;
			string primeiro = getCoordWord(lines.at(line),lat);
			string segundo = getCoordWord(lines.at(line),lon);
			coord.first= stringToDouble(primeiro);
			coord.second= stringToDouble(segundo);
			return coord;
		}

		if(lines.at(line).find("way")!= -1){
			line++;
			int x = lines.at(line).find("ref");
			if(x!=-1){
				string id = getNodeID(lines.at(line),x);
				coord = getCoordsInterestPoints(id);
				return coord;
			}
		}
		line--;
	}
}

pair<double,double> ReadMap::getCoordsInterestPoints(string id){
	pair<double,double> coords;
	int line_pos = 0;
	while(true){
		if(lines.at(line_pos).find(id)!=-1){
			int lat_pos,lon_pos;
			lat_pos = lines.at(line_pos).find("lat");
			lat_pos+=3;
			lon_pos = lines.at(line_pos).find("lon");
			lon_pos+=3;

			string primeiro = getCoordWord(lines.at(line_pos),lat_pos);
			string segundo = getCoordWord(lines.at(line_pos),lon_pos);
			coords.first= stringToDouble(primeiro);
			coords.second= stringToDouble(segundo);
			return coords;
		}
		line_pos++;
	}
}

vector<Locals*> ReadMap::getInterestPoints(){
	return interestPoints;
}

string ReadMap:: getNodeID(string text,int begin){
	begin+=5;
		string result;
		while(true){
			if(text.at(begin)=='"')
				break;
			result+= text.at(begin);
			begin++;
		}
		return result;

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

long ReadMap::stoi(string num){
	long res=0;
	for(int i = 0; i < num.length();i++){
		res+= (num.at(i)-'0')*pow(10,num.length()-1-i);
	}
	return res;

}

long double ReadMap::stringToDouble(string d) {
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
