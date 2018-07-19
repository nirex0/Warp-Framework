// © 2018 NIREX ALL RIGHTS RESERVED

#include <fstream>
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
