/********************Purpose of the code  **************************************************

The Following code is written to test whether the Static Analysis Tools will catch the .
following error types or not?

	1)	Dead code
	

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

int add(int, int);
int sub(int, int);
int multi(int, int);


void Dead_code()
{
	int sum = 0, dif = 0, var1 = 40, var2 = 25;

	sum = add(var1, var2);
	dif = sub(var1, var2);
	
	printf("\nsum value = %d\n", sum);
	printf("difference value = %d\n\n", dif);
	
}

int add(int x,int y)
{
	int z = 0;
	z = x + y;
	return z;
}


int sub(int x,int y)
{
	int z = 0;
	z = x - y;
	return z;
}


int multi(int x,int y)
{
	int z = 0;
	z = x * y;
	return z;
}