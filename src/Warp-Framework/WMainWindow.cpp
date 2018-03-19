//© 2018 NIREX ALL RIGHTS RESERVED

#include "WMainWindow.h"

// We Need to Initialize the container's static memebers to nullptr ({} = ZeroMemory}
HRESULT WContainer::HR = {};
HWND WContainer::hWnd = {};
UINT WContainer::msg = {};
WPARAM WContainer::wParam = {};
LPARAM WContainer::lParam = {};
WEntry WContainer::WFramework = {};
DELTATIME WContainer::DeltaTime = {};

// Same with the Reg Container
WUniqueRegister* WRegContainer::KBD_KeyDownReg = {};
WUniqueRegister* WRegContainer::KBD_KeyUpReg = {};
WUniqueRegister* WRegContainer::KBD_OnCharReg = {};
				 
WUniqueRegister* WRegContainer::MOS_MouseDown = {};
WUniqueRegister* WRegContainer::MOS_MouseUp = {};
WUniqueRegister* WRegContainer::MOS_MouseMove = {};
WUniqueRegister* WRegContainer::MOS_MouseRollUp = {};
WUniqueRegister* WRegContainer::MOS_MouseRollDown = {};
				 
WUniqueRegister* WRegContainer::WND_OnGDIPaint = {};

// C-Style wWinMain function
int WARP_ENTRY wWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,				// UNUSED
	LPWSTR lpCmd,							// UNUSED
	INT cmdShow								// UNUSED
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
	HWND hWnd,				// Handle to our current window
	UINT msg,				// Current message
	WPARAM wParam,			// Word param
	LPARAM lParam			// Long param
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
	WContainer::Framework(*m_entry);
	SetGRegisters();
}

WMainWindow::~WMainWindow(void)
{
	delete m_mouse;
	delete m_keyboard;
	delete m_entry;

	delete m_OnGDIPaint;
}

int WMainWindow::Initialize(void)
{
	HWND hWnd;
	WNDCLASSEX wcex = {};
	ZeroMemory(&wcex, sizeof(WNDCLASSEXW));

	//Setup the WCEX 
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.cbSize = sizeof(WNDCLASSEXW);
	wcex.cbClsExtra = NULL;
	wcex.cbWndExtra = NULL;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = m_windowName;
	wcex.lpfnWndProc = WindowsProcedure;
	wcex.hInstance = m_hAppInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	//Register the class
	RegisterClassExW(&wcex);

	W_STYLE nStyle = WS_OVERLAPPEDWINDOW | WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE | WS_CAPTION | WS_MINIMIZEBOX;

	//We need to do this to make the windoe EXACTLY (width * height) big
	RECT whRect = { 0, 0, W_WIDTH, W_HEIGHT };
	AdjustWindowRect(&whRect, nStyle, FALSE);
	UINT uWidth = whRect.right - whRect.left;
	UINT uHeight = whRect.bottom - whRect.top;

	UINT centX = GetSystemMetrics(SM_CXSCREEN) / 2 - (long)uWidth / 2;
	UINT centY = GetSystemMetrics(SM_CYSCREEN) / 2 - (long)uHeight / 2;
	UINT SCR_WIDTH = GetSystemMetrics(SM_CXSCREEN);
	UINT SCR_HEIGHT = GetSystemMetrics(SM_CYSCREEN);

	hWnd = CreateWindowEx(WS_EX_APPWINDOW, m_windowName, m_windowTitle, nStyle, centX, centY, uWidth, uHeight, NULL, NULL, m_hAppInstance, NULL);

	if (!hWnd)
	{
		WContainer::hResult(E_OUTOFMEMORY);
		PostQuitMessage(2);
		return 2;
	}
	WContainer::hResult(S_OK);

	//Finnaly we show our window
	ShowWindow(hWnd, SW_SHOW);
	SetForegroundWindow(hWnd);
	SetFocus(hWnd);

	return 0;
}

