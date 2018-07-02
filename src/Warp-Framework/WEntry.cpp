// © 2018 NIREX ALL RIGHTS RESERVED

#include "WContainer.h"

#include "WUserSettings.h"
#include "IControl.h"
#include "WDefines.h"
#include "WButton.h"

#include "WMouseArgs.h"
#include "WControlHandler.h"
#include "WAudio.h"

#include "WColorTransform.h"
#include "WColorTransformArgs.h"

#include <thread>
#include <chrono>
#include <string>

#include "WListBox.h"
#include "WAsyncWorker.h"
#include "WLerp.h"

// WButtonHandler
std::map<W_INT, IControl*> WControlHandler::mtcp = {};
std::set<W_INT> WControlHandler::stcz = {};

WListBox* lbx = new WListBox();
WButton* btnLbl = new WButton();
WButton* btn1 = new WButton();
WButton* btn2 = new WButton();
WButton* btn3 = new WButton();
WButton* btn4 = new WButton();

WButton* zbtn0 = new WButton();
WButton* zbtn1 = new WButton();


WLerp* AsyncWorker;

W_INT shoulddisplace = 0;
bool switcher = 0;
bool keyIsDown = 0;
bool dragmove = 0;
W_FLOAT B = 500;


void MouseClickEvent(WEntity* sender, WEventArgs* args)
{
	WMouseArgs* margs = (WMouseArgs*)args;

	if (margs->Point().Y() < 50 && margs->Point().X() < 1200 && margs->Key() == WMouseKey::MK_LEFT)
	{
		WContainer::DragMove(true);
	}


	keyIsDown = 0;
	delete margs;
}

void MouseClickEventx(WEntity* sender, WEventArgs* args)
{
	WMouseArgs* margs = (WMouseArgs*)args;
	if (keyIsDown == 0)
	{
		shoulddisplace = 0;
	}

	WContainer::DragMove(false);
	delete margs;
}

void BtnBordReg(WEntity* sender, WEventArgs* args)
{
	WButton* btn = (WButton*)sender;
	WMouseArgs* margs = (WMouseArgs*)args;

	//btn->BorderThickness(5);
	//btn->BorderRadius(7);

}

void UnBtnBordReg(WEntity* sender, WEventArgs* args)
{
	WButton* btn = (WButton*)sender;
	WMouseArgs* margs = (WMouseArgs*)args;

	//btn->BorderThickness(2);
	//btn->BorderRadius(5);
}

void BtnColorReg(WEntity* sender, WEventArgs* args)
{
	WButton* btn = (WButton*)sender;
	WMouseArgs* margs = (WMouseArgs*)args;
	if (margs->Key() == WMouseKey::MK_LEFT)
	{
		//btn->BorderBrush(WGraphicsContainer::Graphics()->W_Color({027, 237, 147, 240));

	}
}

void UnBtnColorReg(WEntity* sender, WEventArgs* args)
{
	WButton* btn = (WButton*)sender;
	WMouseArgs* margs = (WMouseArgs*)args;
	if (margs->Key() == WMouseKey::MK_LEFT)
	{

		//btn->BorderBrush(WGraphicsContainer::Graphics()->W_Color({116, 111, 187, 240));
	}
}

#define EXIT_NO_ERR quick_exit(0)
#define EXIT_EXCEPTION quick_exit(1)

W_IMAGE* bmp;

void BTNExit_Click(WEntity* sender, WEventArgs* args)
{
	WButton* btn = (WButton*)sender;
	WMouseArgs* margs = (WMouseArgs*)args;
	if (margs->Key() == WMouseKey::MK_LEFT)
	{
		quick_exit(0);
	}
}

WColorTransform* CT = new WColorTransform(
	WGraphicsContainer::Graphics()->FromRGBA(230, 15, 5),
	WGraphicsContainer::Graphics()->FromRGBA(100, 14, 205),
	0.003f,
	1
);

WColorTransform* XCT = new WColorTransform(
	WGraphicsContainer::Graphics()->FromRGBA(100, 14, 205),
	WGraphicsContainer::Graphics()->FromRGBA(230, 15, 5),
	0.003f,
	1
);

void LEX(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* cargs = (WColorTransformArgs*)args;
	zbtn0->Background(cargs->Value());
}

void XLE(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* cargs = (WColorTransformArgs*)args;
	zbtn1->Background(cargs->Value());
}

