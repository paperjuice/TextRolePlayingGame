#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <SDL.h>

struct Position{
	int x, y;
};

struct Rotation
{
	int z;
};

struct Scale {
	int x,y; 
};

class Entity {
public:
	Entity(int pos_x,
		     int pos_y,
		     int rotation,
		     int scale_x,
		     int scale_y,
		     SDL_Renderer* renderer);

	Position get_position() { return m_position; }
	Scale get_scale() { return m_scale; }
	Rotation get_rotation() { return m_rotation; }


private:
	Position m_position;
	Rotation m_rotation;
	Scale m_scale;

	




};



#endif