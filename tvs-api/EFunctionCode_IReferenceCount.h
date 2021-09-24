
class IReferenceCount_FC
{
public:
	enum EFunctionCode_IReferenceCount
	{
		FC_INCREASECOUNT = 0 ,
		FC_DECREASECOUNT,
		FC_CLEARREFERENCECOUNT,
		FC_ADDREFERENCECOUNT,
		FC_RELEASEREFERENCECOUNT,
		FC_ADDREFERENCECOUNTREADY,
		FC_RELEASEREFERENCECOUNTREADY,
		FC_GETREFERENCECOUNT,
		FC_GETREFERENCECOUNTREADY,
		FC_GETREFERENCECOUNTHELP,
		FC_ADDREFERENCECOUNTREADY_2 = 0x10,			//it was hardcode in app
		FC_RELEASEREFERENCECOUNTREADY_2 = 0x11,		//it was hardcode in app
	};
};