int itemcounter = 0;

void ItemClick(WEntity* sender, WEventArgs* args)
{
	WListBoxItem* obj = (WListBoxItem*)sender;

	UINT32 i;

	std::wstring xstr = L"Clicked: ";
	xstr += obj->Content(i);
	wchar_t* cmd = (wchar_t*)xstr.c_str();


	btnLbl->Content(cmd ,i + 9);
}

void BtnAddItemClick(WEntity* sender, WEventArgs* args)
{
	std::wstring xstr = L"#";
	xstr += std::to_wstring(itemcounter);
	wchar_t* cmd = (wchar_t*)xstr.c_str();
	
	lbx->CreateItem
	(
		WGraphicsContainer::Graphics()->FromRGBA(0, 0, 0),
		WGraphicsContainer::Graphics()->FromRGBA(255, 255, 255),
		WGraphicsContainer::Graphics()->FromRGBA(128, 128, 128),
		L"Arial",
		cmd,
		20
	)->MouseDownRegistery()->Register(ItemClick);

	itemcounter++;
}

W_INT zTemp;
bool zx = 1;
void BtnZIndex(WEntity* sender, WEventArgs* args)
{

	//AsyncWorker->Perform();

	lbx->IsVisible(!lbx->IsVisible());

	if (zx)
	{
		zbtn0->ZIndex(55);// 51
		zbtn1->ZIndex(30);// 50

		zbtn0->ZIndex(51);
		zbtn1->ZIndex(50);


		CT->From(WGraphicsContainer::Graphics()->FromRGBA(230, 15, 5));
		CT->To(WGraphicsContainer::Graphics()->FromRGBA(100, 14, 205));


		XCT->To(WGraphicsContainer::Graphics()->FromRGBA(230, 15, 5));
		XCT->From(WGraphicsContainer::Graphics()->FromRGBA(100, 14, 205));


		zbtn0->Parent(zbtn1);
		zbtn1->Parent(nullptr);
	}
	else
	{
		zbtn0->ZIndex(55);// 50
		zbtn1->ZIndex(30);// 51

		zbtn0->ZIndex(50);
		zbtn1->ZIndex(51);

		CT->To(WGraphicsContainer::Graphics()->FromRGBA(230, 15, 5));
		CT->From(WGraphicsContainer::Graphics()->FromRGBA(100, 14, 205));

		XCT->From(WGraphicsContainer::Graphics()->FromRGBA(230, 15, 5));
		XCT->To(WGraphicsContainer::Graphics()->FromRGBA(100, 14, 205));

		zbtn1->Parent(zbtn0);
		zbtn0->Parent(nullptr);

	}
	zx = !zx;

	CT->Perform();
	XCT->Perform();
}

void BtnMinimize(WEntity* sender, WEventArgs* args)
{
	ShowWindow(WContainer::Handle(), SW_MINIMIZE);
}

float p = 0;
#include "WLerpArgs.h"
void WorkerWork(WEntity* sender, WEventArgs* args)
{
	//p = lerp<float>(p, 100, 0.005);
	//std::this_thread::sleep_for(std::chrono::milliseconds(1));
	//zbtn0->BorderThickness(((WLerpArgs*)args)->ValueExact());

}

