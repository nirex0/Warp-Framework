// © 2019 NIREX ALL RIGHTS RESERVED

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

	static void WLoggerFlush(std::wstring path);
	static void WLoggerRun(std::wstring path);
	static void WLoggerPass(std::wstring path, std::wstring text);
	static void WLoggerInfo(std::wstring path, std::wstring text);
	static void WLoggerDebug(std::wstring path, std::wstring text);
	static void WLoggerMessage(std::wstring path, std::wstring text);
	static void WLoggerWarning(std::wstring path, std::wstring text);
	static void WLoggerTrace(std::wstring path, std::wstring text);
	static void WLoggerError(std::wstring path, std::wstring text);
	static void WLoggerFatal(std::wstring path, std::wstring text);

private:
	static int m_loglevel;
};

#endif // !_W_LOGGER_H_