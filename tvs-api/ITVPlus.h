#ifndef _ITVPlus_
#define _ITVPlus_

#include "MarshallingMarks.h"

class ITVPlus
{
protected:
	
	virtual ~ITVPlus(void) {};

public:

	virtual int SendTVPlusTuneSuccess( _IN_ int success_reason) = 0;
	virtual int SendTVPlusTuneFail( _IN_ int fail_reason) = 0;
	virtual int SendTVPlusTuneStart(_IN_ int start_reason)  = 0;

};


#endif //_ITVPlus_

