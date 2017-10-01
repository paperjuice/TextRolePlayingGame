#include "entity.h"

Entity::Entity(int pos_x,
			         int pos_y,
			         int rotation,
			         int scale_w,
			         int scale_h) 
  :m_entity_transform({ pos_x, pos_y, scale_w, scale_h }),
	 m_rotation(rotation)
{
}

void Entity::set_position(const int& x, const int& y)
{
  m_entity_transform.x = x;
  m_entity_transform.y = y;
}

void Entity::set_rotation(const int& angle)
{
  m_rotation = angle;
}

void Entity::set_scale(const int& w, const int& h)
{
  m_entity_transform.w = w;
  m_entity_transform.h = h;
}