#ifdef USE_PCH
#include "rr_pch.h"
#endif
#pragma hdrstop
#include <stdexcept>
#include <stdio.h>
#include "rrLogFile.h"
//---------------------------------------------------------------------------

namespace rr
{

using std::fstream;
LogFile::LogFile(const string& name)
:
mFileName(name),
mFILEHandle(fopen(name.c_str(), "w"))
{
    if (!mFILEHandle && name.size())
    {
        throw std::runtime_error("File Open failure");
    }
}

LogFile::~LogFile()
{
	if(mFILEHandle)
	{
		fclose(mFILEHandle);
	}
}

string LogFile::GetFileName()
{
	return mFileName;
}
}
