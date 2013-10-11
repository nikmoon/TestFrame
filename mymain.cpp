
#include <iostream>
#include <windows.h>
#include "CFrame.h"


using namespace std;
using namespace AppFrameNameSpace;


int RunThreadMessageLoop()
{
	BOOL haveMsg;
	MSG msg;

	// циклично ждем сообщения системы
	while ((haveMsg = GetMessage(&msg, NULL, 0, 0)) != 0)
	{
		if (haveMsg == -1)
		{
			//	Ошибка
			return -1;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

int main(int argc, char * argv[])
{
//	CTestFrame * mainFrame = new CTestFrame(GetModuleHandle(NULL), "MyWindow");
//	int res = RunThreadMessageLoop();
//	delete mainFrame;
//	return res;
//	CTestFrame mainFrame = CTestFrame(GetModuleHandle(NULL), "MyWindow");
//	return RunThreadMessageLoop();
	return 0;
}