//Runs at the start of the application
void WEntry::Start(void)
{


	AsyncWorker = new WLerp(0,100,0.005F,1);
	AsyncWorker->TickRegistry()->Register(WorkerWork);

	btn4->MouseDownRegistery()->Register(BtnAddItemClick);

	CT->TickRegistry()->Register(LEX);
	XCT->TickRegistry()->Register(XLE);
	
	//WAudio x(L"New", L"D:\\1.mp3");
	//x.Play();

	*btn2->MouseUpRegistery() += BtnMinimize;
	*btn3->MouseUpRegistery() += BtnZIndex;

	Graphics()->SetTransparency(90);

	Graphics()->LoadIMG(L"C:\\Users\\Nirex\\Downloads\\x.png", &bmp);

	this->m_mouse->MouseDownRegistry()->Register(MouseClickEvent);
	this->m_mouse->MouseUpRegistry()->Register(MouseClickEventx);

	*btn1->MouseEnterRegistery() += BTNExit_Click;


	*btn1->MouseEnterRegistery() += BtnBordReg;
	*btn2->MouseEnterRegistery() += BtnBordReg;
	*btn3->MouseEnterRegistery() += BtnBordReg;
	*btn4->MouseEnterRegistery() += BtnBordReg;

	//*zbtn0->MouseEnterRegistery() += BtnBordReg;
	//*zbtn1->MouseEnterRegistery() += BtnBordReg;

	*btn1->MouseLeaveRegistery() += UnBtnBordReg;
	*btn2->MouseLeaveRegistery() += UnBtnBordReg;
	*btn3->MouseLeaveRegistery() += UnBtnBordReg;
	*btn4->MouseLeaveRegistery() += UnBtnBordReg;

	//*zbtn0->MouseLeaveRegistery() += UnBtnBordReg;
	//*zbtn1->MouseLeaveRegistery() += UnBtnBordReg;

	*btn1->MouseDownRegistery() += BtnColorReg;
	*btn2->MouseDownRegistery() += BtnColorReg;
	*btn3->MouseDownRegistery() += BtnColorReg;
	*btn4->MouseDownRegistery() += BtnColorReg;

	*btn1->MouseUpRegistery() += UnBtnColorReg;
	*btn1->MouseUpRegistery() += BTNExit_Click;

	*btn2->MouseUpRegistery() += UnBtnColorReg;
	*btn3->MouseUpRegistery() += UnBtnColorReg;
	*btn4->MouseUpRegistery() += UnBtnColorReg;


	zbtn0->BorderThickness(2);
	//zbtn0->Background(Graphics()->FromRGBA(255, 0, 0, 1.0F));
	//zbtn0->Foreground(Graphics()->FromRGBA(0, 15, 25, 1.0F));
	//zbtn0->BorderBrush(Graphics()->FromRGBA(240, 240, 240, 1.0F));
	//zbtn0->BorderRadius(5);
	zbtn0->Location(500, 500, 600, 600);
	zbtn0->Content(L"Y");
	zbtn0->FontSize(30.0F);
	zbtn0->FontFamily(L"Arial");
	zbtn0->IsVisible(false);

	zbtn1->BorderThickness(2);
	//zbtn1->Background(Graphics()->FromRGBA(0, 0, 255, 1.0F));
	//zbtn1->Foreground(Graphics()->FromRGBA(0, 15, 25, 1.0F));
	//zbtn1->BorderBrush(Graphics()->FromRGBA(240, 240, 240, 1.0F));
	//zbtn1->BorderRadius(5);
	zbtn1->Location(550, 550, 650, 650);
	zbtn1->Content(L"Y");
	zbtn1->FontSize(30.0F);
	zbtn1->FontFamily(L"Arial");
	zbtn1->IsVisible(false);

	btn1->BorderThickness(2);
	//btn1->Background(Graphics()->FromRGBA(240, 240, 240, 1.0F));
	//btn1->Foreground(Graphics()->FromRGBA(0, 15, 25, 1.0F));
	//btn1->BorderBrush(Graphics()->FromRGBA(115, 115, 115, 1.0F));
	//btn1->BorderRadius(5);
	btn1->Location(1, 1259, 21, 1279);
	btn1->Content(L"x");
	btn1->FontSize(15.0F);
	btn1->FontFamily(L"Arial");
	btn1->UseExtendedBorder(false);

	//btn1->IsVisible(false);

	btn2->BorderThickness(2);
	//btn2->Background(Graphics()->FromRGBA(240, 240, 240, 1.0F));
	//btn2->Foreground(Graphics()->FromRGBA(0, 15, 25, 1.0F));
	//btn2->BorderBrush(Graphics()->FromRGBA(115, 115, 115, 1.0F));
	//btn2->BorderRadius(5);
	btn2->Location(1, 1236, 21, 1256);
	btn2->Content(L"-");
	btn2->FontSize(15.0F);
	btn2->FontFamily(L"Arial");
	btn2->UseExtendedBorder(false);
	//btn2->IsVisible(false);

	btn3->BorderThickness(2);
	//btn3->Background(Graphics()->FromRGBA(240, 240, 240, 1.0F));
	//btn3->Foreground(Graphics()->FromRGBA(0, 15, 25, 1.0F));
	//btn3->BorderBrush(Graphics()->FromRGBA(115, 115, 115, 1.0F));
	//btn3->BorderRadius(5);
	btn3->Location(160, 50, 190, 160);
	btn3->Content(L"Show/Hide");
	btn3->FontSize(14.0F);
	btn3->FontFamily(L"Consolas");
	//btn3->IsVisible(false);

	btn4->BorderThickness(2);
	//btn4->Background(Graphics()->FromRGBA(240, 240, 240, 1.0F));
	//btn4->Foreground(Graphics()->FromRGBA(0, 15, 25, 1.0F));
	//btn4->BorderBrush(Graphics()->FromRGBA(115, 115, 115, 1.0F));
	//btn4->BorderRadius(5);
	btn4->Location(160, 190, 190, 300);
	btn4->Content(L"Add Item");
	btn4->FontSize(14.0F);
	btn4->FontFamily(L"Consolas");
	//btn4->IsVisible(false);


	


	btnLbl->BorderThickness(2);
	//btnLbl->Background(Graphics()->FromRGBA(240, 240, 240, 1.0F));
	//btnLbl->Foreground(Graphics()->FromRGBA(0, 15, 25, 1.0F));
	//btnLbl->BorderBrush(Graphics()->FromRGBA(115, 115, 115, 1.0F));
	//btnLbl->BorderRadius(5);
	btnLbl->Location(115, 50, 145, 300);
	btnLbl->Content(L"Clicked:");
	btnLbl->FontSize(14.0F);
	btnLbl->FontFamily(L"Consolas");
	//btnLbl->IsVisible(false);

	lbx->Location(210.0, 50, 560.0, 300.0);
	lbx->BorderBrush(Graphics()->FromRGBA(255, 255, 255));
	lbx->Background(Graphics()->FromRGBA(255, 255, 255));

}

