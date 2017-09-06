/********************Purpose of the code  **************************************************

The Following code is written to test whether the Static Analysis Tools will catch the 
following error types or not?

	1)	Data variable never used
	

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

int Variable_unused( int var_1)
{
int var_2=7, var_3=4, result=0;
result = (2*var_1)+(5*var_2)/4;  //variable i.e. var_3 is never used in any where in the program.
return result;
}



