#ifndef UUID_6D85E1C5_01DF_4D11_AB49_8F2D6603D018
#define UUID_6D85E1C5_01DF_4D11_AB49_8F2D6603D018

#include <stack>
#include <SFML/Graphics.hpp>

constexpr int WINDOW_WIDTH{800}, WINDOW_HEIGHT{600};

class GameState;

class Game {
	public:
	
	int score_pibe{0};
	int score_gaver{0};
	int children{20};
	sf::Text text_pibe;
	sf::Sprite icon_pibe;
	int currentScore{0}; // deprecated

	std::stack<GameState*> states;
	sf::RenderWindow window;
	
	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	GameState* peekState();

	void gameloop();
	void drawHighscore(sf::RenderWindow &window);

	Game();
	~Game();
};

#endif
