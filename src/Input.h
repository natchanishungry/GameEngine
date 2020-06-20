#pragma once
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>

#include "json.hpp"

using nlohmann::json;

struct Input
{
	enum tag {
		keyboard, mousebutton, joystickaxis, joystickbutton
	};

	tag pctag;
	union KeyboardMouseInput
	{
		sf::Keyboard::Key key;
		sf::Mouse::Button mouseButton;
	} keyboardmouseinput;

	tag xboxtag;
	union JoystickInput
	{
		struct JoystickAxis
		{
			enum class Direction { POSITIVE = 1, NEGATIVE = -1 };

			sf::Joystick::Axis axis;
			Direction dir;
		} joystickaxis;

		unsigned int button;
	} joystickinput;

	//static bool load(const std::string& filePath);
};

void from_json(const json& j, Input& ac);
void to_json(json& j, const Input& ac);
