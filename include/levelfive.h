#ifndef LEVELFIVE_H
#define LEVELFIVE_H

#include "../include/curupira.h"
#include "../include/politico.h"
#include "../include/urubu.h"
#include "../include/stage.h"

class LevelFive : public Stage
{
public:
	LevelFive();
	~LevelFive();

	void generateEnemies();
	void generateCivilians();
	void drawScenarioRelativeImages();

	void defineBackground();
	void generatePlatform();
	void generateSecondLayer();
};

#endif // LEVELFIVE_H