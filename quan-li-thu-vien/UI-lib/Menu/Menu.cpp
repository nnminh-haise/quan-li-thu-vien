#include "Menu.h"
#include "../../Helper/Constants.h"

void Menu::UpdateIndicator(int inputKey)
{
	switch (inputKey)
	{
	case (ARROW_KEYS::DOWN):
		this->m_moduleIndicator += 1;
		break;
	case (ARROW_KEYS::UP):
		this->m_moduleIndicator -= 1;
	default:
		break;
	}
}
