/*********************Purpose of the code  **************************************************

The Following code is written to test whether the Static Analysis Tools will catch the .
following error types or not?

	1)	Scalar and Float underflow
	

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

/*Scalar and Float Underflows: UNFL
These are checks to establish whether arithmetic expressions underflow. A scalar check is used 
with integer type, and a float check for floating point expressions. Consider the following example.
 */
#include<stdio.h>
#include<float.h>

 void Underflow(void)
 {
 	int i = 1;
 	float fval = FLT_MAX;

 	i = -2 * (i << 30); // i = -2**31
 	i = i - 1; // UNFL ERROR: scalar variable is underflow
 	fval = -2 * fval; // UNFL ERROR: float variable is underflow
  
 }

/*The minimum integer value on a 32 bit architecture platform is represented by -2**31,
 thus adding (-1)will raise an underflow.*/