/********************Purpose of the code  **************************************************

The Following code is written to test whether the Static Analysis Tools will catch the .
following error types or not?

	1)	Detection of constant condition
	
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

void Detection_of_constant_condition()
{
 
	enum boolean { Never=0, Always };
    enum boolean var;
	 
	if (Always) 
		var = Always;
	else             
		var = Never; 
			

	if (Never || Always) 
		var = Always;
	else
		var = Never;


	if (Never) 
		var = Never;
	else
		var = Always;
			


// This is actually valid code, but would still get reported by this error check
	while (Always) 
	{
	  	var = Always;
	
		if (Never || Always) 
	 		break;
	}	


}