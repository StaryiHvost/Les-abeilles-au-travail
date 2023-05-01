#include "Player.h"

void Player::move(direction direction, float mystep)
{
	if (!dead)
	{
		switch (direction)
		{
		case direction::up: {if (SpritePlayer.getPosition().y > borders.y) { step.y = -mystep; } break; }
		case direction::down: {if (SpritePlayer.getPosition().y < borders.maxy) { step.y = mystep; } break; }
		case direction::right: {if (SpritePlayer.getPosition().x < borders.maxx) step.x = mystep;
			if (AnimPlayer.GetCurrentAnimationName() != "idleForward") AnimPlayer.SwitchAnimation("idleForward");
			break; }
		case direction::left: {if (SpritePlayer.getPosition().x > borders.x) step.x = -mystep;
			if (AnimPlayer.GetCurrentAnimationName() != "idleBack") AnimPlayer.SwitchAnimation("idleBack");
			break;
		}
		default:
			break;
		}
	}
}
void Player::update(sf::Time const& deltaTime)
{
	if (!dead) AnimPlayer.Update(deltaTime);


	timeUpdate += deltaTime;

	if (timeUpdate > sf::milliseconds(3))
	{

		timeUpdate = sf::milliseconds(0);

		if (!dead) {
			SpritePlayer.move(step.x, step.y);
			if (SpritePlayer.getPosition().x < borders.x) {
				SpritePlayer.setPosition(borders.x, SpritePlayer.getPosition().y);
			}
			if (SpritePlayer.getPosition().x > borders.maxx - SpritePlayer.getGlobalBounds().width)
			{
				SpritePlayer.setPosition(borders.maxx - SpritePlayer.getGlobalBounds().width, SpritePlayer.getPosition().y);
			}
			if (SpritePlayer.getPosition().y < borders.y) { SpritePlayer.setPosition(SpritePlayer.getPosition().x, borders.y); }
			if (SpritePlayer.getPosition().y > borders.maxy - SpritePlayer.getGlobalBounds().height)
			{
				SpritePlayer.setPosition(SpritePlayer.getPosition().x, borders.maxy - SpritePlayer.getGlobalBounds().height);
			}
		}
		else
		{
			if (SpritePlayer.getRotation() == 0) {
				SpritePlayer.setPosition(SpritePlayer.getPosition().x + SpritePlayer.getGlobalBounds().height, SpritePlayer.getPosition().y);
				SpritePlayer.setRotation(90);
			}
			SpritePlayer.move(0, 1);
			if (SpritePlayer.getPosition().y > borders.maxy) {
				SpritePlayer.setRotation(0);
				SpritePlayer.setPosition(pos.x, pos.y); dead = false;
			}
		}
	}

}
void Player::setStepx(float x)
{
	step.x = x;
}

void Player::setStepy(float y)
{
	step.y = y;
}

void Player::setBordersPlayer(float x, float y, float maxx, float maxy)
{
	borders.x = x;
	borders.y = y;
	borders.maxx = maxx;
	borders.maxy = maxy;
}