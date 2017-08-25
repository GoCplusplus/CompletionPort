#include "TCPServerSocket.h"

int main()
{
	std::string ip = "192.168.1.106";
	CTCPServerSocket server(ip, 8080);
	bool bRet = server.Start();
	if (!bRet)
		std::cout << "start server error" << server.GetErrorMsg() << std::endl;

	while (1)
	{

	}

	Sleep(10 * 1000);
	server.Stop(); // �����Ƿ�����˳�
	return 0;
}