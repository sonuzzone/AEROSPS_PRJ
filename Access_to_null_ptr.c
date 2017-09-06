/********************Purpose of the code  **************************************************

The Following code is written to test whether the Static Analysis Tools will catch the 
following error types or not?

	1)	Access to Null Pointer
	
end of error types list.

********************************************************************************************

Author : Sanjeev Kulkarni
---------------------------------
  
start of Modification History

-------     ----------------------      ----------------------------------------------------
Sl No		Date of modification		change history
-------     -----------------------     ----------------------------------------------------
1)			27 May 09					Initial version

****************************end of modification History ************************************/

#include<stdio.h>

void access_to_null_ptr()
{
	int *ptr = NULL;
	int var = 0;
	var = *ptr;  //access to null pointer
	printf("%d",var);
}
