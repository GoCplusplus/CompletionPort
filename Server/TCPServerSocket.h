#ifndef __CTCPSERVERSOCKET__H
#define __CTCPSERVERSOCKET__H
#include <iostream>
#include <atomic>
#include <mutex>
#include "TCPClientSocketManage.h"


// �ص����ݽṹ����
struct OverlapptedData
{
	OVERLAPPED Overlapped; // �ص�����
	WSABUF WsaBuff; // ���ջ�����
	char   szRecvBuff[1024]; // ���ջ���
	OverlapptedData()
	{
		memset(this, 0, sizeof(OverlapptedData));
	}
};

// �����ģ��

class CTCPServerSocket
{
public:
	CTCPServerSocket(std::string& strIP, int nPort);
	~CTCPServerSocket();

public:
	bool Start()
	{
		return Init();
	}

	const char* GetErrorMsg()
	{
		return m_strErrorMsg.c_str();
	}

	bool Stop(); // �˳�

private:
	bool Init(); // ��ʼ��socket
	void InitCompletionPort(); // ��ʼ����ɶ˿�

private:
	void ErrorMsg(const char* err, ...);
	void CleanSocket();

private:
	std::string m_strIP;
	int         m_nPort;
	std::string m_strErrorMsg; // �������
	SOCKET      m_sServerSocket;
	std::atomic<bool> m_bRun;
	HANDLE      m_hCompletionPort; // ��ɶ˿�
	int         m_nSystemInfo; // ���������ĸ���
	std::thread* m_thWorker; // �������߳�
	std::thread m_thAccept; // accept�߳�

	CTCPClientSocketManage m_clientMange;
};

#endif