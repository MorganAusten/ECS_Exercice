#include "Entity.h"

Entity::Entity(int _id, const string& _name)
{
	id = _id;
	name = _name;
}

Entity::Entity(int _id, const string& _name, const vector<Component*>& _components)
{
	id = _id;
	name = _name;
	components = _components;
}

Entity::~Entity()
{
	for (Component* _component : components)
		delete _component;
	components.clear();
}

void Entity::UpdatePosition()
{
	Position* _position = GetPositionComponent();
	if (_position == nullptr)
		return;

	Speed* _speed = GetSpeedComponent();
	if (_speed != nullptr)
	{
		_position->x += _speed->xSpeed;
		_position->y += _speed->ySpeed;
	}

	cout << name << " Position -> x: " << _position->x << "   y: " << _position->y << endl;
}

#pragma region Components
Position* Entity::GetPositionComponent()
{
	if (!HasComponents())
		return nullptr;

	for (Component*& _component : components)
		if (Position* _position = dynamic_cast<Position*>(_component))
			return _position;

	cout << name + "has no Position component" << endl;
	return nullptr;
}

Speed* Entity::GetSpeedComponent()
{
	if (!HasComponents())
		return nullptr;

	for (Component*& _component : components)
		if (Speed* _speed = dynamic_cast<Speed*>(_component))
			return _speed;

	cout << name + " has no Speed component, " ;
	return nullptr;
}

bool Entity::HasComponents()
{
	if (components.empty())
	{
		cout << name + "has no components" << endl;
		return false;
	}
	return true;
}
#pragma endregion Components
