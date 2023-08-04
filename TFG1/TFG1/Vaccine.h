#pragma once
#include "Entity.h"

class Vaccine : public Entity
{
private:
	char direction;
public:
	Vaccine(int w, int h, int x, int y, char direction) : Entity(w, h) {
		this->x = x;
		this->y = y;
		dx = dy = 40;
		this->direction = direction;
		z = 0.3;
	}
	~Vaccine() {}

	void move(Graphics^ g) {
		if (direction == 'S')
		{
			y += dy;
			idy = 1;
			idx = 1;
		}

		if (direction == 'W')
		{
			y -= dy;
			idy = 0;
			idx = 1;
		}

		if (direction == 'A')
		{
			x -= dx;
			idy = 1;
			idx = 0;
		}

		if (direction == 'D')
		{
			x += dx;
			idy = 0;
			idy = 0;
		}
	}

	int getXW() { return x + w * 0.03; }
	int getYH() { return y + h * 0.03; }
};