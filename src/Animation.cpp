#include "Animation.h"
#include "AnimationFrame.h"
#include "Asset.h"

void to_json(json& j, const Animation& p)
{
	switch (p.mode)
	{
	case animation_mode::loop:
		j["mode"] = "loop";
		break;
	case animation_mode::one_time:
		j["mode"] = "one time";
		break;
	case animation_mode::ping_pong_backward:
		j["mode"] = "ping pong";
		break;
	case animation_mode::ping_pong_forward:
		j["mode"] = "ping pong";
		break;
	}

	int numFrames = static_cast<int>(p.frames.size());
	for (int i = 0; i < numFrames; i++)
	{
		j["sprites"][i] = p.frames[i].sprite;
		j["sprites"][i]["screenOffset"][0] = p.frames[i].screenOffsetX;
		j["sprites"][i]["screenOffset"][1] = p.frames[i].screenOffsetY;
		j["sprites"][i]["duration"] = p.frames[i].duration;
	}
	//j["scale"] = 
}

void from_json(const json& j, Animation& p)
{
	std::string mode = j["mode"].get<std::string>();
	if (mode.compare("loop") == 0) p.mode = animation_mode::loop;
	if (mode.compare("one time") == 0) p.mode = animation_mode::one_time;
	if (mode.compare("ping pong") == 0) p.mode = animation_mode::ping_pong_forward;

	for (auto& jsprite : j["sprites"])
	{
		AnimationFrame af{ jsprite,
						   jsprite["screenOffset"][0].get<int>(),
						   jsprite["screenOffset"][1].get<int>(),
						   jsprite["duration"].get<float>() };
		p.frames.emplace_back(std::move(af));
	}

}

