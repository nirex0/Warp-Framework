// © 2018 NIREX ALL RIGHTS RESERVED

#include "WMainWindow.h"

// We Need to Initialize the container's static memebers to nullptr ({} = ZeroMemory}
HRESULT WContainer::HR = {};
HWND WContainer::hWnd = {};
UINT WContainer::msg = {};
WPARAM WContainer::wParam = {};
LPARAM WContainer::lParam = {};
WEntry WContainer::WFramework = {};
DELTATIME WContainer::DeltaTime = {};

// Background Color Componenets
W_INT WContainer::BGA = 255;	// Background Alfa
W_INT WContainer::BGR = 12;		// Background Red
W_INT WContainer::BGG = 21;		// Background Blue
W_INT WContainer::BGB = 30;		// Background Green

W_INT WContainer::W_WIDTH = 1280;
W_INT WContainer::W_HEIGHT = 720;

WMouse* WContainer::mouse = {};
WKeyboard* WContainer::keyboard = {};

INT WContainer::helperCoordX = 0;
INT WContainer::helperCoordY = 0;
BOOL WContainer::bDragMove = 0;

// Same with the DX components
ID2D1Factory* WDXContainer::DX_Factory = {};
ID2D1HwndRenderTarget* WDXContainer::DX_RT = {};
RECT WDXContainer::DX_cRect = {};
IDWriteFactory* WDXContainer::DX_WFactory = {};
IDWriteTextFormat* WDXContainer::DX_TextFormat = {};

// Same with the Reg Container
WUniqueRegister* WRegContainer::KBD_KeyDownReg = {};
WUniqueRegister* WRegContainer::KBD_KeyUpReg = {};
WUniqueRegister* WRegContainer::KBD_OnCharReg = {};
				 
WRegistry* WRegContainer::MOS_MouseDown = {};
WRegistry* WRegContainer::MOS_MouseUp = {};
WRegistry* WRegContainer::MOS_MouseMove = {};
WRegistry* WRegContainer::MOS_MouseRollUp = {};
WRegistry* WRegContainer::MOS_MouseRollDown = {};

WUniqueRegister* WRegContainer::WND_OnGDIPaint = {};

// Same with the GFX Container
WGraphics* WGraphicsContainer::gfx = {};

// D2D1_RENDER_TARGET_TYPE_HARDWARE	: The main render target uses hardware rendering only.
// D2D1_RENDER_TARGET_TYPE_SOFTWARE	: The main render target uses software rendering only.
// D2D1_RENDER_TARGET_TYPE_DEFAULT	: The main render target uses hardware rendering, if available; otherwise, it uses software rendering.
D2D1_RENDER_TARGET_TYPE WGraphicsContainer::main_rttype = D2D1_RENDER_TARGET_TYPE_DEFAULT;

// C-Style wWinMain function
W_INT WARP_ENTRY wWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,		// UNUSED
	LPWSTR lpCmd,					// UNUSED
	INT cmdShow						// UNUSED
)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmd);
	UNREFERENCED_PARAMETER(cmdShow);

	MainWnd = new WMainWindow(hInstance, WindowTitle, ApplicationName);
	MainWnd->Initialize();
	MainWnd->MessageLoop();

	return 0;
}

// C-Style WinProc function
LRESULT WARP_CALL WindowsProcedure(
	HWND hWnd,		// Handle to our current window
	UINT msg,		// Current message
	WPARAM wParam,	// Word param
	LPARAM lParam	// Long param
)
{
// Update the container's static Members
	WContainer::Handle(hWnd);
	WContainer::Message(msg);
	WContainer::WParam(wParam);
	WContainer::LParam(lParam);

// We call the mainWindow's procedure function from our C-Style winProc function
	return MainWnd->WProcedure(hWnd, msg, wParam, lParam);
}


// WMainWindow Class functions
WMainWindow::WMainWindow(HINSTANCE hInstance, LPWSTR WindowTitle, LPWSTR WindowName)
	: m_hAppInstance(hInstance)
	, m_windowTitle(WindowTitle)
	, m_windowName(WindowName)
{
	m_mouse = new WMouse();
	m_keyboard = new WKeyboard();
	m_entry = new WEntry();
	m_OnGDIPaint = new WUniqueRegister();

	WContainer::Mouse(m_mouse);
	WContainer::Keyboard(m_keyboard);
	
	m_graphics = new WGraphics();

	WGraphicsContainer::Graphics(m_graphics);
	WContainer::Framework(*m_entry);
	SetGRegisters();
}

