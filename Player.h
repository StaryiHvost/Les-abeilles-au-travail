#pragma once
#include "Animator.h"
class Player
{
private:

	struct Borders
	{
		float x;
		float y;
		float maxx;
		float maxy;
	};

	sf::RenderWindow& window;
	sf::Sprite SpritePlayer;
	Animator AnimPlayer = Animator(SpritePlayer);

	sf::Vector2f step;
	Borders borders{ 0 };
	sf::Vector2f pos;
	sf::Time timeUpdate;
	bool dead = false;

public:
	enum class direction { up, down, right, left };

	Player(sf::RenderWindow& window, sf::Vector2f mypos = sf::Vector2f(90, 365),
		std::string const& texture = "image/SPRITESHEET.png", float time = 0.5,
		sf::Vector2i spriteSize = sf::Vector2i(100, 100), int frame = 6, int stepy = 100) :window(window), pos(mypos)
	{
		SpritePlayer.setPosition(pos.x, pos.y);
		auto& idleForward = AnimPlayer.CreateAnimation("idleForward", texture, sf::seconds(time), true);
		idleForward.AddFrames(sf::Vector2i(0, 0), spriteSize, frame, 1);
		auto& idleBack = AnimPlayer.CreateAnimation("idleBack", texture, sf::seconds(time), true);
		idleBack.AddFrames(sf::Vector2i(0, stepy), spriteSize, frame, 1);

		borders.maxx = static_cast<float>(window.getSize().x);
		borders.maxy = static_cast<float>(window.getSize().y);
	}

	void setStepx(float x);
	void setStepy(float y);
	void move(direction direction, float mystep = 1.0f);
	void update(sf::Time const& deltaTime);
	void setBordersPlayer(float x, float y, float maxx, float maxy);
	void setDead(bool playrdead)
	{
		dead = playrdead;
	}
	bool getDead() const
	{
		return dead;
	}
	sf::Sprite& getPlayer()
	{
		return SpritePlayer;
	}
};

