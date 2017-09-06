/*********************Purpose of the code  **************************************************
The Following code is written to test whether the Static Analysis Tools will catch the .
following error types or not?

	1)	Dangerous type conversion
	

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


/*This function is written to depict the type_conversion that can lead to a major problem the 
return_value1 is of type float but after the calculation the value is converted to integer as 
the function returns a integer value.*/

#include<stdio.h>

int Type_conversion(int return_value)
{
	float return_value1=5.35;
	return_value1 = return_value * 2 + return_value1; 
	return return_value1; /* return_value1 is float but function returns only integer so type conversion takes place  
							 which leads to unexpected results */
}


