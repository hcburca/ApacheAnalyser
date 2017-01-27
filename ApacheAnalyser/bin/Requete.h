/*************************************************************************
                 	Requete - Interface de la classe Requete
	La classe Requete offre une représentation simplifiée d'une Requete GET
				telle que présente dans une ligne de log Apache
                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/


//---------- Interface de la classe <Requete> (fichier Requete.h) ----------------
#if ! defined ( REQUETE_H )
#define REQUETE_H

using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <set>
//------------------------------------------------------------- Constantes
const string adresseRacine="http://intranet-if.insa-lyon.fr";
const set <string> extensionsImageJsCss = {"ICO", "JPG", "PNG", "BMP","GIF","TIF","CSS","JS"};


//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Requete>
//
//
//------------------------------------------------------------------------

class Requete
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
   string ObtenirIP() const;
   // Mode d'emploi : Renvoie l'adresse IP du visiteur
   
   unsigned int ObtenirHeure()const;
   // Mode d'emploi : Renvoie l'heure à laquelle a été passée la Requete
   

   
   unsigned int ObtenirCodeHTTP()const;
    // Mode d'emploi : Renvoie le code HTTP associé à la requete 
   
	string ObtenirURI() const;	
	 // Mode d'emploi : Renvoie une chaine de caractere correspondant à la 
	 // page consernée par la requête.

	string ObtenirReferent()const;
	 // Mode d'emploi : Renvoie une chaine de caractere correspondant à la 
	 // page référente de la page consernée par la requête. Si la page est située
	 // sur un autre site, on ne renvoie que le nom de domaine du site, sinon que 
	 // son emplacement par rapport à la racine
    // Contrat :
    //  
    
    
    bool AUneExtensionImgCssJS()const;
    // Mode d'emploi : Renvoie Vrai si la requete porte sur un document Web
    // au format Image, CSS ou Javascript. Les extensions en questions sont
    // contenus dans le set extensionsImageJsCss
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Requete ( const Requete & uneRequete );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Requete (string ligneDeLog);
    // Mode d'emploi : Permet de construire l'objet Requete 
    // à partir d'une ligne de log Apache fournie en paramétre
    //
    // Contrat : La ligne de log doit être valide 
    //

    virtual ~Requete ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string logname;
    string username;
    string gmt;
	string ressource;
	string referenceur;
	string ip;
	string dateEtHeure;
	string typeDeRequete;
    string protocol;
	unsigned int codeHTTP;
    unsigned int dataSize;
	string navigateur;
	string extensionRessource;
	
};

//-------------------------------- Autres définitions dépendantes de <Requete>

#endif // Requete_H

