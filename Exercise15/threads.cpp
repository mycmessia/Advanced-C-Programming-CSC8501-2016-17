#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Thread
{
public:
	Thread () {}
	virtual ~Thread () { CloseHandle (thread_handle); }
	virtual void start ();
	virtual void join ();
	virtual DWORD get_id () const { return tid; }

protected:
	virtual void run () = 0;
	friend DWORD thread_ftn (LPVOID T);
	HANDLE thread_handle;
	DWORD tid;

private:
	Thread (const Thread& src);
	Thread& operator= (const Thread& rhs);
};