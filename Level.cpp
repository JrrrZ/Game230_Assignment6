#include "Level.h"
using namespace sf;
using namespace gm;


Level::Level(int map[5][7]) {
	int index = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			if (map[i][j] != 0) {
				bricks.push_back(new Brick(Vector2f(i*90, j*20), Vector2f(90, 20), map[i][j], index));
				index++;
			}
		}
	}
}

std::vector<Brick*> Level::GetBricks() {
	return bricks;
}

void Level::update(sf::RenderWindow& window, float deltaTime, SquareBall* ball) {
	for (int i = 0; i < bricks.size(); i++) {
		Brick* b = bricks[i];
		if (b->collide(ball->getCollider())) {
			b->SetHealth(b->GetHealth() - 1);
			if (b->GetHealth() == 0) {
				b->Kill();
				bricks.erase(bricks.begin() + b->GetID());
			}
		}
	}
}

void Level::render(sf::RenderWindow& window, float deltaTime) {
	for (int i = 0; i < bricks.size(); i++) {
		bricks[i]->render(window, deltaTime);

	}
}

// void reset();

// Destructor
Level::~Level() {

}