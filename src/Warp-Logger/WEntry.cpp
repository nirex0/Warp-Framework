#include "WFile.h"
#include "WString.h"

#include <Windows.h>

HANDLE hConsole;

// Pass			10	: 0
// Info			8	: 1
// Debug		15	: 2
// Message		15	: 3
// Warning		14	: 4
// Trace		9	: 5 
// Error		12	: 6
// Fatal		207	: 7

void XPrint(std::string text, WORD color)
{
	SetConsoleTextAttribute(hConsole, color);
	std::cout << text;
	SetConsoleTextAttribute(hConsole, 15);
	return;
}

bool Parse(std::string message)
{
	WString parser;
	std::vector<std::string> vecS = parser.Split(message, "::");

	if (vecS.size() < 2)
		return false;
	int level = std::stoi(vecS[1]);

	switch (level)
	{
	case 0:
	{
		XPrint("[", 15);
		XPrint("P", 10);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 10);
		break;
	}
	case 1:
	{
		XPrint("[", 15);
		XPrint("I", 8);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 8);
		break;
	}
	case 2:
	{
		XPrint("[", 15);
		XPrint("D", 15);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 15);
		break;
	}
	case 3:
	{
		XPrint("[", 15);
		XPrint("M", 15);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 15);
		break;
	}
	case 4:
	{
		XPrint("[", 15);
		XPrint("W", 14);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 14);
		break;
	}
	case 5:
	{
		XPrint("[", 15);
		XPrint("T", 9);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 9);
		break;
	}
	case 6:
	{
		XPrint("[", 15);
		XPrint("E", 12);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 12);
		break;
	}
	case 7:
	{
		XPrint("[", 15);
		XPrint("F", 207);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 207);
		break;
	}
	default:
		break;
	}
}

auto main(int argc, char** argv) -> int
{
	// Console
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle("Warp Logging Utility");

	WFile logF;
	logF.WriteAllText("tmpWlog.wlog", "");
	std::vector<std::string>* currentCmd = new std::vector<std::string>();
	
	while (true)
	{		
		// Format: (std::string)time::(int)LEVEL::(std::string)msg
		if (currentCmd->size() > 0)
		{
			for (int i = 0; i < currentCmd->size(); i++)
			{
				Parse(currentCmd->at(i));
			}

			logF.WriteAllText("tmpWlog.wlog", "");
			delete currentCmd;
			currentCmd = new std::vector<std::string>();
		}
		else
		{
			continue;
		}
	}

	return false;
}
