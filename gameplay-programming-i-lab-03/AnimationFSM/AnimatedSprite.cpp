#include <AnimatedSprite.h>

AnimatedSprite::AnimatedSprite() 
{
	m_current_frame = 0;
	bool m_sJumping = false;
	bool m_climbing = false;
	bool m_shoveling = false;
	bool m_swordmanship = false;
	bool m_hammering = false;
	bool m_idle = true;
}

AnimatedSprite::AnimatedSprite(const sf::Texture& t) : Sprite(t), m_current_frame(0), m_time(seconds(0.5f)) {}

AnimatedSprite::AnimatedSprite(const sf::Texture& t, const sf::IntRect& rect) : Sprite(t), m_current_frame(0), m_time(seconds(0.5f)) {
	m_frames.push_back(rect);
}

AnimatedSprite::~AnimatedSprite() {}

const sf::Clock& AnimatedSprite::getClock() {
	return m_clock;
}

const sf::Time& AnimatedSprite::getTime() {
	return m_time;
}

const vector<IntRect>& AnimatedSprite::getFrames() {
	return m_frames;
}

const IntRect& AnimatedSprite::getFrame(int n) {
	return m_frames[n];
}

void AnimatedSprite::addFrame(IntRect& frame) {
	m_frames.push_back(frame);
}

const int AnimatedSprite::getCurrentFrame() {
	return m_current_frame;
}

void AnimatedSprite::update()
{
	m_frames.clear();
	switch (m_animationType)
	{
	default:
	case 0:
		addFrame(sf::IntRect(3, 3, 84, 84));
		addFrame(sf::IntRect(88, 3, 84, 84));
		addFrame(sf::IntRect(173, 3, 84, 84));
		addFrame(sf::IntRect(258, 3, 84, 84));
		addFrame(sf::IntRect(343, 3, 84, 84));
		addFrame(sf::IntRect(428, 3, 84, 84));
		break;
	case 1:
		addFrame(sf::IntRect(3, 88, 84, 84));
		addFrame(sf::IntRect(88, 88, 84, 84));
		addFrame(sf::IntRect(173, 88, 84, 84));
		addFrame(sf::IntRect(258, 88, 84, 84));
		addFrame(sf::IntRect(343, 88, 84, 84));
		addFrame(sf::IntRect(428, 88, 84, 84));
		break;
	case 2:
		addFrame(sf::IntRect(3, 173, 84, 84));
		addFrame(sf::IntRect(88, 173, 84, 84));
		addFrame(sf::IntRect(173, 173, 84, 84));
		addFrame(sf::IntRect(258, 173, 84, 84));
		addFrame(sf::IntRect(343, 173, 84, 84));
		addFrame(sf::IntRect(428, 173, 84, 84));
		break;
	case 3:
		addFrame(sf::IntRect(3, 258, 84, 84));
		addFrame(sf::IntRect(88, 258, 84, 84));
		addFrame(sf::IntRect(173, 258, 84, 84));
		addFrame(sf::IntRect(258, 258, 84, 84));
		addFrame(sf::IntRect(343, 258, 84, 84));
		addFrame(sf::IntRect(428, 258, 84, 84));
		break;
	case 4:
		addFrame(sf::IntRect(3, 343, 84, 84));
		addFrame(sf::IntRect(88, 343, 84, 84));
		addFrame(sf::IntRect(173, 343, 84, 84));
		addFrame(sf::IntRect(258, 343, 84, 84));
		addFrame(sf::IntRect(343, 343, 84, 84));
		addFrame(sf::IntRect(428, 343, 84, 84));
		break;
	case 5:
		addFrame(sf::IntRect(3, 428, 84, 84));
		addFrame(sf::IntRect(88, 428, 84, 84));
		addFrame(sf::IntRect(173, 428, 84, 84));
		addFrame(sf::IntRect(258, 428, 84, 84));
		addFrame(sf::IntRect(343, 428, 84, 84));
		addFrame(sf::IntRect(428, 428, 84, 84));
		break;
	}
	if (m_clock.getElapsedTime() > m_time)
	{
		if (m_frames.size() > m_current_frame + 1)
		{
			m_current_frame++;
		}
		else {
			m_current_frame = 0;
		}
		m_clock.restart();
	}

}

void AnimatedSprite::setAnimation(int animationType)
{
	m_animationType = animationType;
}

