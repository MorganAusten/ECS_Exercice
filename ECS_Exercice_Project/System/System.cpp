#include "System.h"
#include <chrono>
#include <thread>
using namespace std::chrono;

System::System(vector<Entity*> _entitys)
{
	entitys = _entitys;
}

System::~System()
{
	for (Entity* _entity : entitys)
		delete _entity;
	entitys.clear();
}

void System::StartSystem()
{
	int _iteration = 0;
	while (true)
	{
		cout << endl << "----Iteration : " << _iteration << " ------" << endl;
		Update();
		++_iteration;
		std::this_thread::sleep_for(seconds(1));
	}
}

void System::Update()
{
	for (Entity* _entity : entitys)
	{
		_entity->UpdatePosition();
	}
}