void WMainWindow::MessageLoop(void)
{
	//Windows MSG
	MSG msg = {};
	ZeroMemory(&msg, sizeof(MSG));

	//Initialize Keyboard
	m_entry->Keyboard(m_keyboard);

	//Initialize Mouse
	m_entry->Mouse(m_mouse);

	//Start 
	m_entry->Start();

	//Main Loop
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//Update & Render
			//Note: Render statements should be written after all of the Update statements
			m_entry->Update(milliseconds);
			WContainer::DeltaSeconds(milliseconds);

			//Delta time Calculation
			auto newEndTime = NClock::now();
			auto frameTime = newEndTime - mLastEndTime;
			mLastEndTime = newEndTime;

			typedef std::common_type<decltype(frameTime), decltype(kMaxDeltatime)>::type common_duration;
			auto mDeltaTime = std::min<common_duration>(frameTime, kMaxDeltatime);

			//std::ratio<1, 1> for seconds instead of miliseconds
			milliseconds = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(mDeltaTime).count();
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

	switch (msg)
	{

	// GDI PAINT
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		BeginPaint(hWnd, &ps);

		WGDIPaintArgs* args = new WGDIPaintArgs(&ps, &hWnd);
		m_OnGDIPaint->Run(this, args);

		EndPaint(hWnd, &ps);
		break;
	}

	// KEYBOARD MESSAGES
	case WM_KEYDOWN:
	{
		// Key Down
		//No autorepeat
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
	case WM_LBUTTONDOWN:
	{
		const POINTS pt = MAKEPOINTS(lParam);
		m_mouse->MouseKey(WMouseKey::MK_LEFT);
		m_mouse->MPoint(pt.x, pt.y);
		m_mouse->MouseDown();
		break;
	}
	case WM_LBUTTONUP:
	{
		const POINTS pt = MAKEPOINTS(lParam);
		m_mouse->MouseKey(WMouseKey::MK_LEFT);
		m_mouse->MPoint(pt.x, pt.y);
		m_mouse->MouseUp();
		break;
	}
	case WM_RBUTTONDOWN:
	{
		const POINTS pt = MAKEPOINTS(lParam);
		m_mouse->MouseKey(WMouseKey::MK_RIGHT);
		m_mouse->MPoint(pt.x, pt.y);
		m_mouse->MouseDown();
		break;
	}
	case WM_RBUTTONUP:
	{
		const POINTS pt = MAKEPOINTS(lParam);
		m_mouse->MouseKey(WMouseKey::MK_RIGHT);
		m_mouse->MPoint(pt.x, pt.y);
		m_mouse->MouseUp();
		break;
	}
	case WM_MBUTTONDOWN:
	{
		const POINTS pt = MAKEPOINTS(lParam);
		m_mouse->MouseKey(WMouseKey::MK_MIDDLE);
		m_mouse->MPoint(pt.x, pt.y);
		m_mouse->MouseDown();
		break;
	}
	case WM_MBUTTONUP:
	{
		const POINTS pt = MAKEPOINTS(lParam);
		m_mouse->MouseKey(WMouseKey::MK_MIDDLE);
		m_mouse->MPoint(pt.x, pt.y);
		m_mouse->MouseUp();
		break;
	}
	case WM_MOUSEWHEEL:
	{
		const POINTS pt = MAKEPOINTS(lParam);
		m_mouse->MPoint(pt.x, pt.y);
		if (GET_WHEEL_DELTA_WPARAM(wParam) < 0)
		{
			m_mouse->MouseKey(WMouseKey::MK_MIDDLE);
			m_mouse->MouseMiddleDown();
		}
		else if (GET_WHEEL_DELTA_WPARAM(wParam) > 0)
		{
			m_mouse->MouseKey(WMouseKey::MK_MIDDLE);
			m_mouse->MouseMiddleUp();
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