WMainWindow::~WMainWindow(void)
{
	delete m_mouse;
	delete m_keyboard;
	delete m_entry;
	delete m_OnGDIPaint;
	delete m_graphics;
}

W_INT WMainWindow::Initialize(void)
{
	HWND hWnd;
	WNDCLASSEX wcex = {};
	ZeroMemory(&wcex, sizeof(WNDCLASSEXW));

// Setup the WCEX 
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.cbSize = sizeof(WNDCLASSEXW);
	wcex.cbClsExtra = {};
	wcex.cbWndExtra = {};
	wcex.lpszMenuName = {};
	wcex.lpszClassName = m_windowName;
	wcex.lpfnWndProc = WindowsProcedure;
	wcex.hInstance = m_hAppInstance;
	wcex.hCursor = LoadCursor({}, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

// Register the class
	RegisterClassExW(&wcex);

	W_STYLE wStyle = WS_OVERLAPPEDWINDOW | WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE | WS_CAPTION | WS_MINIMIZEBOX;

// We need to do this to make the window EXACTLY (width * height) big
	RECT whRect = { 0, 0, WContainer::Width(), WContainer::Height() };
	AdjustWindowRect(&whRect, wStyle, FALSE);
	
// Use this ONLY if you use A Normal window (With default top bar)
	UINT uWidth = whRect.right - whRect.left;
	UINT uHeight = whRect.bottom - whRect.top;

	UINT centX = GetSystemMetrics(SM_CXSCREEN) / 2 - (W_LONG)uWidth / 2;
	UINT centY = GetSystemMetrics(SM_CYSCREEN) / 2 - (W_LONG)uHeight / 2;
	UINT SCR_WIDTH = GetSystemMetrics(SM_CXSCREEN);
	UINT SCR_HEIGHT = GetSystemMetrics(SM_CYSCREEN);

// WS_EX_LAYERED for Transparency Support
// WS_POPUP for no default top bar
	hWnd = CreateWindowEx(WS_EX_LAYERED, m_windowName, m_windowTitle, WS_POPUP, centX, centY, WContainer::Width(), WContainer::Height(), {}, {}, m_hAppInstance, {});
	
	if (!hWnd)
	{
		WContainer::hResult(E_OUTOFMEMORY);
		PostQuitMessage(2);
		return 2;
	}

	WContainer::hResult(S_OK);
	WContainer::Handle(hWnd);
	
// Show the window
	ShowWindow(hWnd, SW_SHOW);
	SetForegroundWindow(hWnd);
	SetFocus(hWnd);

	return 0;
}

void WMainWindow::MessageLoop(void)
{
// Windows MSG
	MSG msg = {};
	ZeroMemory(&msg, sizeof(MSG));

// Create Graphics Resources
	m_graphics->CreateFactory();
	m_graphics->CreateRenderTarget();
	m_graphics->CreateSolidColorBrush(D2D1::ColorF(0xFFFFFFFF));
	m_graphics->CreateWriteFactory();
	m_graphics->CreateFormat();

// Initialize Keyboard
	m_entry->Keyboard(m_keyboard);

// Initialize Mouse
	m_entry->Mouse(m_mouse);

// Initialize Graphics
	m_entry->Graphics(m_graphics);

// Start 
	m_entry->Start();

// Main Loop
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, {}, {}, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
// Dragmove
			if (!WContainer::DragMove())
			{
				POINT tmpPoint;
				GetCursorPos(&tmpPoint);
				ScreenToClient(WContainer::Handle(), &tmpPoint);

// HC Stands for 'Helper Coordinate'
				WContainer::HCX(tmpPoint.x);
				WContainer::HCY(tmpPoint.y);
			}

			//Delta time Calculation
			auto newEndTime = WClock::now();
			auto frameTime = newEndTime - mLastEndTime;
			mLastEndTime = newEndTime;

			typedef std::common_type<decltype(frameTime), decltype(kMaxDeltatime)>::type common_duration;
			auto mDeltaTime = std::min<common_duration>(frameTime, kMaxDeltatime);

// std::ratio<1, 1> for seconds instead of miliseconds
			milliseconds = std::chrono::duration_cast<std::chrono::duration<W_DOUBLE, std::milli>>(mDeltaTime).count();
			WContainer::DeltaSeconds(milliseconds);

// Update & Render
// Note: Render statements should be written after all of the Update statements
// Update
			m_entry->Update(milliseconds);
			
// Render
			m_graphics->SafeBeginDraw();
			m_graphics->ClearWindow(D2D1::ColorF((W_FLOAT)WContainer::BackR() / 255, (W_FLOAT)WContainer::BackG() / 255, (W_FLOAT)WContainer::BackB() / 255, (W_FLOAT)WContainer::BackA() / 255));
			m_entry->Render(milliseconds);
			
// Render all the controls
			WControlHandler::Update();
			WControlHandler::Render();
			m_graphics->SafeEndDraw();

// We assume the mouse is always moving (Smoother Input) 
// use #define WARP_OMI if you don't want to use this method.
#ifndef WARP_OMI
			POINT pt;
			GetCursorPos(&pt);
			ScreenToClient(WContainer::Handle(), &pt);
			m_mouse->MouseKey(WMouseKey::MK_INVALID);
			m_mouse->MPoint(pt.x, pt.y);
			m_mouse->MouseDown();

			WMouseArgs* args = new WMouseArgs(pt.x, pt.y, WMouseKey::MK_INVALID, KeyState::NoClick);
			WControlHandler::MouseMove(args);
#endif
			if (WContainer::DragMove())
			{
				W_MAIN_WINDOW::DragMoveWindow();
			}
		}
	}
}

