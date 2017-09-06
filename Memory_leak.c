
/*********************Purpose of the code  **************************************************

The Following code is written to test whether the Static Analysis Tools will catch the .
following error types or not?

	1)Memory Leak
	
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

void Memory_leak()
{
	char *memoryArea = "memoryarea";
	char *newArea = "itsnewarea" ;

	memoryArea =  malloc(10*sizeof(char));
	newArea    =  malloc(10*sizeof(char));
	
	memoryArea = newArea; /*assigned the memoryArea pointer to the newArea pointer. As a result, the memory 
							location to which memoryArea was pointing to earlier becomes an orphan, It cannot
							be freed, as there is no reference to this location.This will result in a memory 
							leak of 10 bytes*/

}




