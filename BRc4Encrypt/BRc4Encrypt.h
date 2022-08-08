#pragma once
#include <stdio.h>
#include <windows.h>

class BRc4Encrypt
{
public:
	// InitXorKeyBox
	BRc4Encrypt();
public:
	// 加密函数
	void EncryptData();
	// 解密函数
	void DecryptData();
private:
	// 加密密钥
	unsigned char g_Key[176] = "2Q73HI7Q0OD5BRN7";
	// 要加密的数据
	unsigned char g_data[237] = "{\"cds\":{\"auth\":\"VJM2U57S0U9RA840\"},\"mtdt\":{\"h_name\":\"DESKTOP-DJ1MB67\",\"wver\":\"x64/10.0\",\"arch\":\"x64\",\"bld\":\"19081\",\"p_name\":\"QwA6AFwAVQBzAGUAcgBzAFwAagBvAGgAbgBcAEQAZQBzAGsAdABvAHAAXAByAG8AcgAuAGUAeABlAA==\",\"uid\":\"john\",\"pid\":\"6948\"}}\r\n";
	// 用于临时存储替换密钥
	unsigned char g_TempKey[4] = { 0 };
	// box替换下标
	int g_replaceIndex = 1;
private:
	void InitXorKeyBox();
	void replaceFourByteKey(unsigned char* fourByteKey);
	void MyXor(unsigned char* key, unsigned char* data);
	void replaceBoxData(unsigned char* data);
	void ByteOutOfOrder(unsigned char* data);
	void boxXorData(unsigned char* data);
	// Decrypt
	void DeByteOutOfOrder(unsigned char* data);
	void DereplaceBoxData(unsigned char* data);
	void DeboxXorData(unsigned char* data);
	// ror
	template<class T> T __ROL__(T value, int count)
	{
		const unsigned int nbits = sizeof(T) * 8;

		if (count > 0)
		{
			count %= nbits;
			T high = value >> (nbits - count);
			if (T(-1) < 0) // signed value
				high &= ~((T(-1) << count));
			value <<= count;
			value |= high;
		}
		else
		{
			count = -count % nbits;
			T low = value << (nbits - count);
			value >>= count;
			value |= low;
		}
		return value;
	}

	inline unsigned int __ROR4__(unsigned int value, int count) { return __ROL__((unsigned int)value, -count); }
};

