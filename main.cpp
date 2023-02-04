// BRc4Encrypt.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "BRc4Encrypt.h"

int main()
{
	BRc4Encrypt encrypt;
	DWORD dwLength = 0;
	LPCSTR lpcKey = "ER4PH43DL0UVP2DB";
	LPCSTR lpcData = "abcdefghijklmnopqrstuvwxyz0123456789";

	dwLength = strlen(lpcData);
	PBYTE pbData = (PBYTE)VirtualAlloc(0, 0x100, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	memmove(pbData, lpcData, dwLength);

	encrypt.EncryptData((PBYTE)lpcKey, pbData, &dwLength);
	encrypt.DecryptData((PBYTE)lpcKey, pbData, dwLength);
	VirtualFree(pbData, 0x100, MEM_RELEASE);
	return 0;
}
