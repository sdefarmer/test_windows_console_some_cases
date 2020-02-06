// testpthread.cpp

#include "testpthread.h"
#include <Windows.h>
#include "pthread\include\pthread.h"

#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

// 测试目的：pthread使用释放存在内存泄漏

// 总结：


class CTestPthread
{
public:
	CTestPthread()
	{
		pthread_mutex_init(&m_task_mutex, 0);
		pthread_cond_init(&m_task_event, 0);
		pthread_cond_init(&m_wait_event, 0);

		m_hThread = ::CreateThread(0, 0, run, this, 0, 0);
	}
	virtual ~CTestPthread()
	{
		int n = 10;
		while (n--)
		{
			pthread_mutex_lock(&m_task_mutex);
			pthread_cond_signal(&m_task_event);
			pthread_cond_signal(&m_task_event);
			pthread_cond_signal(&m_task_event);
			pthread_cond_signal(&m_task_event);
			pthread_cond_signal(&m_task_event);
			pthread_mutex_unlock(&m_task_mutex);
			Sleep(100);
		}
		m_bRun = false;
		pthread_mutex_lock(&m_task_mutex);
		pthread_cond_broadcast(&m_task_event);
		pthread_mutex_unlock(&m_task_mutex);
		while (!m_bRun)
			Sleep(100);

		pthread_cond_destroy(&m_wait_event);
		pthread_cond_destroy(&m_task_event);
		pthread_mutex_destroy(&m_task_mutex);

		CloseHandle(m_hThread);
	}
	HANDLE m_hThread;

	static  DWORD CALLBACK run(LPVOID p)
	{
		CTestPthread *pMe = (CTestPthread*)p;
		pMe->m_bRun = true;

		while (pMe->m_bRun)
		{
			pthread_mutex_lock(&pMe->m_task_mutex);
			pthread_cond_wait(&pMe->m_task_event, &pMe->m_task_mutex);
			//pthread_cond_init(&pMe->m_task_event, 0);
			pthread_mutex_unlock(&pMe->m_task_mutex);
		}
		pMe->m_bRun = true;
		return 0;
	}

	bool m_bRun;
	pthread_mutex_t m_task_mutex;
	pthread_cond_t  m_task_event;
	pthread_cond_t  m_wait_event;
};


void testpthread()
{
	CTestPthread mythread;
}

//////////////////////////////////////////////////////////////

// 测试结果：若event使用相同的名称，将导致共享一个事件，需要注意


HANDLE hThread;
HANDLE hEvent1;
HANDLE hEvent2;
DWORD CALLBACK ThreadEvent(void *p)
{
	::ResetEvent(hEvent1);
	::ResetEvent(hEvent2);
	::WaitForSingleObject(hEvent1, -1);
	::WaitForSingleObject(hEvent2, -1);
	return 0;
}
void CreateOneThread()
{
	hEvent1 = ::CreateEvent(0, 1, 0, 0);
	hEvent2 = ::CreateEvent(0, 1, 0, 0);
	hThread = ::CreateThread(0, 0, ThreadEvent, 0, 0, 0);
	Sleep(2000);
	::SetEvent(hEvent1);
	Sleep(2000);
	::SetEvent(hEvent2);
	Sleep(2000);
}


void testEvent()
{
	CreateOneThread();
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

// 测试结果：若Mutex使用相同的名称，将导致共享一个事件，需要注意


HANDLE hThreadMutex;
HANDLE hMutex1;
HANDLE hMutex2;
DWORD CALLBACK ThreadMutex(void *p)
{
	::WaitForSingleObject(hMutex1, -1);
	::WaitForSingleObject(hMutex2, -1);
	while (1) {
		int *pppp = new int[2];
		Sleep(10);
	}
	return 0;
}
void CreateOneMutexThread()
{
	hMutex1 = ::CreateMutex(0, 1, L"123");
	hMutex2 = ::CreateMutex(0, 1, L"123");
	hThreadMutex = ::CreateThread(0, 0, ThreadMutex, 0, 0, 0);
	Sleep(2000);
	::ReleaseMutex(hMutex1);
	Sleep(2000);
	::ReleaseMutex(hMutex2);
	Sleep(2000);
}


void testMutex()
{
	CreateOneMutexThread();
}