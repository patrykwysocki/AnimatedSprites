#include "Swordmanship.h"
#include <Idle.h>

Swordmanship::Swordmanship()
{
}

Swordmanship::~Swordmanship()
{
}

void Swordmanship::idle(Animation* a)
{
	std::cout << "Swordmanship -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
