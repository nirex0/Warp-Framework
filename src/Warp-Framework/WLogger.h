// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_LOGGER_H_
#define _W_LOGGER_H_

#include <string>

class WLogger final
{
public:
	static void Error(std::wstring msg, int logLevel);
	static void Warning(std::wstring msg, int logLevel);
	static void Information(std::wstring msg, int logLevel);
	static void Debug(std::wstring msg, int logLevel);

	static void Error(std::wstring msg, std::wstring path, int logLevel);
	static void Warning(std::wstring msg, std::wstring path, int logLevel);
	static void Information(std::wstring msg, std::wstring path, int logLevel);
	static void Debug(std::wstring msg, std::wstring path, int logLevel);

private:
	static int m_loglevel;
};

#endif // !_W_LOGGER_H_