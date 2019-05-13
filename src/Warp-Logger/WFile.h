//© 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_FILE_H_
#define _W_FILE_H_

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

class WFile final
{
public:
	static std::string ReadAllText(const std::string& file);
	static int WriteAllText(const std::string& file, const std::string& str);

	static std::vector<std::string> ReadAllLines(const std::string& file);
	static int WriteAllLines(const std::string& file, std::vector<std::string> vecstr);

	static std::vector<char> ReadAllBytes(const std::string& fileName);
	static int WriteAllBytes(const std::string& fileName, std::vector<char> vecBytes);

	static std::int32_t FindFirst(const std::string& file, const std::string& val);
	static std::vector<int32_t> FindAll(const std::string& file, const std::string& val);

	static bool SafeFRead(void* buffer, int size, int number, FILE* fp);
	static bool SafeFWrite(void* buffer, int size, int number, FILE* fp);

	bool SafeFread(void* buffer, int size, int number, FILE* fp);
};

#endif // !_W_FILE_H_
