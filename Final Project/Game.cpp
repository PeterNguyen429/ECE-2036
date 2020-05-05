//
// Created by bswenson3 on 11/9/16.
//

#include "Game.h"

Game::Game() :
	m_window(sf::VideoMode(1000, 1000), "Cool Game")
{
	//load the player
	//m_player.load("/Users/peternguyen/Desktop/ECE2036/2036SkeletonCmake/build/Mario.png");
	//m_player.setScale(.25f);
	//m_game_sprites.push_back(&m_player);

	m_kirby.load("/Users/peternguyen/Desktop/ECE2036/2036SkeletonCmake/build/kirby.png");
	m_kirby.setScale(0.5f);
	m_kirby.setPosition(50.0f, 800.0f);
	m_game_sprites.push_back(&m_kirby);

	m_ness.load("/Users/peternguyen/Desktop/ECE2036/2036SkeletonCmake/build/Ness.png");
	m_ness.setScale(0.75f);
	m_ness.setPosition(350.0f,800.0f);
	m_game_sprites.push_back(&m_ness);

	m_dragonair.load("/Users/peternguyen/Desktop/ECE2036/2036SkeletonCmake/build/dragonair.png");
	m_dragonair.setScale(0.75f);
	m_dragonair.setPosition(550.0f, 800.0f);
	m_game_sprites.push_back(&m_dragonair);

	m_dragon.load("/Users/peternguyen/Desktop/ECE2036/2036SkeletonCmake/build/dragonsprites.png");
	m_dragon.setScale(3.0f);
	m_game_sprites.push_back(&m_dragon);

	m_mario.load("/Users/peternguyen/Desktop/ECE2036/2036SkeletonCmake/build/mariosprites.jpeg");
	m_mario.setScale(1.0f);
	m_mario.setPosition(500.f, 300.0f);
	m_game_sprites.push_back(&m_mario);








}

void Game::run() {
	sf::Clock clock;
	sf::Clock clock_dragon;
	sf::Clock clock_mario;
	while (m_window.isOpen()) {
		if (clock_dragon.getElapsedTime().asSeconds() > 1.0f) {
			m_dragon.update(clock_dragon.getElapsedTime().asSeconds());
			sf::Time dragon_update = clock_dragon.restart();
		}
		if (clock_mario.getElapsedTime().asSeconds() > 0.75f) {
			m_mario.updateMario(clock_mario.getElapsedTime().asSeconds());
			sf::Time mario_update = clock_mario.restart();
		}
		sf::Time deltaT = clock.restart();
		processEvents();
		update(deltaT);
		render();
	}
}

void Game::processEvents() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::KeyPressed:
			//handle key down here
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			m_window.close();
			break;
		}
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isDown) {
	if (key == sf::Keyboard::Left)
		m_left = isDown;
	if (key == sf::Keyboard::Right)
		m_right = isDown;
	if (key == sf::Keyboard::Up)
		m_up = isDown;
	if (key == sf::Keyboard::Down)
		m_down = isDown;
}

//use time since last update to get smooth movement
void Game::update(sf::Time deltaT) {
	//Look a vector class!
	sf::Vector2f movement(0.0f, 0.0f);
	if (m_up)
		movement.y -= m_speed;
	if (m_down)
		movement.y += m_speed;
	if (m_left)
		movement.x -= m_speed;
	if (m_right)
		movement.x += m_speed;

	m_player.move(movement * deltaT.asSeconds());

}

void Game::render() {
	m_window.clear();

	for (int i = 0; i < m_game_sprites.size(); i++) {
		m_game_sprites[i]->draw(m_window);
	}

	m_window.display();
}