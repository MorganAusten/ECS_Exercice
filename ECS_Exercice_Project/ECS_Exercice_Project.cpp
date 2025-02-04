#include <iostream>
#include "System/System.h"

//	Objectif:
//	Implémente un mini ECS en C++ qui :
//
//	Crée plusieurs entités(ex : joueur, ennemis, projectiles).
//	Leur assigne des composants(Position, Vitesse).
//	Ajoute un système qui met à jour leurs positions en fonction de leur vitesse.
//	Affiche la position des entités à chaque itération.
// 
//	Règles :
//	Une entité est juste un ID unique.
//	Un composant est une structure contenant uniquement des données.
//	Un système applique des modifications aux entités qui possèdent certains composants.
// 
//	Étapes à suivre :
//	Créer une classe ECS pour gérer les entités et les composants.
//	Définir deux composants : Position(x, y) et Velocity(vx, vy).
//	Créer un système qui met à jour les positions.
//	Simuler plusieurs frames et afficher l'évolution des entités.
// 
//	Contraintes :
//	Tu dois utiliser std::unordered_map ou std::vector pour stocker les composants.
//	Tu dois gérer au moins 3 entités avec des vitesses différentes.
//	La simulation doit afficher au moins 5 itérations.
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
//  Une fois terminé, assure - toi que :
//
//	Toutes les entités se déplacent correctement en fonction de leur vitesse.
//	Le programme fonctionne sans erreur et affiche bien les mises à jour.


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

