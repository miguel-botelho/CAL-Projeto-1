/*
 * Locals.cpp
 *
 *  Created on: 16/04/2015
 *      Author: Daniel
 */
#include "Locals.h"

Locals::Locals(string name,double latitude,double longitude){

	this->name=name;
	this->latitude =latitude;
	this->longitude=longitude;
}


string Locals::getName(){
	return name;
}
