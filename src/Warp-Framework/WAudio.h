//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_AUDIO_H_
#define _W_AUDIO_H_

#include "WEntity.h"
#include "WWin.h"
#include "WMci.h"
#include "WContainer.h"
#include <string>

class WAudio : public WEntity
{
public:
	WAudio(const wchar_t* name, const wchar_t* path);
	~WAudio(void);

	// Getters
	const wchar_t* Path(void) const;
	const wchar_t* Name(void) const;

	// Functions
	void Play(void);
	void Pause(void);
	void Resume(void);
	void Stop(void);
	void PlayOnRepeat(void);


private:
	const wchar_t* m_name;
	const wchar_t* m_path;

};

#endif // !_W_AUDIO_H_
