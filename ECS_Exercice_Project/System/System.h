#pragma once
#include <iostream>
#include <vector>
#include "../Entity/Entity.h"
using namespace std;

class System
{
#pragma region Vars
private:
	vector<Entity*> entitys;
#pragma endregion Vars
#pragma region Constructor/Destructor
public:
	System() {}
	System(vector<Entity*> _entitys);
	~System();
#pragma endregion Constructor/Destructor
#pragma region Methods
public:
	inline void AddEntity(Entity* _entity) { entitys.push_back(_entity); }
	inline void AddEntitys(const vector<Entity*>& _entitys) { for (int i = 0 ; i <= _entitys.size(); i++)	entitys.push_back(_entitys[i]); }
	inline void RemoveEntity(Entity* _entity) {	entitys.erase(std::remove_if(entitys.begin(), entitys.end(), [_entity](Entity* e) { return e == _entity; }), entitys.end());}
	inline void RemoveAllEntitys() { entitys.clear(); }
	void StartSystem();
private:
	void Update();
#pragma endregion Methods
#pragma region Operators

public:
	void operator+=(Entity* _entity)		{	AddEntity(_entity);}
	void operator-=(Entity* _entity)		{	RemoveEntity(_entity);}
#pragma endregion Operators
}; 

