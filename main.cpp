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
#include <stdio.h>        // perror()
#include <stdlib.h>        // ldiv()
#include <time.h>        // clock_nanosleep()
#include <unistd.h>
#include <conio.h>
#include <windows.h>

using namespace std;
using namespace rapidxml;

int main(){

	clock_t begin, end;
	double time_spent;

	cout << "File begin"<<'\n';
	ReadMap mapa;
	begin = clock();
	mapa.loadFile("mapa.txt");
	mapa.loadInterestPoints();
	//Sleep(1000);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout <<"Duracão da execucao: " << time_spent<<endl;
	int x = mapa.getLines().size();
	int y = mapa.getAttractionLines().size();
	for(int i = 0 ; i < mapa.getAttractionLines().size();i++){
		cout << "Linha numero: "<< mapa.getAttractionLines().at(i)<<'\n';
	}
	cout << "Tamanho: "<< mapa.getInterestPoints().size()<<endl;
	for(int i = 0; i < mapa.getInterestPoints().size();i++){
		cout << mapa.getInterestPoints().at(i)->getName()<<'\n';
	}
	cout << "Numero de linhas: "<< x<<"Numero de atracaoes: "<<y<< endl;
	cout <<"End file reading\n";
	return 0;




}
