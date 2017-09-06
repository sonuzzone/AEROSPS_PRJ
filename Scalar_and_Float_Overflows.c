/*********************Purpose of the code  **************************************************

The Following code is written to test whether the Static Analysis Tools will catch the .
following error types or not?

	1)	Scalar and Float overflow 
	

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


/*Scalar and Float Overflows: OVFL
These are checks to establish whether arithmetic expressions overflow. This is a scalar check with integer type 
and float check for floating point expression. Consider the following example.*/
#include<stdio.h>
#include <float.h>

 void Overflow(void)
 {
 	int i = 1;
	float fvalue = FLT_MAX;
	i = i << 30; // i = 2**30
 	i = 2 * (i - 1) + 2; // OVFL ERROR: 2**31 is an overflow value for int32
 	fvalue = 2 * fvalue + 1.0; // OVFL ERROR: float variable is overflow
 }

/*On a 32 bit architecture platform, the maximum integer value is 2**31-1, thus 2**31will raise an overflow. 
In the same manner, if fvaluerepresents the biggest float its double cannot be represented with same type and 
raises an overflow.*/
