#include "Hammering.h"
#include <Idle.h>

Hammering::Hammering()
{
}

Hammering::~Hammering()
{
}

void Hammering::idle(Animation * a)
{
	std::cout << "Hammering -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
