#include "GameOverMenu.h"
#include "ColoredText.h"

using namespace std;
using namespace l2::rendering;
using namespace l2::gameobjects;

static const string GAMEOVER_HEADER_RESOURCE = "GameOverTitle.txt";
static const string PLAY_BUTTON_RESOURCE     = "PlayButton.txt";
static const string EXIT_BUTTON_RESOURCE     = "ExitButton.txt";

static const string PLAY_COMPONENT_NAME      = "Play Button";
static const string EXIT_COMPONENT_NAME      = "Exit Button";

UIComponent::MenuActionReturn GameOverMenu::PlayCallback()
{
	return RequestFwdTransition;
}

UIComponent::MenuActionReturn GameOverMenu::ExitCallback()
{
	return RequestBwdTransition;
}

GameOverMenu::GameOverMenu(shared_ptr<l2r::ConsoleWindow> parentWindow) : Menu(RESPATH_GAMEOVER_MENU)
{
	uint16_t tX, tY, tW, tH;
	drawable_.GetDrawableSpace(tX, tY, tW, tH);

	ColoredText * title = new ColoredText();
	title->SetParentWindow(window_);
	if (title->LoadFromFile(GAMEOVER_HEADER_RESOURCE))
	{
		{
			uint16_t x, y, w, h;
			title->GetDrawable().GetDrawableSpace(x, y, w, h);
			ColorizedDrawable titleCopy(title->GetDrawable());
			titleCopy.SetDrawableSpace(tX, tY, w, h);
			title->SetDrawable(titleCopy);
			title->SetOffsets((tW - w) / 2, 1);
			title->SetColor(Colorizer::Color::Red);
			title->GetDrawable().GetDrawableSpace(tX, tY, tW, tH);
		}
		AddChild(title);
	}
	else
		delete title;

	/////////////////////////////////////////////////////////////
	MenuItem * playButton = new MenuItem(parentWindow, PLAY_BUTTON_RESOURCE);
	playButton->SetComponentName(PLAY_COMPONENT_NAME);
	playButton->SetComponentCallback(std::bind<MenuActionReturn>(&GameOverMenu::PlayCallback, this));

	ColorizedDrawable cpy(playButton->GetDrawable());
	cpy.SetColor(drawable_.GetDrawableColor().foregroundColor, drawable_.GetDrawableColor().backgroundColor);
	playButton->SetDrawable(cpy);

	playButton->SetOffsets(tX, tY + tH + 2);
	AddChild(playButton);
	///////////////////////////////////////////////////////////
	MenuItem * exitButton = new MenuItem(parentWindow, EXIT_BUTTON_RESOURCE);
	exitButton->SetComponentName(EXIT_COMPONENT_NAME);
	exitButton->SetComponentCallback(std::bind<MenuActionReturn>(&GameOverMenu::ExitCallback, this));
	AddChild(exitButton);

	cpy = exitButton->GetDrawable();
	cpy.SetColor(drawable_.GetDrawableColor().foregroundColor, drawable_.GetDrawableColor().backgroundColor);
	exitButton->SetDrawable(cpy);
	{
		uint16_t x, y, w, h;
		exitButton->GetDrawable().GetDrawableSpace(x, y, w, h);
		exitButton->SetOffsets(tX + tW - w, tY + tH + 2);
	}
}

const string GameOverMenu::RESPATH_GAMEOVER_MENU = "GameOverMenu.txt";

