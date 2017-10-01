#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <SDL.h>


class Entity {
public:
	Entity(int pos_x,
		     int pos_y,
		     int rotation,
		     int scale_w,
		     int scale_h);

	SDL_Rect get_transform() const { return m_entity_transform; }
	int get_rotation() const { return m_rotation; }

  void set_position(const int& x, const int& y);
  void set_rotation(const int& angle);
  void set_scale(const int& x, const int& y);

private:
	int m_rotation;
  SDL_Rect m_entity_transform;
};



#endif