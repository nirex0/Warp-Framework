// © 2018 NIREX ALL RIGHTS RESERVED

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <string>

#include "WFile.h"
#include "WString.h"
#include "WLogger.h"
#include "WWin.h"

int WLogger::m_loglevel = {};

void WLogger::Error(std::wstring msg, int logLevel)
{
	if (logLevel > m_loglevel)
		return;

	std::wstring l_msg;
	l_msg = L"(";
	l_msg += std::to_wstring(logLevel);
	l_msg += L") E: ";
	l_msg += msg;
	l_msg += L"\n";

	OutputDebugString(l_msg.c_str());
}

void WLogger::Warning(std::wstring msg, int logLevel)
{
	if (logLevel > m_loglevel)
		return;

	std::wstring l_msg;
	l_msg = L"(";
	l_msg += std::to_wstring(logLevel);
	l_msg += L") W: ";
	l_msg += msg;
	l_msg += L"\n";

	OutputDebugString(l_msg.c_str());
}

void WLogger::Information(std::wstring msg, int logLevel)
{
	if (logLevel > m_loglevel)
		return;

	std::wstring l_msg;
	l_msg = L"(";
	l_msg += std::to_wstring(logLevel);
	l_msg += L") I: ";
	l_msg += msg;
	l_msg += L"\n";

	OutputDebugString(l_msg.c_str());
}

void WLogger::Debug(std::wstring msg, int logLevel)
{
	if (logLevel > m_loglevel)
		return;

	std::wstring l_msg;
	l_msg = L"(";
	l_msg += std::to_wstring(logLevel);
	l_msg += L") D: ";
	l_msg += msg;
	l_msg += L"\n";

	OutputDebugString(l_msg.c_str());
}

void WLogger::Error(std::wstring msg, std::wstring path, int logLevel)
{
	if (logLevel > m_loglevel)
		return;

	std::wstring l_msg;
	l_msg = L"(";
	l_msg += std::to_wstring(logLevel);
	l_msg += L") E: ";
	l_msg += msg;
	l_msg += L"\n";

	std::ofstream file;
	file.open(path, std::ofstream::out | std::ofstream::app);
	file << l_msg.c_str();
	file.close();
}


void WLogger::Warning(std::wstring msg, std::wstring path, int logLevel)
{
	if (logLevel > m_loglevel)
		return;

	std::wstring l_msg;
	l_msg = L"(";
	l_msg += std::to_wstring(logLevel);
	l_msg += L") W: ";
	l_msg += msg;
	l_msg += L"\n";

	std::ofstream file;
	file.open(path, std::ofstream::out | std::ofstream::app);
	file << l_msg.c_str();
	file.close();
}

void WLogger::Information(std::wstring msg, std::wstring path, int logLevel)
{
	if (logLevel > m_loglevel)
		return;

	std::wstring l_msg;
	l_msg = L"(";
	l_msg += std::to_wstring(logLevel);
	l_msg += L") I: ";
	l_msg += msg;
	l_msg += L"\n";

	std::ofstream file;
	file.open(path, std::ofstream::out | std::ofstream::app);
	file << l_msg.c_str();
	file.close();
}

void WLogger::Debug(std::wstring msg, std::wstring path, int logLevel)
{
	if (logLevel > m_loglevel)
		return;

	std::wstring l_msg;
	l_msg = L"(";
	l_msg += std::to_wstring(logLevel);
	l_msg += L") D: ";
	l_msg += msg;
	l_msg += L"\n";

	std::ofstream file;
	file.open(path, std::ofstream::out | std::ofstream::app);
	file << l_msg.c_str();
	file.close();
}

void WLogger::WLoggerFlush(std::wstring path)
{
	std::wstring initPath = path;
	initPath += L"init.wcm";

	WFile file;
	file.WriteAllText(WString::ToNarrow(initPath), "");
}

void WLogger::WLoggerRun(std::wstring path)
{
	LPWSTR lpPath = (LPWSTR)path.c_str();

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	CreateProcess(lpPath, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

void WLogger::WLoggerPass(std::wstring path, std::wstring text)
{
	std::wstring exePath = path;
	exePath += L"Warp-Logger.exe";

	std::ifstream f0(exePath.c_str());
	if (!f0.good())
		return;
	f0.close();

	std::wstring logPath = path + L"tmpWlog.wlog";

	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&now_c), "%F %T");
	ss << "::" << "0" << "::" << WString::ToNarrow(text) << "\n";

	std::ofstream file;
	file.open(logPath, std::ofstream::out | std::ofstream::app);
	file << ss.str().c_str();
	file.close();
	return;
}

