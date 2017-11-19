#include "Shoveling.h"
#include "Idle.h"

Shoveling::Shoveling()
{
}

Shoveling::~Shoveling()
{
}

void Shoveling::idle(Animation * a)
{
	std::cout << "Shoveling -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
