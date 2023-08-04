#pragma once
#include "Player.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Enemy.h"
#include "Patient.h"
#include "Vaccine.h"
#include <vector>

using namespace std;

class Controller
{
private:
	Player* player;
	vector<Enemy*> enemies;
	vector<Doctor*> doctors;
	vector<Nurse*> nurses;
	vector<Vaccine*> vaccines;
	vector<Patient*> patients;

	int nPatients;
	int nEnemies;
	int points;

public:
	Controller(Bitmap^ spritePlayer, Bitmap^ spriteEnemy, Bitmap^ spritePatient) {
		player = new Player(spritePlayer->Width / 10, spritePlayer->Height / 4);
		nPatients = 6;
		nEnemies = 10;
		points = 0;
			
		for (int i = 0; i < nEnemies; i++)
		{
			Enemy* e = new Enemy(spriteEnemy->Width / 4, spriteEnemy->Height / 4, rand() % 3);
			enemies.push_back(e);
		}
		
		for (int i = 0; i < nPatients; i++)
		{
			Patient* p = new Patient(spritePatient->Width / 4, spritePatient->Height / 4);
			patients.push_back(p);
		}
	}
	~Controller() {}

	void addVaccine(Vaccine* v) {
		vaccines.push_back(v);
	}
	void addEnemies(Enemy* e) {
		enemies.push_back(e);
	}
	void addPatient(Patient* p) {
		patients.push_back(p);
	}
	void addDoctor(Doctor* d) {
		doctors.push_back(d);
	}
	void addNurse(Nurse* n) {
		nurses.push_back(n);
	}
	
	void drawEverything(Graphics^ g, Bitmap^ spritePlayer, Bitmap^ spriteAlly, Bitmap^ spriteAlly2, Bitmap^ spriteEnemy, Bitmap^ spritePatient, Bitmap^ spriteVaccine) {
		player->draw(g, spritePlayer);
		for (int i = 0; i < doctors.size(); i++)
		{
			doctors[i]->draw(g, spriteAlly);
		}
		for (int i = 0; i < nurses.size(); i++)
		{
			nurses[i]->draw(g, spriteAlly2);
		}
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i]->draw(g, spriteEnemy);
		}
		for (int i = 0; i < patients.size(); i++)
		{
			patients[i]->draw(g, spritePatient);
		}
		for (int i = 0; i < vaccines.size(); i++)
		{
			vaccines[i]->draw(g, spriteVaccine);
		}
	}

	void moveEverything(Graphics^ g) {
		for (int i = 0; i < doctors.size(); i++)
		{
			doctors[i]->move(g);
		}
		for (int i = 0; i < nurses.size(); i++)
		{
			nurses[i]->move(g);
		}
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i]->move(g, player);
		}
		for (int i = 0; i < vaccines.size(); i++)
		{
			vaccines[i]->move(g);
		}
	}

	void collision(Graphics^ g) {
		// Verification
		// Borders
		for (int i = 0; i < vaccines.size(); i++)
		{
			if (vaccines[i]->getX() <= 0 || vaccines[i]->getXW() >= g->VisibleClipBounds.Width ||
				vaccines[i]->getY() <= 0 || vaccines[i]->getYH() >= g->VisibleClipBounds.Height)
				vaccines[i]->setVisible(false);

		}
		 // Patients - Vaccines
		for (int i = 0; i < patients.size(); i++)
		{
			for (int j = 0; j < vaccines.size(); j++)
			{
				if (patients[i]->getRectangle().IntersectsWith(vaccines[j]->getRectangle())) {
					patients[i]->setVisible(false);
					vaccines[j]->setVisible(false);
					points++;
				}
			}
		}
		// Allies - Enemies
		for (int i = 0; i < doctors.size(); i++)
		{
			for (int j = 0; j < enemies.size(); j++)
			{
				if (doctors[i]->getRectangle().IntersectsWith(enemies[j]->getRectangle()))
					enemies[i]->setVisible(false);
			}
		}
		for (int i = 0; i < nurses.size(); i++)
		{
			for (int j = 0; j < enemies.size(); j++)
			{
				if (nurses[i]->getRectangle().IntersectsWith(enemies[j]->getRectangle()))
					enemies[i]->setVisible(false);
			}
		}
		// Player - Enemies
		for (int i = 0; i < enemies.size(); i++)
		{
			if (player->getRectangle().IntersectsWith(enemies[i]->getRectangle()))
			{
				enemies[i]->setVisible(false);
				player->decreaseHp();
			}
		}

		// Elimination
		for (int i = 0; i < enemies.size(); i++)
		{
			if (!enemies[i]->getVisible()) enemies.erase(enemies.begin() + i);
		}
		for (int i = 0; i < patients.size(); i++)
		{
			if (!patients[i]->getVisible()) patients.erase(patients.begin() + i);
		}
		for (int i = 0; i < vaccines.size(); i++)
		{
			if (!vaccines[i]->getVisible()) vaccines.erase(vaccines.begin() + i);
		}
	}
	Player* getPlayer() { return player; }
	int getNPatients() { return patients.size(); }
	int getPoints() { return points; }
};