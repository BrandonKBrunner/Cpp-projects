#include <string>
#include <random>
#include <sstream>
#include <string>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

struct Event
{
	std::string name;
	std::string description;
	int changeHealth = 0;
	int changeGold = 0;
	int changeDamage = 0;
};

struct Player
{
	int health = 10;
	int gold = 0;
	int damage = 5;
} player;

std::string displayString()
{
	std::stringstream ss;

	ss << "Health: " << player.health << std::endl <<
		"Gold: " << player.gold << std::endl <<
		"Damage: " << player.damage << std::endl;

	return ss.str();
}

const Event AMBUSH = 
			{ "Ambush", 
			"From the shadows, many arrows fly in your direction! \n\nYou are struck!",
			-5, 0, 0 };

const Event APOTHECARY = 
			{ "Apothecary", 
			"You come across a room filled with shelves, bottles, herbs, and other substances. You decide to collect one of the potions on the shelf and find... \n\nYou feel invigorated.", 
			4, 0, 0 };

const Event INFUSION = 
			{ "Infusion", 
			"You come across a room filled with shelves, bottles, herbs, and other substances. You decide to collect one of the potions on the shelf and find... \n\nYou feel stronger.", 
			0, 0, 1 };

const Event TROVE = 
			{ "Trove", 
			"Around the corner you see glints of light, reflections from your torch. \n\nYou discover a small pile of gold!", 
			0, 5, 0 };

const Event ARMORY = 
			{ "Armory", 
			"You come across a sturdy door with iron bracing. Beyond you find arms enough to supply a small militia. \n\nYou should be able to make good use of these.", 
			0, 0, 2 };

const Event GAMEOVER =
			{ "Gameover",
			"Despite your best efforts, the challenge was too great. \n\nYou have fallen!"
			};

const Event WIN =
			{ "Win",
			"After many challenges and trials, you have reached your destination! \n\nRevel in the loot and glory you have obtained during this adventure."
			};

const int nEvents = 5;

const Event events[] = {AMBUSH, APOTHECARY, INFUSION, TROVE, ARMORY};



Event getEvent()
{
	int eventIndex = rand() % nEvents;

	return events[eventIndex];
}

void updatePlayer(const Event& event)
{
	player.health += event.changeHealth;
	player.gold += event.changeGold;
	player.damage += event.changeDamage;
}

int displayEvent(const Event& event)
{
	return MessageBoxA(0, ("Player Stats\n" + displayString() + "\n\n" + event.description).c_str(), "Pop-Up Adventure", MB_OK);
}



int runEvent(int messageResult, int eventCount)
{
	const Event& event = getEvent();
	updatePlayer(event);

	messageResult = displayEvent(event);

	if (player.health <= 0)
	{
		messageResult = -1;
		displayEvent(GAMEOVER);
	}
	else if (eventCount >= 10)
	{
		messageResult = -1;
		displayEvent(WIN);
	}

	return messageResult;
}