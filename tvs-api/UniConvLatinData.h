#include "UniConvLatin.h"
#include "UniConvCommon.h"
#include "SOSpecDataType.h"

#define XXXXXX                0x2717 /* unicode for ballot x */

/* rows are base letters */
/* columns are accents of the base letter */
/* column 0 is the base letter without accent (use for searching merging applicant) */

/* Entries commented with another code (above) (the character above
   is the correct unicode value but the character has no support in
   fontfusion and are replaced with a similar character or the base character.
   If the entry is marked "rep" it is the same case as for above but the
   unicode value has not yet been looked for.
   */
// TODO : temporary removed because of crash
