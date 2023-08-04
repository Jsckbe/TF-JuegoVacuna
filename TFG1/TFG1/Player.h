#pragma once
#include "Entity.h"

class Player : public Entity
{
private:
	int hp;
	char direction;
public:
	Player(int w, int h) :Entity(w, h) {
		x = 100;
		y = 100;
		dx = dy = 15;
		direction = 'S';
		z = 0.5;
		hp = 5;
	}
	~Player() {}

	void move(Graphics^ g, char key) {
		switch (key)
		{
		case 'A':
			if (x > 0) {
				idy = 1;
				x -= dx;
				direction = 'A';
			}
			break;

		case 'D':
			if (x + w * z < g->VisibleClipBounds.Width) {
				idy = 3;
				x += dx;
				direction = 'D';
			}
			break;

		case 'W':
			if (y > 0) {
				idy = 2;
				y -= dy;
				direction = 'W';
			}
			break;

		case 'S':
			if (y + h * z < g->VisibleClipBounds.Height) {
				idy = 0;
				y += dy;
				direction = 'S';
			}
			break;
		}
		idx++;
		if (idx > 6) idx = 0;
	}

	void still() { idx = 0; }
	void decreaseHp() { hp -= 1; }
	int getHp() { return hp; }
	char getDirection() { return direction; }
	int getX() { return x; }
	int getY() { return y; }
};