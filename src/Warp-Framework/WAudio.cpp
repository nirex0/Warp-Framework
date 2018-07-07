// © 2018 NIREX ALL RIGHTS RESERVED

#include "WAudio.h"

WAudio::WAudio(const wchar_t* name, const wchar_t* path)
	: m_name(name)
	, m_path(path)
{
	std::wstring cmd = L"";
	cmd += L"open \"";
	cmd += m_path; 
	cmd += L"\" type mpegvideo alias ";
	cmd += m_name;
	mciSendString(cmd.c_str(), nullptr, 0, WContainer::Handle());
}

WAudio::~WAudio(void)
{
	std::wstring cmd = L"";
	cmd = L"";
	cmd += L"close ";
	cmd += m_name;
	mciSendString(cmd.c_str(), nullptr, 0, WContainer::Handle());
}

const wchar_t* WAudio::Path(void) const
{
	return m_path;
}

const wchar_t* WAudio::Name(void) const
{
	return m_name;
}

void WAudio::Play(void)
{
	std::wstring cmd = L"";
	cmd += L"stop ";
	cmd += m_name;
	mciSendString(cmd.c_str(), nullptr, 0, WContainer::Handle());

	cmd = L"";
	cmd += L"play ";
	cmd += m_name;
	mciSendString(cmd.c_str(), nullptr, 0, WContainer::Handle());
}

void WAudio::Pause(void)
{
	std::wstring cmd = L"";
	cmd += L"pause ";
	cmd += m_name;
	mciSendString(cmd.c_str(), nullptr, 0, WContainer::Handle());
}

void WAudio::Resume(void)
{
	std::wstring cmd = L"";
	cmd += L"resume ";
	cmd += m_name;
	mciSendString(cmd.c_str(), nullptr, 0, WContainer::Handle());
}

void WAudio::Stop(void)
{
	std::wstring cmd = L"";
	cmd += L"stop ";
	cmd += m_name;
	mciSendString(cmd.c_str(), nullptr, 0, WContainer::Handle());
}

void WAudio::PlayOnRepeat(void)
{
	std::wstring cmd = L"";
	cmd += L"stop ";
	cmd += m_name;
	mciSendString(cmd.c_str(), nullptr, 0, WContainer::Handle());

	cmd = L"";
	cmd += L"play ";
	cmd += m_name;
	cmd += L" repeat";
	mciSendString(cmd.c_str(), nullptr, 0, WContainer::Handle());
}