void WLogger::WLoggerInfo(std::wstring path, std::wstring text)
{
	std::wstring exePath = path;
	exePath += L"Warp-Logger.exe";

	std::ifstream f0(exePath.c_str());
	if (!f0.good())
		return;
	f0.close();

	std::wstring logPath = path + L"tmpWlog.wlog";

	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&now_c), "%F %T");
	ss << "::" << "1" << "::" << WString::ToNarrow(text) << "\n";

	std::ofstream file;
	file.open(logPath, std::ofstream::out | std::ofstream::app);
	file << ss.str().c_str();
	file.close();
	return;
}

void WLogger::WLoggerDebug(std::wstring path, std::wstring text)
{
	std::wstring exePath = path;
	exePath += L"Warp-Logger.exe";

	std::ifstream f0(exePath.c_str());
	if (!f0.good())
		return;
	f0.close();

	std::wstring logPath = path + L"tmpWlog.wlog";

	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&now_c), "%F %T");
	ss << "::" << "2" << "::" << WString::ToNarrow(text) << "\n";

	std::ofstream file;
	file.open(logPath, std::ofstream::out | std::ofstream::app);
	file << ss.str().c_str();
	file.close();
	return;
}

void WLogger::WLoggerMessage(std::wstring path, std::wstring text)
{
	std::wstring exePath = path;
	exePath += L"Warp-Logger.exe";

	std::ifstream f0(exePath.c_str());
	if (!f0.good())
		return;
	f0.close();

	std::wstring logPath = path + L"tmpWlog.wlog";

	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&now_c), "%F %T");
	ss << "::" << "3" << "::" << WString::ToNarrow(text) << "\n";

	std::ofstream file;
	file.open(logPath, std::ofstream::out | std::ofstream::app);
	file << ss.str().c_str();
	file.close();
	return;
}

void WLogger::WLoggerWarning(std::wstring path, std::wstring text)
{
	std::wstring exePath = path;
	exePath += L"Warp-Logger.exe";

	std::ifstream f0(exePath.c_str());
	if (!f0.good())
		return;
	f0.close();

	std::wstring logPath = path + L"tmpWlog.wlog";

	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&now_c), "%F %T");
	ss << "::" << "4" << "::" << WString::ToNarrow(text) << "\n";

	std::ofstream file;
	file.open(logPath, std::ofstream::out | std::ofstream::app);
	file << ss.str().c_str();
	file.close();
	return;
}

void WLogger::WLoggerTrace(std::wstring path, std::wstring text)
{
	std::wstring exePath = path;
	exePath += L"Warp-Logger.exe";

	std::ifstream f0(exePath.c_str());
	if (!f0.good())
		return;
	f0.close();

	std::wstring logPath = path + L"tmpWlog.wlog";

	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&now_c), "%F %T");
	ss << "::" << "5" << "::" << WString::ToNarrow(text) << "\n";

	std::ofstream file;
	file.open(logPath, std::ofstream::out | std::ofstream::app);
	file << ss.str().c_str();
	file.close();
	return;
}

void WLogger::WLoggerError(std::wstring path, std::wstring text)
{
	std::wstring exePath = path;
	exePath += L"Warp-Logger.exe";

	std::ifstream f0(exePath.c_str());
	if (!f0.good())
		return;
	f0.close();

	std::wstring logPath = path + L"tmpWlog.wlog";

	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&now_c), "%F %T");
	ss << "::" << "6" << "::" << WString::ToNarrow(text) << "\n";

	std::ofstream file;
	file.open(logPath, std::ofstream::out | std::ofstream::app);
	file << ss.str().c_str();
	file.close();
	return;
}

void WLogger::WLoggerFatal(std::wstring path, std::wstring text)
{
	std::wstring exePath = path;
	exePath += L"Warp-Logger.exe";

	std::ifstream f0(exePath.c_str());
	if (!f0.good())
		return;
	f0.close();

	std::wstring logPath = path + L"tmpWlog.wlog";

	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&now_c), "%F %T");
	ss << "::" << "7" << "::" << WString::ToNarrow(text) << "\n";

	std::ofstream file;
	file.open(logPath, std::ofstream::out | std::ofstream::app);
	file << ss.str().c_str();
	file.close();
	return;
}