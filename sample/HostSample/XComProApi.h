/** ***********************************************************************************
    @file	: XComProApi.h
    @date	: 2016/05/16
	@author	: Linkgenesis(support@linkgenesis.co.kr)
	
*************************************************************************************** */

#pragma once

//========================================================================================
//	IMPORT LIBRARY (x86: XComPro_R40_01_32.lib, x64:XComPro_R40_01_64.lib)
//========================================================================================
#pragma comment(lib, "XComPro_R40_01_32.lib")

//========================================================================================
//	DEFINITION
//========================================================================================
#ifdef __XCOMPRO_API_LIBRARY__
#define XCOMPRO_API_FUNCTION __declspec(dllexport)
#else
#define XCOMPRO_API_FUNCTION __declspec(dllimport)
#endif

//========================================================================================
//	DEFINITION EVENT TYPE : Event type of the PopEvent function
//========================================================================================
#define SECS_EVENT_TYPE				1000
#define SECS_MSG_TYPE				1001

//========================================================================================
//	DECLEARE CLASS
//========================================================================================
class CXComProCtrl;

//========================================================================================
//	DEFINITION FUNCTION POINTER
//========================================================================================
#ifndef __OpCallbackDefine__
#define __OpCallbackDefine__
typedef void (__cdecl *CALLBACK_SECS_EVENT)(void *lpParam, short nEventID, long lParam);
typedef void (__cdecl *CALLBACK_SECS_MSG)(void *lpParam);
#endif

//========================================================================================
//	DEFINITION for DATA TYPE
//========================================================================================
typedef unsigned long       ULONG;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      USHORT;
typedef float               FLOAT;
typedef __int64				LONGLONG;
typedef unsigned __int64	ULONGLONG;
typedef CXComProCtrl		*XCM_Handle;

