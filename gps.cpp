/*
Fichier: gps.cpp
Auteur(s): Benjamin De Leener
Date de creation: 26 aout 2015
Date de modification: 28 aout 2015
Description: Cette classe represente un systeme GPS. Elle permet de localiser une personne dans l'espace, grace a un simulateur de position.
*/

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "gps.h"

#define PROXIMITE 3

using namespace std;

GPS::GPS() : position_(0.0)
{
	srand((time(NULL)));
	time(&temps_);  /* get current time; same as: timer = time(NULL)  */
}


GPS::GPS(float position) : position_(position)
{
	srand((time(NULL)));
	time(&temps_);  /* get current time; same as: timer = time(NULL)  */
}


GPS::~GPS()
{
}


bool GPS::estProche(float position)
{
	bool resultat_position = false;
	simulateurDePosition();
	if (position_ >= position - PROXIMITE && position_ <= position + PROXIMITE)
		resultat_position = true;
	return resultat_position;
}

/*
Cette fonction simule la position du GPS dans le temps et dans l'espace. La position est calculée en additionnant la position actuel par la multiplication du temps avec une vitesse aléatoire entre 3 et 5.
*/
void GPS::simulateurDePosition()
{
	time_t temps_actuel = time(NULL);
	float vitesse = 1.0;
	//float vitesse = 3.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (5.0 - 3.0)));
	position_ += (temps_actuel - temps_) * vitesse * 0.01;
}


float GPS::getPosition() const
{
	return position_;
}


void GPS::setPosition(float position)
{
	position_ = position;
}