#include <Animation.h>
#include <Idle.h>

Animation::Animation()
{
	m_current = new Idle();
}

Animation::~Animation() {}

void Animation::setCurrent(State* s)
{
	m_current = s;
}

State* Animation::getCurrent()
{
	return m_current;
}

void Animation::setPrevious(State* s)
{
	m_previous = s;
}

State* Animation::getPrevious()
{
	return m_previous;
}

void Animation::idle()
{
	m_current->idle(this);
}

void Animation::jumping()
{
	m_current->jumping(this);
}

void Animation::climbing()
{
	m_current->climbing(this);
}

void Animation::shoveling()
{
	m_current->shoveling(this);
}

void Animation::swordmanship()
{
	m_current->swordmanship(this);
}

void Animation::hammering()
{
	m_current->hammering(this);
}
