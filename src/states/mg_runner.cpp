#include "mg_runner.hpp"
#include "stone.hpp"
#include "assets.hpp"

void MiniGameRunner::draw(const float dt) {
	game->window.clear(sf::Color::White);

	// Draw background, runner, stones
	game->window.draw(back);
	runner.draw(game->window);
	for (auto& stone : stones) {
		stone.draw(game->window);
	}

	// Draw highscore
	this->game->window.draw(text);
}

template<class T1, class T2> bool isIntersecting(T1& mA, T2& mB) {
	return mA.right() >= mB.left() && mA.left() <= mB.right()
		&& mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

void MiniGameRunner::testCollision(Stone& stone, Runner& runner) {
	if (!isIntersecting(stone, runner))
		return;

	// Collision
	std::cerr << "GAME OVER with score " << score << std::endl;
	game->popState();
}

void MiniGameRunner::update(const float dt) {
	runner.update(dt);
	for (auto& stone : stones) {
		stone.update(dt);
		testCollision(stone, runner);
		stone.setVelocity(-runner.velocity.x/10, 0);
	}
	// Update background
	back_pos += runner.velocity.x * dt;
	back.setTextureRect(sf::IntRect(back_pos, 0, 800, 600));

	// Update score
	score++;
	text.setString("Highscore: " + std::to_string(score));
}

void MiniGameRunner::handleInput() {
	sf::Event event;

	while (this->game->window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				game->window.close();
				break;

			case sf::Event::Resized:
				//view.setSize(event.size.width, event.size.height);
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					game->window.close();
				else if (event.key.code == sf::Keyboard::S)
					game->window.setFramerateLimit(5);
				runner.handleInputPressed(event.key.code);
				break;

			case sf::Event::KeyReleased:
				runner.handleInputReleased(event.key.code);
				break;

			default:
				break;
		}
	}
}

MiniGameRunner::MiniGameRunner(Game *game) {
	this->game = game;

	back.setTexture(assets::background, true);

	for (int i=0; i<1; i++)
		stones.emplace_back(800 + 800*i, 585);

	text.setFont(assets::font_main);
	text.setString("Highscore: ");
	text.setCharacterSize(30);
	text.setColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);
	text.setPosition(10,10);

	runner.scale(2.f, 2.f);
	runner.speed = .05;
	for (auto& stone : stones) {
		stone.speed = 0.05;
	}

}


void MiniGameRunner::reset() {
}
