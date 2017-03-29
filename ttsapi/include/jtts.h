#ifndef _JTTS_H_
#define _JTTS_H_

#pragma pack( push, jtts_h )
#pragma pack( 8 )

#ifdef __cplusplus
extern "C"
{
#endif

#define TTSAPI __stdcall
/*
����һ��: 

	jTTSPreInit			��ʼ��֮ǰ����ϵͳ����ȡ������
	jTTSInit			��ʼ��jTTS���ģ���ȡ����
	jTTSEnd				�ͷ�jTTS����ռ���ڴ�
	jTTSSetLogFile		����ϵͳ�ļ�¼��־�ļ�

	jTTSSetPlay			ȷ�������豸�ͷ��������еĻص�����
	jTTSPlay			���÷����豸�Ķ�ָ�����ı�
	jTTSStop			��ֹ��ǰ���Ķ�
	jTTSPause			��ͣ��ǰ���Ķ�
	jTTSResume			�ָ���ǰ���Ķ�
	jTTSSetParam		���ò���
	jTTSGetParam		�õ�����
	jTTSSetRemoteParam	����Զ�̺ϳɲ���
	jTTSGetRemoteParam	�õ�Զ�̺ϳɲ���
	jTTSSet2			ͨ���ṹ�ķ�ʽһ�������������ϳɵ����в���
	jTTSGet2			ͨ���ṹ�ķ�ʽһ���Ի�������ϳɵ����в���
	jTTSSetRemote		ͨ���ṹ�ķ�ʽһ��������Զ�������ϳɵ����в���
	jTTSGetRemote		ͨ���ṹ�ķ�ʽһ���Ի��Զ�������ϳɵ����в���
	jTTSPlayToFileEx	���ı����������ϳɣ������д�������ļ�������ʹ�ô���ĺϳɲ�����
	                    ʹ���µĻص����������Իش��û�ָ��������

	jTTSSessionStartEx	��ʼֱ�ӵõ��������������ϳɹ���
	jTTSSessionGetDataEx	���������ϳɣ�ֱ�ӵõ���������ʹ���ڲ�������
	jTTSSessionRemoteConfig	����Զ�̵���ʱ�Ĳ���
	jTTSSessionStop			��ֱֹ�ӵõ��������������ϳɹ���
	jTTSSessionGetReadBytes ����Ѻϳ���ϵ��ֽ���

	jTTSSessionStart	��ʼֱ�ӵõ��������������ϳɹ���
	jTTSSessionConfig2	���������ϳɹ��̵Ĳ�����ʹ���µĽṹ
*/

//ERRCODE
typedef enum 
{
	ERR_NONE,			//	0
	ERR_ALREADYINIT,	//	1
	ERR_NOTINIT,		//	2 
	ERR_MEMORY,			//	3
	ERR_INVALIDHWND,	//	4
	ERR_INVALIDFUNC,	//	5
	ERR_OPENLIB,		//	6
	ERR_READLIB,		//	7
	ERR_PLAYING,		//	8
	ERR_DONOTHING,		//	9
	ERR_INVALIDTEXT,	//	10
	ERR_CREATEFILE,		//	11
	ERR_WRITEFILE,		//	12
	ERR_FORMAT,			//	13
	ERR_INVALIDSESSION,	//	14
	ERR_TOOMANYSESSION,	//	15
	ERR_MORETEXT,		//	16
	ERR_CONFIG,			//	17
	ERR_OPENDEVICE,		//	18
	ERR_RESETDEVICE,	//	19
	ERR_PAUSEDEVICE,	//	20
	ERR_RESTARTDEVICE,	//	21
	ERR_STARTTHREAD,	//	22
	ERR_BEGINOLE,		//	23
	ERR_NOTSUPPORT,		//	24
	ERR_SECURITY,		//	25
	ERR_CONVERT,		//	26
	ERR_PARAM,			//	27
	ERR_INPROGRESS,		//  28
	ERR_INITSOCK,		//	29
	ERR_CREATESOCK,		//	30
	ERR_CONNECTSOCK,	//	31
	ERR_TOOMANYCON,		//	32
	ERR_CONREFUSED,		//	33
	ERR_SEND,			//	34
	ERR_RECEIVE,		//	35
	ERR_SERVERSHUTDOWN,	//	36
	ERR_OUTOFTIME,		//	37
	ERR_CONFIGTTS,		//	38
	ERR_SYNTHTEXT,		//	39
	ERR_CONFIGVERSION,	//	40
	ERR_EXPIRED,		//	41
	ERR_NEEDRESTART,	//	42
	ERR_CODEPAGE,		//	43
	ERR_ENGINE,			//	44
	ERR_CREATEEVENT,	//	45
	ERR_PLAYMODE,		//	46
	ERR_OPENFILE,		//	47
	ERR_USERABORT,		//  48
	ERR_LICENSEFULL,	//	49
	ERR_LICENSEFILEINVALID,	//	50
	ERR_LICENSE,		//	51
	ERR_LICENSEEXPIRED, //  52
}ERRCODE;

// Log File Flag
#define LOG_TEXT	0x01	// �Ƿ�����־�ļ��м�¼�ϳɵ��ı�
#define LOG_SESSION	0x02	// �Ƿ��¼ÿ��Session���̵���ϸ�������

#define WM_JTTS_NOTIFY	(WM_USER + 0x4999)

// wParam of WM_JTTS_NOTIFY or JTTSCALLBACKPROC
#define NOTIFY_BEGIN		0	// lParam: not use 
#define NOTIFY_END			1	// lParam: not use
#define NOTIFY_PROGRESS		2	// lParam: bytes of content have been read
#define NOTIFY_PROGRESS2	3	// lParam: end postion of content will be read in next session
#define NOTIFY_MARK			4	// lParam: ���Mark����λ�úͳ���, �ο���GETMARKOFFSET��GETMARKLEN
#define NOTIFY_VISEME		5	// lParam: ��Ǵ�����Ϣ���ְ汾��δʹ��

#define STATUS_NOTINIT	0
#define STATUS_READING	1
#define STATUS_PAUSE	2
#define STATUS_IDLE		3


#define VID_MALE1			0
#define VID_FEMALE1			1

//BACKAUDIO
#define BACKAUDIO_NONE			0		// û�б�������
#define BACKAUDIO_MIN			1		// ��С�ı����������
#define BACKAUDIO_MAX			10000	// ���ı����������

//VOICESYTLE
#define VOICESTYLE_CADENCE		0		// ����ٴ� jTTS 3.0���ġ�
#define VOICESTYLE_FLAT			1		// ƽ��ׯ��

//VOICEBUFSIZE
#define VOICEBUFSIZE_DEFAULT	0		// Default: 128K
#define VOICEBUFSIZE_MIN		16		// 16K
#define VOICEBUFSIZE_MAX		8192	// 8M

//INSERTINFOSIZE
#define INSERTINFOSIZE_DEFAULT	0		// Default: 100
#define INSERTINFOSIZE_MIN		1
#define INSERTINFOSIZE_MAX		1000

// BackAudio Flag
#define BACKAUDIOFLAG_REPEAT	0x01

// BackAudio Volume
#define AUDIOVOLUME_MIN		0
#define AUDIOVOLUME_MAX		100

// Volume, Speed, Pitch
#define VOLUME_MIN	0
#define VOLUME_MAX	9
#define SPEED_MIN	0
#define SPEED_MAX	9
#define PITCH_MIN	0
#define PITCH_MAX	9

// PuncMode
#define PUNC_OFF		0	/* �������ţ��Զ��жϻس������Ƿ�ָ���*/
#define PUNC_ON			1	/* �����ţ�  �Զ��жϻس������Ƿ�ָ���*/
#define PUNC_OFF_RTN	2	/* �������ţ�ǿ�ƽ��س�������Ϊ�ָ���*/
#define PUNC_ON_RTN		3	/* �����ţ�  ǿ�ƽ��س�������Ϊ�ָ���*/


// DigitMode���ڴ˰汾�У�������DIGIT_AUTO_TELEGRAM���޷��Զ��жϵ����ִ�������������
#define DIGIT_AUTO_NUMBER	0
#define DIGIT_TELEGRAM		1
#define DIGIT_NUMBER		2
#define DIGIT_AUTO_TELEGRAM	3

#define DIGIT_AUTO			DIGIT_AUTO_NUMBER

// EngMode
#define ENG_AUTO			0	/* �Զ���ʽ */
#define ENG_ENGENGINE		1	/* ǿ��ʹ��Ӣ������ */
#define ENG_LETTER			2	/* ǿ�Ƶ���ĸ��ʽ */
#define ENG_LETTER_PHRASE	3	/* ����ĸ����¼���ʷ�ʽ */

#define ENG_SAPI			1	/* ǿ��SAPI ��jTTS3.0����*/

//֧��TAG
#define TAG_AUTO				0x00	// �Զ��ж�
#define TAG_JTTS				0x01	// ����������jTTS 3.0֧�ֵ�TAG: \read=\  
#define TAG_SSML				0x02	// ����������SSML ��TAG: <voice gender="female" />
#define TAG_NONE				0x03	// û��TAG

// Domain
//��jTTS 4.0רҵ����֧�ֶ�����
// 
//�����г�����ϵͳ�ڽ��������壬��Ҫ��װ��Ӧ�������Դ����������֧�֡�
//
//��������û���г������򣬽���Ҳ���ܻᷢ����Ӧ����Դ����ͬʱ�����һ����ֵ��
//ֻҪ��װ����Դ���󣬾Ϳ���ʹ�á�����û���г������������ʹ�ã�����ֱ��ʹ����ֵ
//
//����ͨ��Domainϵ�к����õ�����ϵͳ�ж���ģ�����������չ�ģ�������ֵ������������Ϣ

//Ϊ��֧��Domain����Ҫʹ��JTTSCONFIG4��

#define DOMAIN_COMMON			0		// ͨ����������
#define DOMAIN_FINANCE			1		// ����֤ȯ
#define DOMAIN_WEATHER			2		// ����Ԥ��
#define DOMAIN_SPORTS			3		// ��������
#define DOMAIN_TRAFFIC			4		// ������Ϣ
#define DOMAIN_TRAVEL			5		// ���β���
#define DOMAIN_CARBORNE			6		//����
#define DOMAIN_QUEUE			7		//�Ŷ�
#define DOMAIN_SONG				8		//���
#define DOMAIN_INSURANCE		9		//����
#define DOMAIN_VOYAGE			10		//����
#define DOMAIN_REVENUE			11		//˰��
#define DOMAIN_ELECPOWER		12		//����
#define DOMAIN_MESSAGE			13		//����

#define DOMAIN_CUSTOM			30		// һ�㶨������

#define DOMAIN_MIN				0
#define DOMAIN_MAX				31

// CodePage���ڴ˰汾�У�CP_GB2312��CP_GBK��Ч  
// CP_xxx ֻ���ڼ���3.0���µĳ���Ӧ��ʹ��CODEPAGE_xxx��ֵ
#define CP_GB2312		0	
#define CP_GBK			1	
#define CP_BIG5			2
#define CP_UNICODE		3

//֧�ֵ�CODEPAGE 4.0 ���µı�׼
#define CODEPAGE_GB		        936		// ����GB18030, GBK, GB2312
#define CODEPAGE_BIG5		    950
#define CODEPAGE_SHIFTJIS	    932
#define CODEPAGE_KCS			949
#define CODEPAGE_ISO8859_1		1252
#define CODEPAGE_UNICODE		1200
#define CODEPAGE_UNICODE_BIGE	1201	// BIG Endian
#define CODEPAGE_UTF8 			65001

typedef enum 
{
	PARAM_CODEPAGE,			// CP_xxx
	PARAM_VOICEID,			// VID_xxx
	PARAM_PITCH,			// PITCH_MIN - PITCH_MAX
	PARAM_VOLUME,			// VOLUME_MIN - VOLUME_MAX
	PARAM_SPEED,			// SPEED_MIN - SPEED_MAX
	PARAM_PUNCMODE,			// PUNCMODE_xxx
	PARAM_DIGITMODE,		// DIGITMODE_xxx
	PARAM_ENGMODE,			// ENGMODE_xxx
	PARAM_TAGMODE,			// TAG_xxx
	PARAM_DOMAIN,		    // DOMAIN_xxx
	PARAM_VOICESTYLE,		// VOICESTYLE_xxx
	PARAM_BACKAUDIO,		// 0: no backaudio, from 1: backaudio order
	PARAM_BACKAUDIOVOLUME,	// BACKAUDIOVOLUME_MIN - BACKAUDIOVOLUME_MAX
	PARAM_BACKAUDIOFLAG,	// BACKAUDIOFLAG_xxx
	PARAM_VOICEBUFSIZE,		// VOICEBUFSIZE_DEFAULT, or n (K)
	PARAM_INSERTINFOSIZE,	// INSERTINFOSIZE_DEFAULT, or n
}JTTSPARAM;

typedef enum 
{
	PARAM_REMOTE_TRYTIMES,			// �Ϸ�ֵ��1 - 100, ȱʡֵ��10
	PARAM_REMOTE_LOADBALANCE,		// �Ϸ�ֵ��TRUE, FALSE, ȱʡֵ��FALSE
}JTTSREMOTEPARAM;

#define FORMAT_WAV			0	// PCM Native (ĿǰΪ16KHz, 16Bit)
#define FORMAT_VOX_6K		1	// OKI ADPCM, 6KHz, 4bit (Dialogic Vox)
#define FORMAT_VOX_8K		2	// OKI ADPCM, 8KHz, 4bit (Dialogic Vox)
#define FORMAT_ALAW_8K		3	// A��, 8KHz, 8Bit
#define FORMAT_uLAW_8K		4	// u��, 8KHz, 8Bit
#define FORMAT_WAV_8K8B		5	// PCM, 8KHz, 8Bit
#define FORMAT_WAV_8K16B	6	// PCM, 8KHz, 16Bit
#define FORMAT_WAV_16K8B	7	// PCM, 16KHz, 8Bit
#define FORMAT_WAV_16K16B	8	// PCM, 16KHz, 16Bit
#define FORMAT_WAV_11K8B	9	// PCM, 11.025KHz, 8Bit
#define FORMAT_WAV_11K16B	10	// PCM, 11.025KHz, 16Bit
#define FORMAT_MP3			11	// PCM, 40KBit/s

#define FORMAT_FIRST		0
#define FORMAT_LAST			11

//jTTSPlayToFileEx�����в���dwFlag����ֵ����
#define PLAYTOFILE_DEFAULT	0	//Ĭ��ֵ,д�ļ�ʱֻ����FORMAT_WAV_...��ʽ���ļ�ͷ
#define PLAYTOFILE_NOHEAD	1	//���еĸ�ʽ���������ļ�ͷ
#define PLAYTOFILE_ADDHEAD	2	//����FORMAT_WAV_...��ʽ��FORMAT_ALAW_8K,FORMAT_uLAW_8K��ʽ���ļ�ͷ

//JTTSCONFIG2 ��Ҫ������jTTS3.0���ݣ�����֧��jTTS4.0���¹��ܣ�
//�����ҪjTTS4.0���¹��ܣ���ʹ��JTTSCONFIG4�ṹ��
#define JTTS_VERSION	0x0002	// version 2.0 

typedef struct 
{
	WORD wVersion;
	UINT nCodePage;
	UINT nVoiceID;
	int nPitch;
	int nVolume;
	int nSpeed;
	int nPuncMode;
	int nDigitMode;
	int nEngMode;
}JTTSCONFIG2;

//�µ�JTTSCONFIG4�ṹ����jTTS 4.0רҵ�棬
//������Ҫ����JTTSCONFIG2ָ��������������ʹ��JTTSCONFIG4ָ����档
#define JTTS_VERSION4		0x0004	//����jTTS 4.0רҵ��
typedef struct JTTSCONFIG_4
{
	WORD	wVersion;				// JTTS_VERSION4
	UINT 	nCodePage;
	UINT 	nVoiceID;
	short	nDomain;	
	short	nPitch;
	short	nVolume;
	short	nSpeed;
	short	nPuncMode;
	short	nDigitMode;
	short	nEngMode;
	short	nTagMode;
	short	nVoiceStyle;
	short	nBackAudio;
	short	nBackAudioVolume;
	WORD	wBackAudioFlag;
	short	nVoiceBufSize;		// �����ڲ��������Ĵ�С
	short	nInsertInfoSize;	// �������в�����Ϣ�ĸ���
	short	nReserved[6];		// ����
}
JTTSCONFIG4;


typedef struct 
{
	WORD wVersion;				// Ӧ��ʹ��JTTS_VERSION
	int nTryTimes;
	BOOL bLoadBalance;
}JTTSREMOTECONFIG;

typedef BOOL (* JTTSCALLBACKPROC)(WORD wParam, LONG lParam);
typedef BOOL (* JTTSCALLBACKPROCEX)(WORD wParam, LONG lParam, DWORD dwUserData);

//------------------------------------------------------------------------
// ϵͳ����

ERRCODE TTSAPI jTTSSetSerialNo(const char * pszSerialNo);
ERRCODE TTSAPI jTTSPreInit(int * arrayVoiceID, int nCount);
ERRCODE TTSAPI jTTSInit(const char * pcszLibPath);
ERRCODE TTSAPI jTTSEnd();
void    TTSAPI jTTSSetLogFile(const char* pcszLogFile, DWORD dwLogFlag);

//------------------------------------------------------------------------
// ���ź��� 

// ��׼�汾�н�֧��uDeviceID == WAVE_MAPPER(-1), ��ȱʡ�������豸
ERRCODE TTSAPI jTTSSetPlay(UINT uDeviceID, HWND hwnd, JTTSCALLBACKPROC lpfnCallback);
ERRCODE TTSAPI jTTSPlay(const char * pcszText);
ERRCODE TTSAPI jTTSStop();
ERRCODE TTSAPI jTTSPause();
ERRCODE TTSAPI jTTSResume();
int		TTSAPI jTTSGetStatus();

//------------------------------------------------------------------------
// ���ŵ��ļ����� 

// ��׼�汾�н�֧��nFormat = FORMAT_WAV, ��д��WAV�ļ���ʽ
// pConfig == NULLʱ��ʹ��ϵͳ��Config
// dwFlag, Ϊ PLAYTOFILE_xxxx������Ҫ���ڱ�ʶ�Ƿ�д�ļ�ͷ
ERRCODE TTSAPI jTTSPlayToFileEx(const char *pcszText, const char * pcszFileName, UINT nFormat, const JTTSCONFIG2 * pConfig, 
						 DWORD dwFlag, JTTSCALLBACKPROCEX lpfnCallbackEx, DWORD dwUserData);

//------------------------------------------------------------------------
// ���ú��� 
ERRCODE TTSAPI jTTSSet2(const JTTSCONFIG2 * pConfig);
ERRCODE TTSAPI jTTSGet2(JTTSCONFIG2 * pConfig);
ERRCODE TTSAPI jTTSSetParam(JTTSPARAM nParam, DWORD dwValue);
ERRCODE TTSAPI jTTSGetParam(JTTSPARAM nParam, DWORD *pdwValue);

//-------------------------------------------------------------
// Զ�̺ϳɲ�������
ERRCODE TTSAPI jTTSSetRemote(const JTTSREMOTECONFIG * pConfig);
ERRCODE TTSAPI jTTSGetRemote(JTTSREMOTECONFIG * pConfig);
ERRCODE TTSAPI jTTSSetRemoteParam(JTTSREMOTEPARAM nParam, DWORD dwValue);
ERRCODE TTSAPI jTTSGetRemoteParam(JTTSREMOTEPARAM nParam, DWORD* pdwValue);

//------------------------------------------------------------------------
// �ϳɹ��̵ײ㺯�� 

ERRCODE TTSAPI jTTSSessionStartEx(const char * pcszText, DWORD * pdwSessionID, UINT nFormat, const JTTSCONFIG2 *pConfig, 
								  int * pnBitsPerSample, int * pnSamplesPerSec);
ERRCODE TTSAPI jTTSSessionRemoteConfig(DWORD dwSessionID, const JTTSREMOTECONFIG *pConfig);
ERRCODE TTSAPI jTTSSessionGetDataEx(DWORD dwSessionID, int nIndex, unsigned char ** ppVoiceData, DWORD * pdwLen, int nReserveLen);
ERRCODE TTSAPI jTTSSessionStop(DWORD dwSessionID);
ERRCODE TTSAPI jTTSSessionGetReadBytes(DWORD dwSessionID, DWORD * pdwBytes);

//���ؾ��������֤��
ERRCODE TTSAPI jTTSLoadBalanceInit(char* pszIPnPort, BOOL bMainServer);
ERRCODE TTSAPI jTTSLoadBalanceEnd();

ERRCODE TTSAPI jTTSSessionStart(const char * pcszText, DWORD * pdwSessionID);
ERRCODE TTSAPI jTTSSessionConfig2(DWORD dwSessionID, const JTTSCONFIG2 *pConfig, int nFormat, int * pnBitsPerSample, int * pnSamplesPerSec);
#ifdef __cplusplus
}
#endif

#pragma pack( pop, jtts_h )

#endif	// _JTTS_H_