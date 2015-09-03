#pragma once

#ifndef __CSMTP_H__
#define __CSMTP_H__

#include <vector>
#include <string.h>
#include <assert.h>

#ifdef __linux__
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <sys/ioctl.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <netdb.h>
	#include <errno.h>
	#include <stdio.h>
	#include <iostream>
	#include <unistd.h>

	#define SOCKET_ERROR -1
	#define INVALID_SOCKET -1

#ifndef HAVE__STRNICMP
	#define HAVE__STRNICMP
	#define _strnicmp strncasecmp
#endif

	#define OutputDebugStringA(buf)

	typedef unsigned short WORD;
	typedef int SOCKET;
	typedef struct sockaddr_in SOCKADDR_IN;
	typedef struct hostent* LPHOSTENT;
	typedef struct servent* LPSERVENT;
	typedef struct in_addr* LPIN_ADDR;
	typedef struct sockaddr* LPSOCKADDR;

	#define LINUX
#else
	#include <winsock2.h>
	#include <time.h>
	#pragma comment(lib, "ws2_32.lib")

	#if _MSC_VER < 1400
		#define snprintf _snprintf
	#else
		#define snprintf sprintf_s
	#endif
#endif

#include "md5.h"

#define TIME_IN_SEC 3 * 60
#define BUFFER_SIZE 10240
#define MSG_SIZE_IN_MB 5
#define COUNTER_VALUE 100

const char BOUNDARY_TEXT[] = "__MESSAGE__ID__54yg6f6h6y456345";

enum CSmptXPriority
{
	XPRIORITY_HIGH = 2,
	XPRIORITY_NORMAL = 3,
	XPRIORITY_LOW = 4
};

class ECSmtp
{
public:
	enum CSmtpError
	{
		CSMTP_NO_ERROR = 0,
		WSA_STARTUP = 100,
		WSA_VER,
		WSA_SEND,
		WSA_RECV,
		WSA_CONNECT,
		WSA_GETHOSTBY_NAME_ADDR,
		WSA_INVALID_SOCKET,
		WSA_HOSTNAME,
		WSA_IOCTLSOCKET,
		WSA_SELECT,
		BAD_IPV4_ADDR,
		UNDEF_MSG_HEADER = 200,
		UNDEF_MAIL_FROM,
		UNDEF_SUBJECT,
		UNDEF_RECIPIENTS,
		UNDEF_LOGIN,
		UNDEF_PASSWORD,
		BAD_LOGIN_PASSWORD,
		BAD_DIGEST_RESPONSE,
		BAD_SERVER_NAME,
		UNDEF_RECIPIENT_MAIL,
		COMMAND_MAIL_FROM = 300,
		COMMAND_EHLO,
		COMMAND_AUTH_PLAIN,
		COMMAND_AUTH_LOGIN,
		COMMAND_AUTH_CRAMMD5,
		COMMAND_AUTH_DIGESTMD5,
		COMMAND_DIGESTMD5,
		COMMAND_DATA,
		COMMAND_QUIT,
		COMMAND_RCPT_TO,
		MSG_BODY_ERROR,
		CONNECTION_CLOSED = 400,
		SERVER_NOT_READY,
		SERVER_NOT_RESPONDING,
		SELECT_TIMEOUT,
		FILE_NOT_EXIST,
		MSG_TOO_BIG,
		BAD_LOGIN_PASS,
		UNDEF_XYZ_RESPONSE,
		LACK_OF_MEMORY,
		TIME_ERROR,
		RECVBUF_IS_EMPTY,
		SENDBUF_IS_EMPTY,
		OUT_OF_MSG_RANGE,
		COMMAND_EHLO_STARTTLS,
		SSL_PROBLEM,
		COMMAND_DATABLOCK,
		STARTTLS_NOT_SUPPORTED,
		LOGIN_NOT_SUPPORTED
	};

	ECSmtp(CSmtpError err_) : ErrorCode(err_) {}
	CSmtpError GetErrorNum(void) const { return ErrorCode; }
	std::string GetErrorText(void) const;

private:
	CSmtpError ErrorCode;
};

