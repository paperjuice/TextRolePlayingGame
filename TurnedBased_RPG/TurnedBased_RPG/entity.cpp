#include "entity.h"

Entity::Entity(int pos_x,
			         int pos_y,
			         int rotation,
			         int scale_x,
			         int scale_y,
	              SDL_Renderer* renderer) 
  :m_position({ pos_x, pos_y }),
	 m_rotation({rotation}),
   m_scale({scale_x, scale_y})
{
}
