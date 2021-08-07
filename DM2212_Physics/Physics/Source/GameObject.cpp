
#include "GameObject.h"

GameObject::GameObject(GAMEOBJECT_TYPE typeValue)
	: type(typeValue),
	scale(1, 1, 1),
	angle(0.f),
	gravity(false),
	health(1.0f),
	customMesh(nullptr),
	attachment(nullptr),
	isMoveable(true),
	justDamagedByCollision(false),
	active(false),
	mass(1.f),
	dir(1, 0, 0),
	momentOfInertia(1.f),
	angularVelocity(0.f),
	invincible(false),
	origin(Vector3()),
	maxSpringLength(10),
	springMagnitude(1),
	powerupLocked(false),
	cooldown(0.0) //Move to flipper class?
{
}

GameObject::~GameObject()
{
	if (attachment != nullptr)
	{
		delete attachment;
	}
}

bool GameObject::hasCustomMesh() {
	return (customMesh != nullptr);
}

void GameObject::setCustomMesh(Mesh* cM) {
	customMesh = cM;
}

void GameObject::setActive(bool active) {
	this->active = active;
	if (active == false) {
		customMesh = nullptr;
		maxHealth = 0;
		health = 0;
		vel = Vector3(0, 0, 0);
		normal = Vector3(0, 0, 0);
		mass = 1.0;
		type = GameObject::GO_NONE;
		gravity = false;
		invincible = false;
	}
}

bool GameObject::isActive() {
	return active;
}

void GameObject::setHealth(float health) {
	if (health > this->maxHealth) this->maxHealth = health;
	this->health = health;
}

float GameObject::getHealthPercentage()
{
	return health / maxHealth * 100;
}

void GameObject::subtractHealth(float amt) {
	if (amt > 0)
	{
		health -= amt;
		if (health < 0) health = 0;
	}
	else {
		amt + 1;
	}
}

void GameObject::addHealth(float amt) {
	health += amt;
	if (health > maxHealth)
		maxHealth = health;
}

float GameObject::getHealth() {
	return health;
}

float GameObject::getMaxHealth() {
	return maxHealth;
}

bool GameObject::isDamaged() {
	return !(health > maxHealth - Math::EPSILON);
}

