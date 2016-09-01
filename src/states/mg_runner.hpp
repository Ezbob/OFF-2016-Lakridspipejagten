#ifndef MiniGameRunner_HPP
#define MiniGameRunner_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "game_state.hpp"
#include "runner.hpp"
#include "stone.hpp"

class MiniGameRunner : public GameState {
	private:
	
	sf::Texture tex_back;
	sf::Sprite back;
	float back_pos{0.f};
	Runner runner;
	std::vector<Stone> stones;
	int score = 0;
	sf::Text text;
	sf::Font font;
	int num_stones{2};

	public:

	MiniGameRunner(Game *game);
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	virtual void testCollision(Stone& stone, Runner& runner);
	virtual void reset();

};

#endif
