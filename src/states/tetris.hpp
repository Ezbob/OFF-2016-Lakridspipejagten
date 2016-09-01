#ifndef UUID_2DF3C36F_5E29_4D28_A292_D92217A6B786
#define UUID_2DF3C36F_5E29_4D28_A292_D92217A6B786

#include <SFML/Graphics.hpp>
#include <vector>
#include "game_state.hpp"

class GameStateTetris : public GameState {
public:
	GameStateTetris(Game * g);
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	virtual void reset();
	typedef std::vector<std::vector<int>> matrix;

	void draw_matrix(GameStateTetris::matrix block, size_t x, size_t y, sf::Color c);

private:

	sf::Texture background_texture;
	sf::Texture frame_texture;
	sf::Sprite frame;
	sf::Sprite background;

	bool settled;
	matrix current_block;
	matrix next_block;
	matrix world;
	size_t x;
	size_t y;

	bool get_new_block = true;

};

#endif
