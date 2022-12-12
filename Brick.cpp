#include "Brick.h"

using namespace sf;
using namespace gm;


BrickType normal_brick = {
		1, // hp
		//&normal_brick_texture, // tex
		Color::White, // col
		//&normal_brick_sound // buf
};

BrickType tough_brick = {
	2, // hp
	//&tough_brick_texture, // tex
	Color::Red, // col
	//&tough_brick_sound // buf
};


Brick::Brick(const Vector2f& position, const Vector2f& size, int t, int index): GameObject(position, size) {
	body.setPosition(position);
	body.setSize(size);
	type = t;
	BrickType brickType;
	if (t == 1) {
		brickType = normal_brick;
	}
	else {
		brickType = tough_brick;
	}
	body.setFillColor(brickType.col);
	health = brickType.hp;
	alive = true;
	id = index;
}

void Brick::update(sf::RenderWindow& window, float deltaTime) {
	
}

void Brick::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

void Brick::setPosition(const Vector2f& position) {
	GameObject::setPosition(position);
	// Don't forget to update the Box's shape position to match the new position
	body.setPosition(position);
	collider.left = position.x;
	collider.top = position.y;
}

void Brick::SetAlive(bool _alive) {
	alive = _alive;
}

bool Brick::IsAlive() const {
	return alive;
}

void Brick::SetHealth(int _health) {
	health = _health;
}

int Brick::GetHealth() const {
	return health;
}

void Brick::Kill() {
	alive = false;
	body.setFillColor(Color::Transparent);
}

int Brick::GetID() {
	return id;
}

// Checks to see if the float rect collider contains a specified point
//bool Box::collide(const Vector2f& point) const {
//	return collider.contains(point);
//}

// Checks to see if the float rect collider intersects another float rect
