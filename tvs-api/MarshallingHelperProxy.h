/** 
 * @file MarshallingHelperProxy.h
 * @brief DTool class for External API helping in marshalling process (Proxy side)
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

#ifndef _MARSHALLINGHELPERPROXY_H_
#define _MARSHALLINGHELPERPROXY_H_

#include "MarshallingHelper.h"
#include "MessageBuffer.h"

class TVServiceAPIConnection;


class TCMarshallingHelperProxy  : public TCMarshallingHelper
{
public:
	TCMarshallingHelperProxy();
	virtual ~TCMarshallingHelperProxy();

	/**
	 * @brief Handles proxy call
	 * @param [in] pIPCConnection Dbus connection to be used for method call.
	 * @param [in] interfaceName interface to be called
	 * @param [in] methodName method to be called
	 * @param [in] functionCode of called method
	 * @param [in] asyncCall if true method does not wait for response from native side.
	 * @return true if success
	 */
	bool Run(TVServiceAPIConnection* pIPCConnection, std::string& interfaceName,const std::string& methodName, short functionCode, bool asyncCall = false);

	/**
	 * @brief Converts given list of items, that should be send to native, into tree
	 * @param [in] treeParent result tree
	 * @return true if success
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);

	/**
	 * @brief Converts given tree, that is received from native, basing on list of items into objects
	 * @param [in] treeMine tree to be converted
	 * @return true if success
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);

	/**
	 * @brief Returns buffer to be send
	 * @return send buffer
	 */
	TCMessageBuffer* GetProxySendBuffer() { return &m_sendBuffer; };
	
	/**
	 * @brief Returns received buffer
	 * @return reply buffer
	 */
	TCMessageBuffer* GetProxyReplyBuffer() { return &m_replyBuffer; };

private:
	TCMessageBuffer m_sendBuffer;
	TCMessageBuffer m_replyBuffer;
};

#endif // _MARSHALLINGHELPERPROXY_H_

