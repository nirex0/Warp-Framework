// © 2019 NIREX ALL RIGHTS RESERVED

#include "WContainer.h"
#include "WControlHandler.h"
#include "WRadioButtonHandler.h"

// These need to be initialized before everything else
std::map<W_INT, IControl*> WControlHandler::mtcp = {};
std::set<WRadioButton*> WRadioButtonHandler::strz = {};
std::set<W_INT> WControlHandler::stcz = {};
WTheme WContainer::wTheme = {};

/* EXAMPLE BUTTON */

#include "WButton.h"
WButton* myFirstButton;
WButton* mySecondButton;

/* EXAMPLE TEXTBOX */

#include "WTextBox.h"
WTextBox* myFirstTextBox;


/* EXAMPLE LISTBOX */

#include "WListBox.h"
#include "WListBoxItem.h"

WListBox* myDynamicListBox;

/* EXAMPLE EVENTS */

void myFirstButton_Click(WEntity* sender, WEventArgs* arguments)
{
	myDynamicListBox->CreateItem((wchar_t*)myFirstTextBox->Content().c_str());
}

void mySecondButton_Click(WEntity* sender, WEventArgs* arguments)
{
	// Don't worry, RAII is not being denied!
	myDynamicListBox->RemoveLast();
}

void myFirstTextBox_Click(WEntity* sender, WEventArgs* arguments)
{
	// Clean the content on click!
	myFirstTextBox->Content(L"");
}

/* GRADIENT BACKGROUND */

#include "WContainer.h"
W_COLOR firstColor;
W_COLOR secondColor;
WRectF clientRegion;

// Runs at the start of the application
void WEntry::Start(void)
{
	// Button #1
	myFirstButton = new WButton(100, 100, 150, 200, 10);
	myFirstButton->Content(L"PUSH");
	myFirstButton->MouseDownRegistery()->Register(myFirstButton_Click);

	// Button #2
	mySecondButton = new WButton(100, 230, 150, 330, 11);
	mySecondButton->Content(L"POP");
	mySecondButton->MouseDownRegistery()->Register(mySecondButton_Click);

	// Textbox
	myFirstTextBox = new WTextBox(170, 100, 200, 330, 12);
	myFirstTextBox->Content(L"Click and Write (It's not fancy!)");
	myFirstTextBox->MouseDownRegistery()->Register(myFirstTextBox_Click);

	// List box
	myDynamicListBox = new WListBox(230, 100, 500, 330, 1);
	
	// Gradient Background
	firstColor = Graphics()->FromRGBA(10, 10, 10, 1);
	secondColor = Graphics()->FromRGBA(120, 120, 120, 1);

	clientRegion.Top((W_FLOAT)Graphics()->GetClientArea().top);
	clientRegion.Left((W_FLOAT)Graphics()->GetClientArea().left);
	clientRegion.Bottom((W_FLOAT)Graphics()->GetClientArea().bottom);
	clientRegion.Right((W_FLOAT)Graphics()->GetClientArea().right);
}

// Runs every frame pre-render
void WEntry::Update(DELTATIME deltaTime)
{
}

// Runs every frame post-update
void WEntry::Render(DELTATIME deltaTime)
{
	// NOTE: Gradient Background renders before all the controls!
	Graphics()->FillRectLinear(clientRegion,
		Graphics()->FromRGBA(128, 128, 128, 0.7F),
		Graphics()->FromRGBA(0, 0, 0, 0.7F),
		WLinearGradientDirection::WLG_Bottom_Top);
}

// Runs before the application quits 
void WEntry::End(void)
{
	// Free your resources here!

	myFirstButton->Free();
	mySecondButton->Free();
	myFirstTextBox->Free();
	myDynamicListBox->Free();
}
