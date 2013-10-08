
#include <iostream>
#include <windows.h>
#include "CFrame.h"


using namespace std;
using namespace AppFrameNameSpace;


int RunThreadMessageLoop()
{
	BOOL haveMsg;
	MSG msg;

	// �������� ���� ��������� �������
	while ((haveMsg = GetMessage(&msg, NULL, 0, 0)) != 0)
	{
		if (haveMsg == -1)
		{
			//	������
			return -1;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

int main(int argc, char * argv[])
{
	CTestFrame mainFrame(GetModuleHandle(NULL), "MyWindow");
	return RunThreadMessageLoop();
}
