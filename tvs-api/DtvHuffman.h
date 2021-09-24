#ifndef _DTVHUFFMAN_H_
#define _DTVHUFFMAN_H_

#include <string>

struct HuffmanTree
{
	std::string string;
	std::string code;
	HuffmanTree(){}
	HuffmanTree(std::string paramStr,std::string paramCode):string(paramStr),code(paramCode){}
};


class TCDtvHuffman
{
public:
	/* Multiple String Structure */
	typedef enum {
		cm_None					= 0x00,
		cm_Huffman_C4C5			= 0x01,
		cm_Huffman_C6C7			= 0x02,
		// compression_type 0x00~0xFF is for ATSC. A65
		cm_Huffman_Freesat_1	= 0x100,
		cm_Huffman_Freesat_2	= 0x101,
		/* specified in Malaysia DTV Spec*/
		cm_Huffman_English		= 0x102,
		cm_Huffman_Bahasa_Melayu	= 0x103,		
	} compress_type_k;

	TCDtvHuffman();
	
	virtual ~TCDtvHuffman();

	bool DecompressString(const unsigned int type, const unsigned char* compressedStr, const unsigned char length, unsigned char* text, unsigned int* bufLen);
private:
	std::string m_ConvertToBinary(const unsigned char* hexadecimalText,const int HexadecimalTextLength);
	char m_ConvertBinaryToHex(std::string characterInBinary);
	bool m_DecodeHuffmanByTable (const unsigned char* compressedStr, const unsigned char length, unsigned char* text, unsigned int* bufLen,const unsigned char* DecodeTable);
	bool m_DecodeHuffmanByTree (const unsigned char *inputStr,const int inputStrLength,unsigned char* outputStr,unsigned int* outputLength,const HuffmanTree* HuffmanTable);

};

#endif
