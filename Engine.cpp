#include "Engine.h"

void Engine::input()
{
	sf::Event event_play;

	while (window->pollEvent(event_play))
	{
		if (event_play.key.code = sf::Keyboard::Escape) { window->close(); }
		if (event_play.type == sf::Event::KeyPressed)
		{
			switch (event_play.key.code)
			{
			case sf::Keyboard::Right: {bee.move(Player::direction::right); break; }
			case sf::Keyboard::Left: {bee.move(Player::direction::left); break; }
			case sf::Keyboard::Up: {bee.move(Player::direction::up); break; }
			case sf::Keyboard::Down: {bee.move(Player::direction::down); break; }

			default:
				break;
			}
		}
		if (event_play.type == sf::Event::KeyReleased)
		{
			switch (event_play.key.code)
			{
			case sf::Keyboard::Right: {bee.setStepx(0); break; }
			case sf::Keyboard::Left: {bee.setStepx(0); break; }
			case sf::Keyboard::Up: {bee.setStepy(0); break; }
			case sf::Keyboard::Down: {bee.setStepy(0); break; }

			default:
				break;
			}
		}
	}
}



void Engine::update(sf::Time const& deltaTime)
{
	bee.update(deltaTime);

	tm += deltaTime;
	if (tm > sf::milliseconds(3))
	{
		auto mybee = bee.getPlayer();
		drop.move(0, 1);

		if (drop.getPosition().y > window->getSize().y - drop.getGlobalBounds().height) drop.setPosition(drop.getPosition().x, 0);

		if (drop.getGlobalBounds().intersects(mybee.getGlobalBounds()) && (!bee.getDead()))
		{
			drop.setPosition(drop.getPosition().x, 0);
			bee.setDead(true);
		}

		tm = sf::milliseconds(0);

	}
}

void Engine::draw()
{
	window->clear();
	window->draw(background);
	auto drawBee = bee.getPlayer();
	window->draw(drawBee);
	window->draw(drop);
	window->display();

}

Engine::Engine()
{
//background_texture.loadFromFile("image/background.jpg");
	background.setTexture(&AssetManager::GetTexture("image/background.jpg"));
		drop.setTexture(&AssetManager::GetTexture("image/blob.png"));
		drop.setSize(sf::Vector2f(10, 20));
		drop.setPosition(500, 0);
	}

void Engine::run()
{
	sf::Clock montre;
	while (window->isOpen())
	{
		sf::Time dt = montre.restart();

		input();
		update(dt);
		draw();

	}

}
