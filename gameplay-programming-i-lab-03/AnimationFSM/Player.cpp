#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player()
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s) : m_animated_sprite(s)
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	switch (in.getCurrent())
	{
	case Input::Action::IDLE:
		//std::cout << "Player Idling" << std::endl;
		m_animation.idle();
		break;
	case Input::Action::JUMPING:
		//std::cout << "Player Up" << std::endl;
		m_animation.jumping();
		break;
	case Input::Action::SWORDMANSHIP:
		//std::cout << "Player Left" << std::endl;
		m_animation.swordmanship();
		break;
	case Input::Action::SHOVELING:
		//std::cout << "Player Idling" << std::endl;
		m_animation.shoveling();
		break;
	case Input::Action::CLIMBING:
		m_animation.climbing();
	case Input::Action::HAMMERING:
		m_animation.hammering();
	default:
		break;
	}
}

void Player::update()
{
	//std::cout << "Handle Update" << std::endl;
	m_animated_sprite.update();
}