W_INT x = 800;
W_INT y = 600;

WRECTF clientR;

//Runs every frame pre-render
void WEntry::Update(DELTATIME deltaTime)
{
	if (switcher)
	{
		B -= (W_FLOAT)deltaTime / 10;
	}
	else
	{
		B += (W_FLOAT)deltaTime / 10;
	}

	//btn1->Location(100, 100, B, B);

	if (B >= 500)
	{
		switcher = 1;
	}
	else if (B <= 300)
	{
		switcher = 0;
	}

	if (shoulddisplace == 1)
	{
		btn1->Displace((W_FLOAT)deltaTime / 2, 0);
		btn2->Displace((W_FLOAT)deltaTime / 2, 0);
		btn3->Displace((W_FLOAT)deltaTime / 2, 0);
		btn4->Displace((W_FLOAT)deltaTime / 2, 0);
		//x += 1;
	}
	else if (shoulddisplace == 2)
	{
		btn1->Displace((W_FLOAT)-deltaTime / 2, 0);
		btn2->Displace((W_FLOAT)-deltaTime / 2, 0);
		btn3->Displace((W_FLOAT)-deltaTime / 2, 0);
		btn4->Displace((W_FLOAT)-deltaTime / 2, 0);
		//x -= 1;
	}


	clientR.Top((W_FLOAT)Graphics()->GetClientArea().top);
	clientR.Left((W_FLOAT)Graphics()->GetClientArea().left);
	clientR.Bottom((W_FLOAT)Graphics()->GetClientArea().bottom);
	clientR.Right((W_FLOAT)Graphics()->GetClientArea().right);
}

//Runs every frame post-update
void WEntry::Render(DELTATIME deltaTime)
{

	//Graphics()->DrawBMP(bmp, W_Rect(0, 0, 720, 1280), 0.7F);
	
	std::wstring xstr = L"Async: ";
	xstr += std::to_wstring(p);
	wchar_t* cmd = (wchar_t*)xstr.c_str();

	//btn3->Content(cmd);
	
	Graphics()->FillRectRadial(clientR,
		Graphics()->FromRGBA(255, 255, 255, 0.7F),
		Graphics()->FromRGBA(0, 0, 0, 0.7F),
		POINTF({ 0,0 }),
		1480,
		920,
		WLRadialGradientDirection::WRG_BottomRight
	);


	//Graphics()->FillRectLinear(clientR, 
	//	Graphics()->W_Color({128, 128, 128, 0.7F),
	//	Graphics()->W_Color({0, 0, 0, 0.7F),
	//	WLinearGradientDirection::WLG_Bottom_Top);

	//Graphics()->DrawRect(clientR,
	//	10,
	//	Graphics()->W_Color({255, 255, 255, 1.0F)
	//);

}