#pragma once
#include "Entity.h"

class Nurse : public Entity
{
	int direction;
public:
	Nurse(int w, int h, int direction) : Entity(w, h) {
		this->direction = direction;
		x = rand() % 852;
		y = rand() % 422;
		dx = dy = 20;
		idx = idx = 0;
		visible = true;
		z = 1.0;
	}
	~Nurse() {}

	void move(Graphics^ g) {
		switch (direction)
		{
		case 0:
			if (x + w * z > g->VisibleClipBounds.Width || x < 0) dx *= -1;
			if (dx > 0) idy = 2;
			else idy = 1;
			x += dx;
			break;
		case 1:
			if (y + h * z > g->VisibleClipBounds.Height || y < 0) dy *= -1;
			if (dy > 0) idy = 0;
			else idy = 3;
			y += dy;
			break;
		}
		idx++;
		if (idx > 3) idx = 0;
	}
};