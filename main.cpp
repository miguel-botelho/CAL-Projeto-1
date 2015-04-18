/*
 * main.cpp
 *
 *  Created on: 16/04/2015
 *      Author: Daniel
 */


#include <iostream>
#include<string>
#include "ReadMap.h"
#include "Locals.h"
#include<vector>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"
#include <time.h>        // clock_nanosleep()
#include<iomanip>


using namespace std;
using namespace rapidxml;

int main(){
	cout << "cenas";

	clock_t begin, end;
	double time_spent;

	cout << "File begin"<<'\n';
	ReadMap mapa;
	begin = clock();
	mapa.loadFile("mapa.txt");
	mapa.loadInterestPoints();
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	cout <<"Duracão da execucao: " << time_spent<<endl;


	cout << "Tamanho: "<< mapa.getInterestPoints().size()<<endl;

	for(int i = 0; i < mapa.getInterestPoints().size();i++){
		cout <<"Nome ponto de interesse: "<< mapa.getInterestPoints().at(i)->getName()<<'\n';
		cout << "Latitude do ponto de interesse: " <<setprecision(10)<<mapa.getInterestPoints().at(i)->getLatitude()<<'\n';
		cout << "Longitude do ponto de interesse: " <<setprecision(10)<<mapa.getInterestPoints().at(i)->getLongitude()<<'\n';
	}
	return 0;





}
