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

	//clock_t begin, end;
	//double time_spent;

	cout << "File begin"<<'\n';
	ReadMap mapa;
	//begin = clock();
	mapa.loadFile("mapa.txt");
	mapa.loadInterestPointsName();
	cout << "Linha: "<< mapa.getAttractionLines().at(0)<<'\n';
	pair<double,double> m = mapa.loadInterestPointCoord(mapa.getAttractionLines().at(1));
	cout <<"lat: "<<setprecision(10)<< m.first<<endl;
	cout << "lon: "<<setprecision(10)<< m.second<<endl;
	cout << "END!"<<endl;
	return 0;
	//Sleep(1000);
	/*end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout <<"Duracão da execucao: " << time_spent<<endl;
	int x = mapa.getLines().size();
	int y = mapa.getAttractionLines().size();
	cout << "Tamanho: "<< mapa.getInterestPoints().size()<<endl;
	for(int i = 0; i < mapa.getInterestPoints().size();i++){
		cout <<"Nome ponto de interesse: "<< mapa.getInterestPoints().at(i)->getName()<<'\n';
		cout << "Latitude do ponto de interesse: " <<mapa.getInterestPoints().at(i)->getLatitude()<<'\n';
		cout << "Longitude do ponto de interesse: " <<mapa.getInterestPoints().at(i)->getLongitude()<<'\n';
	}
	cout << "Numero de linhas: "<< x<<"Numero de atracaoes: "<<y<< endl;
	cout <<"End file reading\n";
	system("pause");
	return 0;*/





}
