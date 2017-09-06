/*********************Purpose of the code  **************************************************

The Following code is written to test whether the Static Analysis Tools will catch the .
following error types or not?

	1)	Passed value never used 
	

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

int  passed_value_never_used (int , int);
 
void passed_value_never_used_main ()

{

	int passed_var1 = 5;
	int passed_var2 = 6;
	
	passed_value_never_used(passed_var1, passed_var2); /*calling the passed_value_never_used error type function*/

}

/*This function is written to depict the passed value never been used  in the called function which is an non value 
added activity*/


int passed_value_never_used(int value1, int value2)
{
	int result = 0;
	result = (value1 * 2) + 15;
	return result;
}