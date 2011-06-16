// Copyright 2008-2011 Zhang Yun Gui, rhcad@hotmail.com
// http://sourceforge.net/projects/x3c/

#ifndef _X3_CORE_LOGMANAGER_H
#define _X3_CORE_LOGMANAGER_H

#include <Log/Ix_LogManager.h>

class Cx_LogManager
    : public Ix_LogManager
{
protected:
    Cx_LogManager();
    virtual ~Cx_LogManager();

protected:
    virtual bool RegisterObserver(Ix_LogObserver* observer);
    virtual void UnRegisterObserver(Ix_LogObserver* observer);
    virtual bool PushGroup(const wchar_t* msg, const wchar_t* extra);
    virtual bool PopGroup();
    virtual bool WriteLog(x3LogType type, const wchar_t* msg, 
        const wchar_t* extra, const char* file, long line);
    virtual bool WriteLog(x3LogType type, const char* msg, 
        const char* extra, const char* file, long line);
    virtual int CrtDbgReport(const char* msg, const char* file, long line);

private:
    const char* TrimFileName(const char* file);
    bool CheckMsgParam(std::wstring& msg2, std::wstring& extra2, 
        std::wstring& module, std::wstring& idname, 
        const wchar_t* msg, const wchar_t* extra);

private:
    typedef std::vector<Ix_LogObserver*>::iterator ObserverIt;
    std::vector<Ix_LogObserver*>      m_observers;
    long                            m_groupLevel;
    long                            m_loglock;
};

#endif // _X3_CORE_LOGMANAGER_H
