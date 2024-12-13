#include <iostream>
#include <sstream>
#include <string>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "Events.h"


int gameIntro(int messageResult)
{
	std::string INTRO;
	INTRO = "Welcome to the Pop-Up Adventure! \n\nIn moments you will be sent on the journy of your lifetime through the most dangerous dungeons for loot and glory! \n\nBe warned, there is no guarentee you may come back alive. \n\nAre you ready to partake in this most daring adventure? ";

	messageResult = MessageBoxA(0, INTRO.c_str(), "Pop-Up Adventure", MB_YESNO);

	if (messageResult == 6)
	{
		return MessageBoxA(0, "Let us begin!", "Pop-Up Adventure", MB_OK);
	}
	else if (messageResult == 7)
	{
		return MessageBoxA(0, "The bravest adventurers did not choose the adventurers life. \n\nThe adventurers life chose them!", "Pop-Up Adventure", MB_OK);
	}
}

void gameLoop()
{
	
	int messageResult = -1;
	int eventCounter = 0;

	messageResult = gameIntro(messageResult);

	std::cout << "Message Result: " << messageResult << std::endl;

	while (messageResult > 0)
	{
		eventCounter++;
		messageResult = runEvent(messageResult, eventCounter);	
	}

}

int main() 
{
	


	gameLoop();
	

	return 0;
}