LRESULT WMainWindow::WProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
// Update the container's static Members
	WContainer::Handle(hWnd);
	WContainer::Message(msg);
	WContainer::WParam(wParam);
	WContainer::LParam(lParam);

	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);

	switch (msg)
	{
// WINDOW RESIZE
	case WM_SIZING:
	{
		W_UINT width = LOWORD(lParam);
		W_UINT height = HIWORD(lParam);
		WContainer::Width((W_INT)width);
		WContainer::Height((W_INT)height);

		break;
	}

// WINDOW RESIZED
	case WM_SIZE:
	{
		W_UINT width = LOWORD(lParam);
		W_UINT height = HIWORD(lParam);
		WContainer::Width((W_INT)width);
		WContainer::Height((W_INT)height);
		if (m_entry->Graphics() != nullptr)
		{
			m_entry->Graphics()->ResizeRenderTarget(width, height);
		}
		break;
	}

// PAINT MESSAGE (#Define WARP_GDI_SUPPORT to Enable WM_PAINT and GDI Support)
#ifdef WARP_GDI_SUPPORT
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		BeginPaint(hWnd, &ps);

		ValidateRect(hWnd, nullptr);
		WGDIPaintArgs* args = new WGDIPaintArgs(&ps, &hWnd);
		m_OnGDIPaint->Run(this, args);

		EndPaint(hWnd, &ps);
		break;
	}
#endif WARP_GDI_SUPPORT

// KEYBOARD MESSAGES
	case WM_KEYDOWN:
	{
// Key Down
// No autorepeat
		if (!(lParam & 0x40000000) || m_keyboard->AutorepeatIsEnabled())
		{
			m_keyboard->LastKey((static_cast<W_BYTE>(wParam)));
			m_keyboard->RunKeyDown();
		}
		break;
	}
	case WM_KEYUP:
	{
// Key Up
		m_keyboard->LastKey((static_cast<W_BYTE>(wParam)));
		m_keyboard->RunKeyUp();
		break;
	}
	case WM_CHAR:
	{
		m_keyboard->LastKey((static_cast<W_BYTE>(wParam)));
		m_keyboard->RunOnChar();
		break;
	}
