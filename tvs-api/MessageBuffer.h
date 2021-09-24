/** 
 * @file MessageBuffer.h
 * @brief Data buffer used to send data between middleware and applications
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */
	  
#ifdef _WIN32
#pragma once
#endif

#ifndef _MESSAGEBUFFER_H
#define _MESSAGEBUFFER_H

#include <vector>
#include <string>

class TCMessageBuffer
{
public:
	TCMessageBuffer();
	~TCMessageBuffer();

	/**
	 * @brief Adds one char at the end data buffer
	 * @param [in] data char that should be added
	 * @return true if success
	 */
	bool PushChar( char data );
	
	/**
	 * @brief Adds one short at the end data buffer
	 * @param [in] data short that should be added
	 * @return true if success
	 */
	bool PushShort( short data );
	
	/**
	 * @brief Adds one int at the end data buffer
	 * @param [in] data int that should be added
	 * @return true if success
	 */
	bool PushInt( int data );

	/**
	 * @brief Adds void data at the end data buffer
	 * @param [in] sizeOfData length of pData
	 * @param [in] pData data that should be added
	 * @return true if success
	 */
	bool PushConcatenated( unsigned long sizeOfData, const void* pData );
	
	/**
	 * @brief Reads one char from the start of data buffer (on the initial (full) buffer)
	 * @param [in] offset from which char should be read
	 * @return one char
	 */
	char ReadChar( unsigned int offset );

	/**
	 * @brief Reads one short from selected place  (on the initial (full) buffer)
	 * @param [in] offset from which int should be read
	 * @return one int
	 */
	void ReadShort( short* pTarget, unsigned int offset );

	/**
	 * @brief Reads one int from selected place  (on the initial (full) buffer)
	 * @param [in] offset from which int should be read
	 * @return one int
	 */
	void ReadInt( int* pTarget, unsigned int offset );

	/**
	 * @brief Write one int from selected place (on the initial (full) buffer)
	 * @param [in] offset from which int should be written
	 * @return one int
	 */
	bool WriteInt( int data, int offset = 0 );

	/**
	 * @brief Reads set number of bytes from selected place (on the initial (full) buffer)
	 * @param [in] offset from which data should be read
	 * @param [in] number of bytes to be read
	 * @return data with selected length
	 */
	void ReadConcatenated( unsigned long sizeOfData, void* pData, unsigned int offset );
	
	/**
	 * @brief Writes set number of bytes from selected place (on the initial (full) buffer)
	 * @param [in] offset from which data should be written
	 * @param [in] number of bytes to be written
	 * @param [in] data to be written
	 * @return data with selected length
	 */
	bool WriteConcatenated( unsigned long sizeOfData, void* pData, int offset = -1);
	
	bool PushBuffer(TCMessageBuffer* pBuffer);

	/**
	 * @brief Returns data buffer as a c-string
	 * @param [in] offset
	 * @return data as const char*
	 */
	const char* GetAsCStr( unsigned int offset = 0 ) const;
	
	/**
	 * @brief Returns void pointer to data with given offset
	 * @param [in] offset
	 * @return data as const char*
	 */
	const void* GetAsVoidFromOffset( unsigned int offset = 0 ) const;

	/**
	 * @brief Copies data to target 
	 * @param [out] target where data should be copied
	 * @param [in] length of copied data
	 * @param [in] offset from which data should be copied
	 */
	void CopyData(void* target, unsigned int length, unsigned int offset);
	 
	/**
	 * @brief Returns data buffer size
	 * @return buffer size
	 */
	unsigned long GetFullBufferSize() const { return (unsigned long) m_bufferData.size(); }

	/**
	 * @brief Returns data buffer size minus shift
	 * @return buffer size
	 */
	unsigned long GetBufferSize() const { return (unsigned long) (m_bufferData.size() - m_bufferShift); }
	
	/**
	 * @brief Reserves given number of bytes capacity
	 * @param [in] sizeOfData capacity to be reserved
	 */
	void Reserve(unsigned int sizeOfData);
	
	/**
	 * @brief Resizes buffer by given number of bytes
	 * @param [in] sizeOfData capacity to be added
	 */
	void Resize(unsigned int sizeOfData);
	
	/**
	 * @brief Sets if data should be encrypted
	 * @param [in] secureValue [True / False]
	 */
	void SetSecure(bool secureValue){ m_secureValue = secureValue; }
	
	/**
	 * @brief Returns information if data should be encrypted
	 * @return secureValue [True/False]
	 */
	bool GetSecure(void){ return m_secureValue; }
	
	/**
	 * @brief Cleans vector
	 */
	void Clean(void);

	/**
	 * @brief Sets sender of a message.
	 * @param [in] pSender Message sender.
	 */
	void SetSender(const char* sender);

	/**
	 * @brief Returns sender of a message.
	 * @remarks Empty string means that message was not yet sent.
	 * @return Sender of a message.
	 */
	std::string GetSender(){ return m_sender; }
	
private:
	std::vector<char> m_bufferData;
	unsigned long m_bufferShift; // number of read elements from buffer
	bool m_secureValue;
	std::string m_sender; // message sender
};

#endif // _MESSAGEBUFFER_H
