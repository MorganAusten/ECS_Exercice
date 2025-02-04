#pragma once
#include <iostream>
using namespace std;

class Component
{
protected:
	string name = "";
public:
	virtual ~Component() {}
	inline string GetName()const { return name; }
};

struct Position :public Component
{
	int x = 0;
	int y = 0;

	Position(const int _x, const int _y)
	{
		name = "Position";
		x = _x;
		y = _y;
	}
	Position(const int _x)
	{
		name = "Position";
		x = _x;
		y = x;
	}
};

struct Speed :public Component
{
	int xSpeed = 0;
	int ySpeed = 0;

	Speed(const int _xSpeed, const int _ySpeed)
	{
		name = "Speed";
		xSpeed = _xSpeed;
		ySpeed = _ySpeed;
	}

	Speed(const int _speed)
	{
		name = "Speed";
		xSpeed = _speed;
		ySpeed = xSpeed;
	}
};
