//
//  personne.h
//  inf1010_tp1
//
//  Created by Benjamin De Leener on 2015-08-26.
//  Modified by Dominique Beaini on 2015-09-20
//

#ifndef inf1010_tp1_personne_h
#define inf1010_tp1_personne_h

#include <string>
#include <iostream>

using namespace std;

class Personne
{
public:
	/// TP2
	//surcharge de l operateur==
	bool operator==(const Personne& personne2);
	//surcharge de l operteur<
	bool operator<(const Personne& personne2);
	//Methode non membre de surcharge de l operateur<<
	friend ostream& operator<<(ostream& os, const Personne * personne);


	/// TP1
	Personne();
	Personne(string prenom, string nom, unsigned int age);
	~Personne();

	string getNom() const;
	void setNom(string nom);
	string getPrenom() const;
	void setPrenom(string prenom);
	unsigned int getAge() const;
	void setAge(unsigned int age);

	bool estALaMaison() const;
	void setEstALaMaison(bool estmaison);

	void attribuerCellulaire(string numeroCellulaire);
	string getNumeroCellulaire() const;




private:
	string nom_;
	string prenom_;
	unsigned int age_;
	bool estALaMaison_;

	string numeroCellulaire_;
};

#endif