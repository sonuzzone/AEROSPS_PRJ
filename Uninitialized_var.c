/*********************Purpose of the code  **************************************************

The Following code is written to test whether the Static Analysis Tools will catch the .
following error types are not?

	1)	Uninitialized variable
	

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
void Uninitialized_var ()
{
	int Un_initialized_var, Calculated_value = 0;
	
	Calculated_value = Un_initialized_var * 10; /*this statement shows the presence of uninitialized var in the 
												calculation which leads to unexpected results */
											  
	if(Calculated_value == 0)
		printf("Calculated_value is equals to zero\n");
	else
		printf("Calculated_value value is= %d", Calculated_value);

}