extern "C"
{
	XCM_Handle XCOMPRO_API_FUNCTION XCM_CreateObject();
	void XCOMPRO_API_FUNCTION XCM_DeleteObject(XCM_Handle pXCom);
	
	//property
	short XCOMPRO_API_FUNCTION XCM_getDeviceID(XCM_Handle pXCom);
	short XCOMPRO_API_FUNCTION XCM_getStream(XCM_Handle pXCom);
	short XCOMPRO_API_FUNCTION XCM_getFunction(XCM_Handle pXCom);
	long XCOMPRO_API_FUNCTION XCM_getSystemBytes(XCM_Handle pXCom);
	short XCOMPRO_API_FUNCTION XCM_getWbit(XCM_Handle pXCom);
	short XCOMPRO_API_FUNCTION XCM_getRbit(XCM_Handle pXCom);
	short XCOMPRO_API_FUNCTION XCM_getEbit(XCM_Handle pXCom);
	short XCOMPRO_API_FUNCTION XCM_getPtype(XCM_Handle pXCom);
	short XCOMPRO_API_FUNCTION XCM_getStype(XCM_Handle pXCom);
	short XCOMPRO_API_FUNCTION XCM_getBlock(XCM_Handle pXCom);
	long XCOMPRO_API_FUNCTION XCM_getHeaderSize(XCM_Handle pXCom);
	long XCOMPRO_API_FUNCTION XCM_getMessageSize(XCM_Handle pXCom);

	//Function
	long XCOMPRO_API_FUNCTION XCM_Initialize(XCM_Handle pXCom, const char *pszCfgFile);
	long XCOMPRO_API_FUNCTION XCM_Close(XCM_Handle pXCom);
	long XCOMPRO_API_FUNCTION XCM_Start(XCM_Handle pXCom);
	long XCOMPRO_API_FUNCTION XCM_Stop(XCM_Handle pXCom);
	long XCOMPRO_API_FUNCTION XCM_MakeSecsMsg(XCM_Handle pXCom, long *plMsgId, short nDevId, short nStrm, short nFunc, long lSysByte);
	long XCOMPRO_API_FUNCTION XCM_Send(XCM_Handle pXCom, long lMsgId);
	long XCOMPRO_API_FUNCTION XCM_LoadSecsMsg(XCM_Handle pXCom, long *plMsgId, short *pnDevId, short *pnStrm, short *pnFunc, long *plSysByte, short *pnWbit);
	void XCOMPRO_API_FUNCTION XCM_CloseSecsMsg(XCM_Handle pXCom, long lMsgId);
	long XCOMPRO_API_FUNCTION XCM_GetListItem(XCM_Handle pXCom, long lMsgId, long *pnItems);
	long XCOMPRO_API_FUNCTION XCM_GetBinaryItem(XCM_Handle pXCom, long lMsgId, BYTE *pnValue, long *plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetBoolItem(XCM_Handle pXCom, long lMsgId, BYTE *pnValue, long *plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetAsciiItem(XCM_Handle pXCom, long lMsgId, char *pszValue, long *plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetJis8Item(XCM_Handle pXCom, long lMsgId, char *pszValue, long *plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetI1Item(XCM_Handle pXCom, long lMsgId, char* pnValue, long* plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetI2Item(XCM_Handle pXCom, long lMsgId, short* pnValue, long* plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetI4Item(XCM_Handle pXCom, long lMsgId, long* plValue, long* plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetI8Item(XCM_Handle pXCom, long lMsgId, LONGLONG* plValue, long* plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetU1Item(XCM_Handle pXCom, long lMsgId, BYTE* pnValue, long* plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetU2Item(XCM_Handle pXCom, long lMsgId, USHORT* plValue, long* plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetU4Item(XCM_Handle pXCom, long lMsgId, ULONG* plValue, long* plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetU8Item(XCM_Handle pXCom, long lMsgId, ULONGLONG* plValue, long* plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetF4Item(XCM_Handle pXCom, long lMsgId, FLOAT* prValue, long* plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetF8Item(XCM_Handle pXCom, long lMsgId, double* prValue, long* plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_SetListItem(XCM_Handle pXCom, long lMsgId, long nItems);
	long XCOMPRO_API_FUNCTION XCM_SetBinaryItem(XCM_Handle pXCom, long lMsgId, BYTE* pnValue, long lCount);
	long XCOMPRO_API_FUNCTION XCM_SetBoolItem(XCM_Handle pXCom, long lMsgId, BYTE* pnValue, long lCount);
	long XCOMPRO_API_FUNCTION XCM_SetAsciiItem(XCM_Handle pXCom, long lMsgId, const char *pszValue, long lCount);
	long XCOMPRO_API_FUNCTION XCM_SetJis8Item(XCM_Handle pXCom, long lMsgId, const char *pszValue, long lCount);
	long XCOMPRO_API_FUNCTION XCM_SetI1Item(XCM_Handle pXCom, long lMsgId, char* pnValue, long lCount);
	long XCOMPRO_API_FUNCTION XCM_SetI2Item(XCM_Handle pXCom, long lMsgId, short* pnValue, long lCount);
	long XCOMPRO_API_FUNCTION XCM_SetI4Item(XCM_Handle pXCom, long lMsgId, long* plValue, long lCount);
	long XCOMPRO_API_FUNCTION XCM_SetI8Item(XCM_Handle pXCom, long lMsgId, LONGLONG* plValue, long lCount);
	long XCOMPRO_API_FUNCTION XCM_SetU1Item(XCM_Handle pXCom, long lMsgId, BYTE* pnValue, long lCount);
	long XCOMPRO_API_FUNCTION XCM_SetU2Item(XCM_Handle pXCom, long lMsgId, USHORT* plValue, long lCount);
	long XCOMPRO_API_FUNCTION XCM_SetU4Item(XCM_Handle pXCom, long lMsgId, ULONG* pnValue, long lCount);
	long XCOMPRO_API_FUNCTION XCM_SetU8Item(XCM_Handle pXCom, long lMsgId, ULONGLONG* plValue, long lCount);
	long XCOMPRO_API_FUNCTION XCM_SetF4Item(XCM_Handle pXCom, long lMsgId, FLOAT* prValue, long lCount);
	long XCOMPRO_API_FUNCTION XCM_SetF8Item(XCM_Handle pXCom, long lMsgId, double* prValue, long lCount);
	long XCOMPRO_API_FUNCTION XCM_EnableLog(XCM_Handle pXCom, long nLogType, short nEnabled);
	long XCOMPRO_API_FUNCTION XCM_GetHeaderBytes(XCM_Handle pXCom, long lMsgId, BYTE* pnHeader, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetMsgBytes(XCM_Handle pXCom, long lMsgId, BYTE* pnMsg, long lSize);
	long XCOMPRO_API_FUNCTION XCM_SetHeaderBytes(XCM_Handle pXCom, long lMsgId, BYTE* pnHeader, long lSize);
	long XCOMPRO_API_FUNCTION XCM_SetMsgBytes(XCM_Handle pXCom, long lMsgId, BYTE* pnMsg, long lSize);
	long XCOMPRO_API_FUNCTION XCM_GetAlarmMsgInfo(XCM_Handle pXCom, long lMsgId, short* pnDevId, short* pnStrm, short* pnFunc, long* plSysByte, short* pnWbit);
	long XCOMPRO_API_FUNCTION XCM_DebugInfo(XCM_Handle pXCom, short* pnInfo);
	long XCOMPRO_API_FUNCTION XCM_GetSysBytes(XCM_Handle pXCom, long lMsgId);
	long XCOMPRO_API_FUNCTION XCM_SetWBit(XCM_Handle pXCom, long lMsgId, short nWBit);
	long XCOMPRO_API_FUNCTION XCM_GetInvalidMsgInfo(XCM_Handle pXCom, long lMsgId, short* pnDevId, short* pnStrm, short* pnFunc, long* plSysByte, short* pnWbit);
	long XCOMPRO_API_FUNCTION XCM_MakeSpoolStream(XCM_Handle pXCom, long lMsgId);
	const char XCOMPRO_API_FUNCTION *XCM_GetParam(XCM_Handle pXCom, const char *pszParamName);
	long XCOMPRO_API_FUNCTION XCM_SetParam(XCM_Handle pXCom, const char* psParamName, const char* pszValue);
	long XCOMPRO_API_FUNCTION XCM_GetCurrentItemType(XCM_Handle pXCom, long lMsgId);
	long XCOMPRO_API_FUNCTION XCM_GetCurrentItemCount(XCM_Handle pXCom, long lMsgId);
	long XCOMPRO_API_FUNCTION XCM_GetSecsLog(XCM_Handle pXCom, long lMsgId, char* pszValue, long lSize);
	long XCOMPRO_API_FUNCTION XCM_PopEvent(XCM_Handle pXCom, long *pIEventType, short* nEventID, long* lParam);
	long XCOMPRO_API_FUNCTION XCM_SetSecsEventHandler(XCM_Handle pXCom, void *lpParam, CALLBACK_SECS_EVENT pfn);
	long XCOMPRO_API_FUNCTION XCM_SetSecsMsgEventHandler(XCM_Handle pXCom, void *lpParam, CALLBACK_SECS_MSG pfn);
	long XCOMPRO_API_FUNCTION XCM_SetStreamMsg(XCM_Handle pXCom, long lMsgId, BYTE *pcData, long nSize);
	long XCOMPRO_API_FUNCTION XCM_GetStreamMsgSize(XCM_Handle pXCom, long lMsgId);
	long XCOMPRO_API_FUNCTION XCM_GetStreamMsg(XCM_Handle pXCom, long lMsgId, BYTE *pnData, long *plCount, long lSize);
	long XCOMPRO_API_FUNCTION XCM_MoveSecsItem(XCM_Handle pXCom, long lMsgId, long nIndex);
	long XCOMPRO_API_FUNCTION XCM_GetMsgSize(XCM_Handle pXCom, long lMsgId);
	long XCOMPRO_API_FUNCTION XCM_SetEventHandlerMode(XCM_Handle pXCom, short nParam);
}

class XComPro
{
private:
	XCM_Handle pXCom;
public:
	/** ***********************************************************************************
		@brief       Constructor
		@retval      None
		@param       None
		@date        2016/05/16
	*************************************************************************************** */
	XComPro()
	{
		pXCom = XCM_CreateObject();
	}
	/** ***********************************************************************************
		@brief       Destructor
		@retval      None
		@param       None
		@date        2016/05/16
	*************************************************************************************** */
	~XComPro()
	{
		XCM_DeleteObject(pXCom);
	}

	
	/*========================================================================================
		PROPERTY : getDeviceID()
		DESCRIPT : ���� �ε�� �޽����� DeviceID ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	short getDeviceID()
	{
		return XCM_getDeviceID(pXCom);
	}
	/*========================================================================================
		PROPERTY : getStream()
		DESCRIPT : ���� �ε�� �޽����� Stream ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	short getStream()
	{
		return XCM_getStream(pXCom);
	}
	/*========================================================================================
		PROPERTY : getFunction()
		DESCRIPT : ���� �ε�� �޽����� Function ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	short getFunction()
	{
		return XCM_getFunction(pXCom);
	}
	/*========================================================================================
		PROPERTY : getSystemBytes()
		DESCRIPT : ���� �ε�� �޽����� SystemBytes ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long getSystemBytes()
	{
		return XCM_getSystemBytes(pXCom);
	}
	/*========================================================================================
		PROPERTY : getWbit()
		DESCRIPT : ���� �ε�� �޽����� Wbit ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	short getWbit()
	{
		return XCM_getWbit(pXCom);
	}
	/*========================================================================================
		PROPERTY : getRbit()
		DESCRIPT : ���� �ε�� �޽����� Rbit ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	short getRbit()
	{
		return XCM_getRbit(pXCom);
	}
	/*========================================================================================
		PROPERTY : getEbit()
		DESCRIPT : ���� �ε�� �޽����� Ebit ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	short getEbit()
	{
		return XCM_getEbit(pXCom);
	}
	/*========================================================================================
		PROPERTY : XCM_getPtype()
		DESCRIPT : ���� �ε�� �޽����� Ptype ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	short getPtype()
	{
		return XCM_getPtype(pXCom);
	}
	/*========================================================================================
		PROPERTY : XCM_getStype()
		DESCRIPT : ���� �ε�� �޽����� Stype ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	short getStype()
	{
		return XCM_getStype(pXCom);
	}
	/*========================================================================================
		PROPERTY : getBlock()
		DESCRIPT : ���� �ε�� �޽����� Block ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	short getBlock()
	{
		return XCM_getBlock(pXCom);
	}
	/*========================================================================================
		PROPERTY : getDeviceID()
		DESCRIPT : ���� �ε�� �޽����� HeaderSize ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long getHeaderSize()
	{
		return XCM_getHeaderSize(pXCom);
	}
	/*========================================================================================
		PROPERTY : getMessageSize()
		DESCRIPT : ���� �ε�� �޽����� MsgSize ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long getMessageSize()
	{
		return XCM_getMessageSize(pXCom);
	}
	/*========================================================================================
		FUNCTION : SetSecsEventHandler()
		DESCRIPT : SecsEvent �Լ� ������ �Ҵ�
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetSecsEventHandler(void *lpParam, CALLBACK_SECS_EVENT pfn)
	{
		return XCM_SetSecsEventHandler(pXCom, lpParam, pfn);
	}
	/*========================================================================================
		FUNCTION : SetSecsMsgEventHandler()
		DESCRIPT : SecsMsg �Լ� ������ �Ҵ�
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetSecsMsgEventHandler(void *lpParam, CALLBACK_SECS_MSG pfn)
	{
		return XCM_SetSecsMsgEventHandler(pXCom, lpParam, pfn);
	}
	/*========================================================================================
		FUNCTION : Initialize()
		DESCRIPT : �ʱ� ���� �ε� �� ��ü �ʱ�ȭ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long Initialize(const char *pszFile)
	{
		return XCM_Initialize(pXCom, pszFile);
	}
	/*========================================================================================
		FUNCTION : Start()
		DESCRIPT : ��� ���� ���� �� ��ü ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long Start()
	{
		return XCM_Start(pXCom);
	}
	/*========================================================================================
		FUNCTION : Stop()
		DESCRIPT : ��� ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long Stop()
	{
		return XCM_Stop(pXCom);
	}
	/*========================================================================================
		FUNCTION : Close()
		DESCRIPT : ��� ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long Close()
	{
		return XCM_Close(pXCom);
	}
	/*========================================================================================
		FUNCTION : MakeSecsMsg()
		DESCRIPT : SECS Message ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/

	long MakeSecsMsg(long *plMsgId, short nDevId, short nStrm, short nFunc, long lSysByte)
	{
		return XCM_MakeSecsMsg(pXCom, plMsgId, nDevId, nStrm, nFunc, lSysByte);
	}
	/*========================================================================================
		FUNCTION : Send()
		DESCRIPT : SECS Message ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long Send(long lMsgId)
	{
		return XCM_Send(pXCom, lMsgId);
	}
	/*========================================================================================
		FUNCTION : LoadSecsMsg()
		DESCRIPT : ���ŵ� SECS message�� ���� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long LoadSecsMsg(long *plMsgId, short *pnDevId, short *pnStrm, short *pnFunc, long *plSysByte, short *pnWbit)
	{
		return XCM_LoadSecsMsg(pXCom, plMsgId, pnDevId, pnStrm, pnFunc, plSysByte, pnWbit);
	}
	/*========================================================================================
		FUNCTION : CloseSecsMsg()
		DESCRIPT : ���ŵ� SECS message�� ���� ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	void CloseSecsMsg(long lMsgId)
	{
		XCM_CloseSecsMsg(pXCom, lMsgId);
	}
	/*========================================================================================
		FUNCTION : GetListItem()
		DESCRIPT : ���ŵ� SECS message���� LIST format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetListItem(long lMsgId, long *pnItems)
	{
		return XCM_GetListItem(pXCom, lMsgId, pnItems);
	}
	/*========================================================================================
		FUNCTION : GetBinaryItem()
		DESCRIPT : ���ŵ� SECS message���� Binary format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/

	long GetBinaryItem(long lMsgId, BYTE *pnValue, long *plCount, long lSize)
	{
		return XCM_GetBinaryItem(pXCom, lMsgId, pnValue, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : GetBoolItem()
		DESCRIPT : ���ŵ� SECS message���� Boolean format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetBoolItem(long lMsgId, BYTE *pnValue, long *plCount, long lSize)
	{
		return XCM_GetBoolItem(pXCom, lMsgId, pnValue, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : GetAsciiItem()
		DESCRIPT : ���ŵ� SECS message���� Ascii format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/

	long GetAsciiItem(long lMsgId, char *pszValue, long *plCount, long lSize)
	{
		return XCM_GetAsciiItem(pXCom, lMsgId, pszValue, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : GetJis8Item()
		DESCRIPT : ���ŵ� SECS message���� Jis8 format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetJis8Item(long lMsgId, char *pszValue, long *plCount, long lSize)
	{
		return XCM_GetJis8Item(pXCom, lMsgId, pszValue, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : GetI1Item()
		DESCRIPT : ���ŵ� SECS message���� INT1 format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetI1Item(long lMsgId, char* pnValue, long* plCount, long lSize)
	{
		return XCM_GetI1Item(pXCom, lMsgId, pnValue, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : GetI2Item()
		DESCRIPT : ���ŵ� SECS message���� INT2 format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetI2Item(long lMsgId, short* pnValue, long* plCount, long lSize)
	{
		return XCM_GetI2Item(pXCom, lMsgId, pnValue, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : GetI4Item()
		DESCRIPT : ���ŵ� SECS message���� INT4 format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetI4Item(long lMsgId, long* plValue, long* plCount, long lSize)
	{
		return XCM_GetI4Item(pXCom, lMsgId, plValue, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : GetI8Item()
		DESCRIPT : ���ŵ� SECS message���� INT8 format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetI8Item(long lMsgId, LONGLONG* plValue, long* plCount, long lSize)
	{
		return XCM_GetI8Item(pXCom, lMsgId, plValue, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : GetU1Item()
		DESCRIPT : ���ŵ� SECS message���� UINT1 format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetU1Item(long lMsgId, BYTE* pnValue, long* plCount, long lSize) 
	{
		return XCM_GetU1Item(pXCom, lMsgId, pnValue, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : GetU2Item()
		DESCRIPT : ���ŵ� SECS message���� UINT2 format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetU2Item(long lMsgId, USHORT* plValue, long* plCount, long lSize) 
	{
		return XCM_GetU2Item(pXCom, lMsgId, plValue, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : GetU4Item()
		DESCRIPT : ���ŵ� SECS message���� UINT4 format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/

	long GetU4Item(long lMsgId, ULONG* plValue, long* plCount, long lSize) 
	{
		return XCM_GetU4Item(pXCom, lMsgId, plValue, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : GetU8Item()
		DESCRIPT : ���ŵ� SECS message���� UINT8 format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetU8Item(long lMsgId, ULONGLONG* plValue, long* plCount, long lSize) 
	{
		return XCM_GetU8Item(pXCom, lMsgId, plValue, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : GetF4Item()
		DESCRIPT : ���ŵ� SECS message���� Float4 format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetF4Item(long lMsgId, FLOAT* prValue, long* plCount, long lSize) 
	{
		return XCM_GetF4Item(pXCom, lMsgId, prValue, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : GetF8Item()
		DESCRIPT : ���ŵ� SECS message���� Float8 format item �� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetF8Item(long lMsgId, double* prValue, long* plCount, long lSize) 
	{
		return XCM_GetF8Item(pXCom, lMsgId, prValue, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : SetListItem()
		DESCRIPT : SECS Message�� LIST format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetListItem(long lMsgId, long nItems) 
	{
		return XCM_SetListItem(pXCom, lMsgId, nItems);
	}
	/*========================================================================================
		FUNCTION : SetBinaryItem()
		DESCRIPT : SECS Message�� Binary format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetBinaryItem(long lMsgId, BYTE* pnValue, long lCount) 
	{
		return XCM_SetBinaryItem(pXCom, lMsgId, pnValue, lCount);
	}
	/*========================================================================================
		FUNCTION : SetBoolItem()
		DESCRIPT : SECS Message�� Boolean format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetBoolItem(long lMsgId, BYTE* pnValue, long lCount) 
	{
		return XCM_SetBoolItem(pXCom, lMsgId, pnValue, lCount);
	}
	/*========================================================================================
		FUNCTION : SetAsciiItem()
		DESCRIPT : SECS Message�� Ascii format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetAsciiItem(long lMsgId, const char *pszValue, long lCount) 
	{
		return XCM_SetAsciiItem(pXCom, lMsgId, pszValue, lCount);
	}
	/*========================================================================================
		FUNCTION : SetJis8Item()
		DESCRIPT : SECS Message�� Jis8 format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetJis8Item(long lMsgId, const char *pszValue, long lCount) 
	{
		return XCM_SetJis8Item(pXCom, lMsgId, pszValue, lCount);
	}
	/*========================================================================================
		FUNCTION : SetI1Item()
		DESCRIPT : SECS Message�� INT1 format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetI1Item(long lMsgId, char* pnValue, long lCount) 
	{
		return XCM_SetI1Item(pXCom, lMsgId, pnValue, lCount);
	}
	/*========================================================================================
		FUNCTION : SetI2Item()
		DESCRIPT : SECS Message�� INT2 format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetI2Item(long lMsgId, short* pnValue, long lCount) 
	{
		return XCM_SetI2Item(pXCom, lMsgId, pnValue, lCount);
	}
	/*========================================================================================
		FUNCTION : SetI4Item()
		DESCRIPT : SECS Message�� INT4 format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetI4Item(long lMsgId, long* plValue, long lCount) 
	{
		return XCM_SetI4Item(pXCom, lMsgId, plValue, lCount);
	}
	/*========================================================================================
		FUNCTION : SetI8Item()
		DESCRIPT : SECS Message�� INT8 format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetI8Item(long lMsgId, LONGLONG* plValue, long lCount) 
	{
		return XCM_SetI8Item(pXCom, lMsgId, plValue, lCount);
	}
	/*========================================================================================
		FUNCTION : SetU1Item()
		DESCRIPT : SECS Message�� UINT1 format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetU1Item(long lMsgId, BYTE* pnValue, long lCount) 
	{
		return XCM_SetU1Item(pXCom, lMsgId, pnValue, lCount);
	}
	/*========================================================================================
		FUNCTION : SetU2Item()
		DESCRIPT : SECS Message�� UINT2 format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetU2Item(long lMsgId, USHORT* plValue, long lCount) 
	{
		return XCM_SetU2Item(pXCom, lMsgId, plValue, lCount);
	}
	/*========================================================================================
		FUNCTION : SetU4Item()
		DESCRIPT : SECS Message�� UINT4 format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetU4Item(long lMsgId, ULONG* pnValue, long lCount) 
	{
		return XCM_SetU4Item(pXCom, lMsgId, pnValue, lCount);
	}
	/*========================================================================================
		FUNCTION : SetU8Item()
		DESCRIPT : SECS Message�� UINT8 format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetU8Item(long lMsgId, ULONGLONG* plValue, long lCount) 
	{
		return XCM_SetU8Item(pXCom, lMsgId, plValue, lCount);
	}
	/*========================================================================================
		FUNCTION : SetF4Item()
		DESCRIPT : SECS Message�� Float4 format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetF4Item(long lMsgId, FLOAT* prValue, long lCount) 
	{
		return XCM_SetF4Item(pXCom, lMsgId, prValue, lCount);
	}
	/*========================================================================================
		FUNCTION : SetF8Item()
		DESCRIPT : SECS Message�� Float8 format�� item ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetF8Item(long lMsgId, double* prValue, long lCount) 
	{
		return XCM_SetF8Item(pXCom, lMsgId, prValue, lCount);
	}
	/*========================================================================================
		FUNCTION : EnableLog()
		DESCRIPT : �α� ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long EnableLog(long nLogType, short nEnabled) 
	{
		return XCM_EnableLog(pXCom, nLogType, nEnabled);
	}
	/*========================================================================================
		FUNCTION : GetHeaderBytes()
		DESCRIPT : SECS Message�� Header ���� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetHeaderBytes(long lMsgId, BYTE* pnHeader, long lSize) 
	{
		return XCM_GetHeaderBytes(pXCom, lMsgId, pnHeader, lSize);
	}
	/*========================================================================================
		FUNCTION : GetMsgBytes()
		DESCRIPT : SECS Message�� SECS-II message ���� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetMsgBytes(long lMsgId, BYTE* pnMsg, long lSize) 
	{
		return XCM_GetMsgBytes(pXCom, lMsgId, pnMsg, lSize);
	}
	/*========================================================================================
		FUNCTION : SetHeaderBytes()
		DESCRIPT : SECS Message�� Header ���� ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetHeaderBytes(long lMsgId, BYTE* pnHeader, long lSize) 
	{
		return XCM_SetHeaderBytes(pXCom, lMsgId, pnHeader, lSize);
	}
	/*========================================================================================
		FUNCTION : SetMsgBytes()
		DESCRIPT : SECS Message�� SECS-II message ���� ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetMsgBytes(long lMsgId, BYTE* pnMsg, long lSize) 
	{
		return XCM_SetMsgBytes(pXCom, lMsgId, pnMsg, lSize);
	}
	/*========================================================================================
		FUNCTION : GetAlarmMsgInfo()
		DESCRIPT : SECS Alarm ���� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetAlarmMsgInfo(long lMsgId, short* pnDevId, short* pnStrm, short* pnFunc, long* plSysByte, short* pnWbit) 
	{
		return XCM_GetAlarmMsgInfo(pXCom, lMsgId, pnDevId, pnStrm, pnFunc, plSysByte, pnWbit);
	}
	/*========================================================================================
		FUNCTION : DebugInfo()
		DESCRIPT : 
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long DebugInfo(short* pnInfo) 
	{
		return XCM_DebugInfo(pXCom, pnInfo);
	}
	/*========================================================================================
		FUNCTION : GetSysBytes()
		DESCRIPT : SECS Message�� system bytes ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetSysBytes(long lMsgId) 
	{
		return XCM_GetSysBytes(pXCom, lMsgId);
	}
	/*========================================================================================
		FUNCTION : SetWBit()
		DESCRIPT : SECS Message�� WBit ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetWBit(long lMsgId, short nWBit) 
	{
		return XCM_SetWBit(pXCom, lMsgId, nWBit);
	}
	/*========================================================================================
		FUNCTION : GetInvalidMsgInfo()
		DESCRIPT : Invalid Message ���� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetInvalidMsgInfo(long lMsgId, short* pnDevId, short* pnStrm, short* pnFunc, long* plSysByte, short* pnWbit) 
	{
		return XCM_GetInvalidMsgInfo(pXCom, lMsgId, pnDevId, pnStrm, pnFunc, plSysByte, pnWbit);
	}
	/*========================================================================================
		FUNCTION : MakeSpoolStream()
		DESCRIPT : SECS ����Ʈ Stream ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long MakeSpoolStream(long lMsgId) 
	{
		return XCM_MakeSpoolStream(pXCom, lMsgId);
	}
	/*========================================================================================
		FUNCTION : GetParam()
		DESCRIPT : ���� ���� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	const char* GetParam(const char *pszParamName) 
	{
		return XCM_GetParam(pXCom, pszParamName);
	}
	/*========================================================================================
		FUNCTION : SetParam()
		DESCRIPT : ���� ���� ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetParam(const char* psParamName, const char* pszValue) 
	{
		return XCM_SetParam(pXCom, psParamName, pszValue);
	}
	/*========================================================================================
		FUNCTION : GetCurrentItemType()
		DESCRIPT : ���ŵ� SECS Message�� ���� item type ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetCurrentItemType(long lMsgId) 
	{
		return XCM_GetCurrentItemType(pXCom, lMsgId);
	}
	/*========================================================================================
		FUNCTION : GetCurrentItemCount()
		DESCRIPT : ���ŵ� SECS Message�� ���� item count ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetCurrentItemCount(long lMsgId) 
	{
		return XCM_GetCurrentItemCount(pXCom, lMsgId);
	}
	/*========================================================================================
		FUNCTION : GetSecsLog()
		DESCRIPT : SECS Message�� SECS-II �α� ��ȸ
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetSecsLog(long lMsgId, char *pszBuff, long lSize) 
	{
		return XCM_GetSecsLog(pXCom, lMsgId, pszBuff, lSize);
	}
	/*========================================================================================
		FUNCTION : PopEvent()
		DESCRIPT : SECS Event ���� ��ȸ(POLLING ���)
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long PopEvent(long *pIEventType, short* nEventID, long* lParam)
	{
		return XCM_PopEvent(pXCom, pIEventType, nEventID, lParam);
	}
	/*========================================================================================
		FUNCTION : SetStreamMsg()
		DESCRIPT : Binary�� SECS Message ����
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetStreamMsg(long lMsgId, BYTE *pcData, long nSize) 
	{
		return XCM_SetStreamMsg(pXCom, lMsgId, pcData, nSize);
	}
	/*========================================================================================
		FUNCTION : GetStreamMsgSize()
		DESCRIPT : Length�� �� �� �ִ� �������̽� �� ���� �ʿ�
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetStreamMsgSize(long lMsgId) 
	{
		return XCM_GetStreamMsgSize(pXCom, lMsgId);
	}
	/*========================================================================================
		FUNCTION : GetStreamMsg()
		DESCRIPT : XSecs format stream�� ������ �Լ�
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetStreamMsg(long lMsgId, BYTE *pnData, long *plCount, long lSize) 
	{
		return XCM_GetStreamMsg(pXCom, lMsgId, pnData, plCount, lSize);
	}
	/*========================================================================================
		FUNCTION : MoveSecsItem()
		DESCRIPT : 
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long MoveSecsItem(long lMsgId, long nIndex) 
	{
		return XCM_MoveSecsItem(pXCom, lMsgId, nIndex);
	}
	/*========================================================================================
		FUNCTION : GetMsgSize()
		DESCRIPT : 
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long GetMsgSize(long lMsgId) 
	{
		return XCM_GetMsgSize(pXCom, lMsgId);
	}
	/*========================================================================================
		FUNCTION : SetEventHandlerMode()
		DESCRIPT : ������ ���� ����� ���� �� ���� �� Event������� ����.(0:Polling 1:Event)
		RETURN	 : None
		ARGUMENT : None
		UPDATE	 : 2016/05/16
	========================================================================================*/
	long SetEventHandlerMode(short nParam) 
	{
		return XCM_SetEventHandlerMode(pXCom, nParam);
	}

};
