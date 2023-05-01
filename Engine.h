#pragma once
#include <SFML/Graphics.hpp>
#include<memory>
#include"AssetManager.h"
#include"Animator.h"
#include"Player.h"

class Engine
{
private:
	AssetManager manager;

	std::unique_ptr<sf::RenderWindow> window = std::make_unique < sf::RenderWindow>(sf::VideoMode(1280, 720), L"Les abeiiles au travaille", sf::Style::Default);
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(1280, 720));
//sf::Texture background_texture;
	Player bee = Player(*window);

	sf::RectangleShape drop;
	sf::Time tm;


void input();
void update(sf::Time const& deltaTime);
void draw();

public:

	Engine();
	void run();

};