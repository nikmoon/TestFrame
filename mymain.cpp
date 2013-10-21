
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


int SeeThis()
{
	RECT rtClient = {0,0,600,300};
	::AdjustWindowRect(&rtClient,WS_OVERLAPPEDWINDOW,FALSE);

	CDialogFrame frameMain(GetModuleHandle(NULL),CS_HREDRAW|CS_VREDRAW,NULL,NULL,NULL,NULL,"MainFrame",WS_OVERLAPPEDWINDOW,0,
			"App main window",NULL,100,100,rtClient.right - rtClient.left,rtClient.bottom - rtClient.top);

	for(int y = 0; y < 300; y += 50)
	{
		for(int x = 0; x < 600; x += 100)
		{
//			frameMain.AddButton("Кнопочка )))", x,y,100,50);
		}
	}

	frameMain.AddTreeView("TreeView", 0, 0, 200, 100);
	frameMain.AddStateButton("Push", 50, 110, 150, 50);
	frameMain.ShowFrame();
	frameMain.UpdateFrame();

	return RunThreadMessageLoop();
}


int main(int argc, char **argv)
{


	return SeeThis();
}
