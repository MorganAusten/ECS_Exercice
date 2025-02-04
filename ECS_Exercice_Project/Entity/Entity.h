#pragma once 
#include <iostream>
#include <vector>
#include "../Component/Component.h"
using namespace std;

class Entity
{
#pragma region Vars
private:
	int id;
	string name;
	vector<Component*> components;
#pragma endregion Vars
public:
	Entity(const int _id, const string& _name);
	Entity(const int _id, const string& _name, const vector<Component*>& _components);
	virtual ~Entity();
public:
	inline const int GetId()const { return id; }
	inline const string& GetName()const { return name; }
	inline void AddComponent(Component* _component) { components.push_back(_component); }
	inline void AddComponents(std::vector<Component*> _components) { for (Component* _component : _components) components.push_back(_component); }
	void UpdatePosition();
private:
	Position* GetPositionComponent();
	Speed* GetSpeedComponent();
	bool HasComponents();
};