#pragma once
#include "Entity.h"

class Patient : public Entity
{
public:
	Patient(int w, int h) : Entity(w, h) {
		x = rand() % 852;
		y = rand() % 422;
		idx = idy = 0;
		visible = true;
		z = 1.0;
	}
	~Patient() {}
};