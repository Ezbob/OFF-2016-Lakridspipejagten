#ifndef UUID_7654AC26_B92D_4C5C_A0CE_06B7F0E0C8CF
#define UUID_7654AC26_B92D_4C5C_A0CE_06B7F0E0C8CF

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "animation.hpp"

namespace assets {

	extern sf::Font font_main;
	extern sf::Font font_description;

	extern sf::Texture world;
	extern sf::Texture back_sky;
	extern sf::Texture back_mountains;
	extern sf::Texture back_trees;
	extern sf::Texture back_grass;
	extern sf::Texture ball;
	extern sf::Texture runner;
	extern sf::Texture player_texture;
	extern sf::Texture rock;
	extern sf::Texture pibe;
	extern sf::Texture gave;

	extern sf::Sprite ball_sprite;
	extern sf::Sprite runner_sprite;
	extern sf::Sprite back_sky_sprite;
	extern sf::Sprite back_mountains_sprite;
	extern sf::Sprite back_trees_sprite;
	extern sf::Sprite back_grass_sprite;
	extern sf::Sprite world_sprite;
	extern sf::Sprite player_sprite;
	extern sf::Sprite rock_sprite;
	extern sf::Sprite pibe_sprite;
	extern sf::Sprite gave_sprite;
	extern animation * runner_animation;
}


#endif
