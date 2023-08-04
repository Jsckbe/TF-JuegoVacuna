#pragma once
#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
private:
	int type;
	//0 -> Horizontal
	//1 -> Vertical
	//2 -> Presuit
public:
	Enemy(int w, int h, int type) : Entity(w, h) {
		this->type = type;
		x = rand() % 200 + 500;
		y = rand() % 30 * 10;
		dx = dy = 5;
		z = 1.0;
	}
	~Enemy() {}

	void move(Graphics^ g, Player* player) {
		int i = rand() % 4;

		switch (type)
		{
		case 0: //Horizontal
			if (x + w * z > g->VisibleClipBounds.Width || x < 0) dx *= -1; // Bounce
			if (dx > 0) idy = 2;	// Right
			else idy = 1;			// Left
			x += dx;
			break;

		case 1: //Vertical
			if (y + h * z > g->VisibleClipBounds.Height || y < 0) dy *= -1; // Bounce
			if (dy > 0) idy = 0;	// Down
			else idy = 3;			// Up
			y += dy;
			break;

		case 2: //Persuit
			if (x == player->getX()) x += 0;
			else if (x > player->getX()) {
				x -= dx;
				idy = 1; // Left
			}
			else if (x < player->getX()) {
				x += dx;
				idy = 2; // Rigth
			}

			if (y == player->getY()) y += 0;
			else if (y > player->getY()) {
				y -= dy;
				idy = 3; // Up
			}
			else if (y < player->getY()) {
				y += dy;
				idy = 0; // Down
			}
		}
		idx++;
		if (idx > 3) idx = 0;
	}

};
