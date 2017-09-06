/********************Purpose of the code  **************************************************

The Following code is written to test whether the Static Analysis Tools will catch the .
following error types or not?

	1)	Out of bound array access
	
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

int Out_of_bound_array(int Source[]);

void Out_of_bound_array_access()
{
 
int Source[5] = {0,1,2,3,4};
int Destination[5] = {0,0,0,0,0};
int count=0;
int result = 0;

result = Out_of_bound_array(Source);


for (count=0; count<=5; count++)
{
	Destination [count] = Source[count]; /*Out of bound array access as we 
	                                    are accesing 6th elemenmt but the size of array is 5 only */
}

}

Out_of_bound_array(int Source[])
{
	int temp[5];
	int i=0;
	for (i=0;i<5;i++)
	{
		temp[i]=Source[i];

	}
	return temp[i];  /*trying to access 6 the element from the array it will lead to out of bound 
	                   array access error as array size is 5*/ 
	

}
