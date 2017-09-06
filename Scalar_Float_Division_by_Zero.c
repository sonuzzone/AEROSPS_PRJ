/*********************Purpose of the code  **************************************************

The Following code is written to test whether the Static Analysis Tools will catch the .
following error types or not?

	1)	Scalar and Float Division by zero
	

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

/*Scalar or Float Division by Zero: ZDV
This is a check to establish whether the right operand of a division (that is, the denominator) is different
from 0[.0]. Consider the following example.*/

#include<stdio.h>

void zdvs(int p)
 {
 	int i = 0, j = 1;
 	i = 1024 / (j-p); // ZDV ERROR: Scalar Division by Zero
 }

void zdvf(float p)
 {
 	float i = 0.0, j = 1.0;
 	i = 1024.0 / (j-p); // ZDV ERROR: float Division by Zero
 }

 
void Divide_by_zero(void)
 {
 	
		zdvs(1); // NTC ERROR: because of ZDV ERROR  ZDVS.

		zdvf(1.0); // NTC ERROR: because of ZDV ERROR in ZDVF.
 }
