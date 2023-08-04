#pragma once
#include <iostream>
using namespace System::Drawing;

class Entity
{
protected:
	int x, y;
	int w, h;
	int dx, dy;
	int idx, idy;
	float z;
	bool visible;
public:
	Entity(int w, int h) {
		this->w = w;
		this->h = h;
		idx = idy = 0;
		visible = true;
	}
	~Entity() {}

	void draw(Graphics^ g, Bitmap^ sprite) {
		Rectangle sectionShown = Rectangle(idx * w, idy * h, w, h);
		Rectangle zoom = Rectangle(x, y, w * z, h * z);
		g->DrawImage(sprite, zoom, sectionShown, GraphicsUnit::Pixel);
	}
	virtual void move() {}

	int getX() { return x; }
	int getY() { return y; }
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
	Rectangle getRectangle() { return Rectangle(x, y, w * z, h * z); }
};