
/*********************Purpose of the code  **************************************************

The Following code is written to test whether the Static Analysis Tools will catch the .
following error types or not?

	1)	Illegal dereferance of a pointer
	

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

void Illegal_Dereference ( void); 
void Illegal_dereferance_of_a_pointer()
{
	int *ptr_i;
	float *ptr_f;
	int a = 5, b = 6;

	ptr_i = &a;
	ptr_f = &b; //Illegal. Here storing address of an integer in a float pointer.
	
	Illegal_Dereference();
	
}

void Illegal_Dereference()

{

	int *ptr_i1;
	float *ptr_f1;
	int a1 = 5, b1 = 6;

	ptr_i1 = &a1;
	ptr_f1 = &b1; //Illegal. Here storing address of an integer in a float pointer.
}