// END OF KEYBOARD MESSAGES
// MOUSE MESSAGES
	case WM_MOUSEMOVE:
	{

#ifndef WARP_OMI
		break;
#endif
		m_mouse->MouseKey(WMouseKey::MK_INVALID);
		m_mouse->MPoint(pt.x, pt.y);
		m_mouse->MouseDown();

		WMouseArgs* args = new WMouseArgs(pt.x, pt.y, WMouseKey::MK_INVALID, KeyState::NoClick);
		WControlHandler::MouseMove(args);
		break;
	}
	case WM_LBUTTONDOWN:
	{
		m_mouse->MouseKey(WMouseKey::MK_LEFT);
		m_mouse->MPoint(pt.x, pt.y);
		m_mouse->MouseDown();

		WMouseArgs* args = new WMouseArgs(pt.x, pt.y, WMouseKey::MK_LEFT, KeyState::MouseDown);
		WControlHandler::MouseDown(args);
		break;
	}
	case WM_LBUTTONUP:
	{		
		m_mouse->MouseKey(WMouseKey::MK_LEFT);
		m_mouse->MPoint(pt.x, pt.y);
		m_mouse->MouseUp();

		WMouseArgs* args = new WMouseArgs(pt.x, pt.y, WMouseKey::MK_LEFT, KeyState::MouseUp);
		WControlHandler::MouseUp(args);
		break;
	}
	case WM_RBUTTONDOWN:
	{
		m_mouse->MouseKey(WMouseKey::MK_RIGHT);
		m_mouse->MPoint(pt.x, pt.y);
		m_mouse->MouseDown();

		WMouseArgs* args = new WMouseArgs(pt.x, pt.y, WMouseKey::MK_RIGHT, KeyState::MouseDown);
		WControlHandler::MouseDown(args);
		break;
	}
	case WM_RBUTTONUP:
	{
		m_mouse->MouseKey(WMouseKey::MK_RIGHT);
		m_mouse->MPoint(pt.x, pt.y);
		m_mouse->MouseUp();

		WMouseArgs* args = new WMouseArgs(pt.x, pt.y, WMouseKey::MK_RIGHT, KeyState::MouseUp);
		WControlHandler::MouseUp(args);
		break;
	}
	case WM_MBUTTONDOWN:
	{
		m_mouse->MouseKey(WMouseKey::MK_MIDDLE);
		m_mouse->MPoint(pt.x, pt.y);
		m_mouse->MouseDown();

		WMouseArgs* args = new WMouseArgs(pt.x, pt.y, WMouseKey::MK_MIDDLE, KeyState::MouseDown);
		WControlHandler::MouseDown(args);
		break;
	}
	case WM_MBUTTONUP:
	{
		m_mouse->MouseKey(WMouseKey::MK_MIDDLE);
		m_mouse->MPoint(pt.x, pt.y);
		m_mouse->MouseUp();

		WMouseArgs* args = new WMouseArgs(pt.x, pt.y, WMouseKey::MK_MIDDLE, KeyState::MouseUp);
		WControlHandler::MouseUp(args);
		break;
	}
	case WM_MOUSEWHEEL:
	{
		if (GET_WHEEL_DELTA_WPARAM(wParam) < 0)
		{
			m_mouse->MouseKey(WMouseKey::MK_MIDDLE);
			m_mouse->MPoint(pt.x, pt.y);
			m_mouse->MouseMiddleDown();

			WMouseArgs* args = new WMouseArgs(pt.x, pt.y, WMouseKey::MK_MIDDLE, KeyState::NoClick);
			WControlHandler::MouseRollDown(args);
		}
		else if (GET_WHEEL_DELTA_WPARAM(wParam) > 0)
		{

			m_mouse->MouseKey(WMouseKey::MK_MIDDLE);
			m_mouse->MPoint(pt.x, pt.y);
			m_mouse->MouseMiddleUp();

			WMouseArgs* args = new WMouseArgs(pt.x, pt.y, WMouseKey::MK_MIDDLE, KeyState::NoClick);
			WControlHandler::MouseRollUp(args);
		}
		break;
	}
// END OF MOUSE MESSAGES
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	default:
	{
		return DefWindowProc(hWnd, msg, wParam, lParam);
		break;
	}
	}
// Safeguard
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void WMainWindow::SetGRegisters(void)
{
	WRegContainer::OnGDIPaint(m_OnGDIPaint);
}
