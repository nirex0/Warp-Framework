// © 2018 NIREX ALL RIGHTS RESERVED

#include "WString.h"
#include <locale>
#include <codecvt>

char* WString::ToUpper(char* temp)
{
	char* retc = temp;

	int i = 0;
	while (retc[i])
	{
		retc[i] = toupper(retc[i]);
		i++;
	}
	return retc;
}

char* WString::ToLower(char* temp)
{
	char* retc = temp;

	int i = 0;
	while (retc[i])
	{
		retc[i] = tolower(retc[i]);
		i++;
	}
	return retc;
}

char* WString::Proper(char* temp)
{
	char* retc = temp;

	int i = 0;
	while (retc[i])
	{
		retc[i] = tolower(retc[i]);
		i++;
	}
	retc[0] = toupper(retc[0]);
	return retc;
}

wchar_t* WString::ToUpper(wchar_t* temp)
{
	wchar_t* retc = temp;

	int i = 0;
	while (retc[i])
	{
		retc[i] = toupper(retc[i]);
		i++;
	}
	return retc;
}

wchar_t* WString::ToLower(wchar_t* temp)
{
	wchar_t* retc = temp;

	int i = 0;
	while (retc[i])
	{
		retc[i] = tolower(retc[i]);
		i++;
	}
	return retc;
}

wchar_t* WString::Proper(wchar_t* temp)
{
	wchar_t* retc = temp;

	int i = 0;
	while (retc[i])
	{
		retc[i] = tolower(retc[i]);
		i++;
	}
	retc[0] = toupper(retc[0]);
	return retc;
}

std::string WString::ToUpper(std::string temp)
{
	int i = 0;
	while (temp[i])
	{
		temp[i] = toupper(temp[i]);
		i++;
	}
	return temp;
}

std::string WString::ToLower(std::string temp)
{
	int i = 0;
	while (temp[i])
	{
		temp[i] = tolower(temp[i]);
		i++;
	}
	return temp;
}

std::string WString::Proper(std::string temp)
{
	int i = 0;
	while (temp[i])
	{
		temp[i] = tolower(temp[i]);
		i++;
	}
	temp[0] = toupper(temp[0]);
	return temp;
}

std::wstring WString::ToUpper(std::wstring temp)
{
	int i = 0;
	while (temp[i])
	{
		temp[i] = toupper(temp[i]);
		i++;
	}
	return temp;
}

std::wstring WString::ToLower(std::wstring temp)
{
	int i = 0;
	while (temp[i])
	{
		temp[i] = tolower(temp[i]);
		i++;
	}
	return temp;
}

std::wstring WString::Proper(std::wstring temp)
{
	int i = 0;
	while (temp[i])
	{
		temp[i] = tolower(temp[i]);
		i++;
	}
	temp[0] = toupper(temp[0]);
	return temp;
}

std::vector<std::string> WString::Split(std::string in_s, const std::string& delim)
{
	std::vector <std::string> retvec;
	size_t pos = 0;
	std::string token;

	while ((pos = in_s.find(delim)) != std::string::npos)
	{
		token = in_s.substr(0, pos);
		retvec.push_back(token);
		in_s.erase(0, pos + delim.length());
	}

	retvec.push_back(in_s);
	return retvec;
}

std::vector<std::wstring> WString::Split(std::wstring in_s, const std::wstring & delim)
{
	std::vector <std::wstring> retvec;
	size_t pos = 0;
	std::wstring token;

	while ((pos = in_s.find(delim)) != std::wstring::npos)
	{
		token = in_s.substr(0, pos);
		retvec.push_back(token);
		in_s.erase(0, pos + delim.length());
	}

	retvec.push_back(in_s);
	return retvec;
}

std::wstring WString::ToWide(std::string in)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(in);
}

std::string WString::ToNarrow(std::wstring in)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.to_bytes(in);
}
