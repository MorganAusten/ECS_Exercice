#include <iostream>
#include "System/System.h"

//	Objectif:
//	Impl�mente un mini ECS en C++ qui :
//
//	Cr�e plusieurs entit�s(ex : joueur, ennemis, projectiles).
//	Leur assigne des composants(Position, Vitesse).
//	Ajoute un syst�me qui met � jour leurs positions en fonction de leur vitesse.
//	Affiche la position des entit�s � chaque it�ration.
// 
//	R�gles :
//	Une entit� est juste un ID unique.
//	Un composant est une structure contenant uniquement des donn�es.
//	Un syst�me applique des modifications aux entit�s qui poss�dent certains composants.
// 
//	�tapes � suivre :
//	Cr�er une classe ECS pour g�rer les entit�s et les composants.
//	D�finir deux composants : Position(x, y) et Velocity(vx, vy).
//	Cr�er un syst�me qui met � jour les positions.
//	Simuler plusieurs frames et afficher l'�volution des entit�s.
// 
//	Contraintes :
//	Tu dois utiliser std::unordered_map ou std::vector pour stocker les composants.
//	Tu dois g�rer au moins 3 entit�s avec des vitesses diff�rentes.
//	La simulation doit afficher au moins 5 it�rations.
// 
//	Exemple de sortie attendue :
//
//	Iteration 1 :
//	Entity 0->Position : (2, 3)
//	Entity 1->Position : (9, 5)
//	Entity 2->Position : (4, -2)
//	----------------------
//	Iteration 2 :
//	Entity 0->Position : (4, 6)
//	Entity 1->Position : (8, 5)
//	Entity 2->Position : (8, -4)
//	----------------------
//	...
// 
// 
//  Une fois termin�, assure - toi que :
//
//	Toutes les entit�s se d�placent correctement en fonction de leur vitesse.
//	Le programme fonctionne sans erreur et affiche bien les mises � jour.


int main()
{
	Entity* _player = new Entity(0, "Player", {new Position(10,10), new Speed(2)});
	Entity* _chair = new Entity(1, "Chair");
	Entity* _mom = new Entity(2, "Mom");
	Entity* _dad = new Entity(3, "Dad");
	Entity* _bro = new Entity(4, "Bro");

	//Juste pour tester
	_chair->AddComponent( new Position(10,10));
	_mom->AddComponents({ new Position(47,26), new Speed(2,5)});
	_dad->AddComponents({ new Position(580,-90),new Speed(-1,1) });
	_bro->AddComponents({ new Position(25,1221),new Speed(4,-1) });

	System _system = System(vector<Entity*>({ _player, _chair, _mom, _dad, _bro }));
	_system.StartSystem();
}