enum SMTP_COMMAND
{
	command_INIT,
	command_EHLO,
	command_AUTHPLAIN,
	command_AUTHLOGIN,
	command_AUTHCRAMMD5,
	command_AUTHDIGESTMD5,
	command_DIGESTMD5,
	command_USER,
	command_PASSWORD,
	command_MAILFROM,
	command_RCPTTO,
	command_DATA,
	command_DATABLOCK,
	command_DATAEND,
	command_QUIT,
	command_STARTTLS
};

enum SMTP_SECURITY_TYPE
{
	NO_SECURITY,
	DO_NOT_SET
};

typedef struct tagCommand_Entry
{
	SMTP_COMMAND command;
	int send_timeout;
	int recv_timeout;
	int valid_reply_code;
	ECSmtp::CSmtpError error;
}
Command_Entry;

class CSmtp
{
public:
	CSmtp(void);
	virtual ~CSmtp(void);

public:
	void AddRecipient(const char *email, const char *name = NULL);
	void AddBCCRecipient(const char *email, const char *name = NULL);
	void AddCCRecipient(const char *email, const char *name = NULL);
	void AddAttachment(const char *path);
	void AddMsgLine(const char *text);
	void ClearMessage(void);
	bool ConnectRemoteServer(const char *szServer, const unsigned short nPort_ = 0, SMTP_SECURITY_TYPE securityType = DO_NOT_SET, bool authenticate = true, const char *login = NULL, const char *password = NULL);
	void DisconnectRemoteServer(void);
	void DelRecipients(void);
	void DelBCCRecipients(void);
	void DelCCRecipients(void);
	void DelAttachments(void);
	void DelMsgLines(void);
	void DelMsgLine(unsigned int line);
	void ModMsgLine(unsigned int line,const char *text);
	unsigned int GetBCCRecipientCount(void) const;
	unsigned int GetCCRecipientCount(void) const;
	unsigned int GetRecipientCount(void) const;
	const char *GetLocalHostIP(void) const;
	const char *GetLocalHostName(void);
	const char *GetMsgLineText(unsigned int line) const;
	unsigned int GetMsgLines(void) const;
	const char *GetReplyTo(void) const;
	const char *GetMailFrom(void) const;
	const char *GetSenderName(void) const;
	const char *GetSubject(void) const;
	const char *GetXMailer(void) const;
	CSmptXPriority GetXPriority(void) const;
	void Send(void);
	void SetCharSet(const char *sCharSet);
	void SetLocalHostName(const char *sLocalHostName);
	void SetSubject(const char *);
	void SetSenderName(const char *);
	void SetSenderMail(const char *);
	void SetReplyTo(const char *);
	void SetReadReceipt(bool requestReceipt = true);
	void SetXMailer(const char *);
	void SetLogin(const char *);
	void SetPassword(const char *);
	void SetXPriority(CSmptXPriority);
	void SetSMTPServer(const char *server, const unsigned short port = 0, bool authenticate = true);

private:	
	std::string m_sLocalHostName;
	std::string m_sMailFrom;
	std::string m_sNameFrom;
	std::string m_sSubject;
	std::string m_sCharSet;
	std::string m_sXMailer;
	std::string m_sReplyTo;
	bool m_bReadReceipt;
	std::string m_sIPAddr;
	std::string m_sLogin;
	std::string m_sPassword;
	std::string m_sSMTPSrvName;
	unsigned short m_iSMTPSrvPort;
	bool m_bAuthenticate;
	CSmptXPriority m_iXPriority;
	char *SendBuf;
	char *RecvBuf;

	SOCKET hSocket;
	bool m_bConnected;

	struct Recipient
	{
		std::string Name;
		std::string Mail;
	};

	std::vector<Recipient> Recipients;
	std::vector<Recipient> CCRecipients;
	std::vector<Recipient> BCCRecipients;
	std::vector<std::string> Attachments;
	std::vector<std::string> MsgBody;

	void ReceiveData(Command_Entry *pEntry);
	void SendData(Command_Entry *pEntry);
	void FormatHeader(char *);
	int SmtpXYZdigits(void);
	void SayHello(void);
	void SayQuit(void);

public:
	SMTP_SECURITY_TYPE GetSecurityType(void) const { return m_type; }
	void SetSecurityType(SMTP_SECURITY_TYPE type) { m_type = type; }

public:
	bool m_bHTML;

private:
	SMTP_SECURITY_TYPE m_type;

private:
	void ReceiveResponse(Command_Entry *pEntry);
};

#endif