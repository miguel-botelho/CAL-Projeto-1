/*
 * main.cpp
 *
 *  Created on: 16/04/2015
 *      Author: Daniel
 */


#include <iostream>
#include<string>
#include<vector>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"

using namespace std;
using namespace rapidxml;

int main(){
	xml_document<> doc;
	ifstream file("mapa.xml");
	stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	string content(buffer.str());
	doc.parse<0>(&content[0]);




}

