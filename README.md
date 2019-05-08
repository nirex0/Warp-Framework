# Warp-Framework (Beta)
Welcome to warp, a framework to create powerful and rich GUI C++ Single-Window applications using Direct2D API

STATUS
======

**🔧 CURRENTLY WORKING ON: DOCUMENTATION**

DOCUMENTATION
=============

The documentation is finally being worked on, you can find it in the [docs](/docs) folder.

- [Warp Async](https://github.com/nirex0/Warp-Framework/blob/master/docs/documentation/AS-INDEX.md) 

- [Warp Core](https://github.com/nirex0/Warp-Framework/blob/master/docs/documentation/CORE-INDEX.md)

- Warp Graphics

- Warp Test

- Warp Network

- Warp Utility

PLANS
=====

Since the plan list got a little bigger than I originally expected, I decided it would be best if I 
moved it to another MarkDown (MD) page; You can find it [Here](https://github.com/nirex0/Warp-Framework/blob/master/TODO.md)! 

FRAMEWORK VIEW
==============

#### Warp-Framework
![alt text](https://raw.githubusercontent.com/nirex0/warp-framework/master/repo-resources/warp-000.png)

#### Warp-Logger
![alt text](https://raw.githubusercontent.com/nirex0/warp-framework/master/repo-resources/warp-001.png)

EXAMPLES
========

This is a simple WEntry.cpp example which would be your main starting point of the framework!

It shows you how to create buttons, a textbox, a listbox, and add whatever is in the textbox to the content of the listbox upon clicking the Push button!

To go to the file in the repo click [Here](https://github.com/nirex0/Warp-Framework/blob/master/src/Warp-Framework/WEntry.cpp)!

```cpp
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

/* EXAMPLE TEXTBOX*/

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
```

CONTACT
=======

Nirex.0@gmail.com

COPYRIGHT INFO
==============
MIT License

Copyright (c) 2018 nirex0

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


