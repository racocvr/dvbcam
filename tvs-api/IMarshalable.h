/** 
 * @file IMarshalable.h
 * @brief Interface inherited by classes that can be marshalled
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _IMARSHALABLE_H_
#define _IMARSHALABLE_H_

#ifdef _WIN32
#pragma once
#endif

class TCTreeBranch;

class TIMarshalable
{
public:
	TIMarshalable(){};
	virtual ~TIMarshalable(){};

	/**
	 * @brief Gets size of marshalled object.
	 * @param [out] size Size of marshalled object.
	 * @return Returns true if size of marshalled object is available, otherwise returns false.
	 */
	virtual bool GetSizeOfMarshalled(unsigned long& size) = 0;

	/**
	 * @brief Extract tree from class.
	 * @param [inout] tree Branch to which object data should be added.
	 * @return Returns true if extraction was successful, otherwise returns false.
	 */
	virtual bool ClassToTree(TCTreeBranch& tree) = 0;
	
	/**
	 * @brief Fill out class from tree.
	 * @param [inout] tree Branch from which object data should be fetched.
	 * @return Returns true if conversion was successful, otherwise returns false.
	 */
	virtual bool TreeToClass(TCTreeBranch& tree) = 0;

};

#endif // IMARSHALABLE_H_