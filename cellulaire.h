//
//  Cellulaire.h
//  inf1010_tp1
//
//  Created by Benjamin De Leener on 2015-08-26.
//  Modified by Dominique Beaini on 2015-09-20
//

#ifndef inf1010_tp1_Cellulaire_h
#define inf1010_tp1_Cellulaire_h

#include <string>
#include <iostream>
#include "gps.h"
#include "personne.h"
#include "ObjetConnecte.h"
#include "Routeur.h"

using namespace std;

class Cellulaire : public ObjetConnecte
{
public:
	//TP3
	Cellulaire(unsigned int id, string numeroDeCell);

	void seConnecter(Routeur* routeur);
	void recevoirMessage(const Message& message) const;

	// TP2
	//surcharge de l operateur==
	bool operator==(const Cellulaire& cellulaire2) const;
	//surcharge de l operateur<
	bool operator<(const Cellulaire& cellulaire2) const;
	//surcharge de l operateur=
	Cellulaire& operator=(const Cellulaire& cellulaire2);
	//fonction non membre de surcharge de l operateur<<
	friend ostream& operator<<(ostream& os, const Cellulaire *cellulaire);
	//constructeur par copie
	Cellulaire(const Cellulaire& cellulaire);
	
	
	// TP1
    Cellulaire();
    Cellulaire(string numero);
    ~Cellulaire();
    
    bool estProche(float position);
    
    string getNumero() const;
    void setNumero(string numero);
    
    Personne* getProprietaire() const;
    void setProprietaire(Personne* personne);
    
    float getPosition() const;
    void setPosition(float position);
    
private:
    string numero_;
    
    Personne* proprietaire_;
    
    GPS gps_;
    
};

#endif
