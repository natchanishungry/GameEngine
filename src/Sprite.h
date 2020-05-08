#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include <string>

#include "json.hpp"
#include "Asset.h"

using nlohmann::json;

using TextureId = std::string;
using IntRect = sf::IntRect;

struct Sprite : virtual Asset
{
	TextureId texId;
	IntRect texRect;
	float scale; //this can eventually be stored in a transform

	sf::Sprite m_sprite;

	~Sprite() override = default;

};

void to_json(json& j, const Sprite& p);
void from_json(const json& j, Sprite& p);

