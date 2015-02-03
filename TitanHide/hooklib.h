#ifndef _HOOKLIB_H_
#define _HOOKLIB_H_

#include "_global.h"

#pragma pack(push,1)
struct opcode
{
#ifdef _WIN64
	unsigned short int mov;
#else
	unsigned char mov;
#endif
	ULONG_PTR addr;
	unsigned char push;
	unsigned char ret;
};
#pragma pack(pop)

struct hookstruct
{
	ULONG_PTR addr;
	opcode hook;
	unsigned char orig[sizeof(opcode)];
	//SSDT extension
	int SSDToffset;
	ULONG SSDTold;
	ULONG SSDTnew;
	ULONG_PTR SSDTaddress;
};

typedef hookstruct* HOOK;

int init_hook();
VOID uninit_hook();
HOOK hook(PVOID api, void* newfunc);
bool unhook(HOOK hook, bool free = false);
bool hook(HOOK hook);

#endif //_HOOKLIB_H_
