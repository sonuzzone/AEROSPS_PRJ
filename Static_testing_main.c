#include<stdio.h>
#include "Declarations.h"

void main()
{

int Conversion_var = 5, var = 5, Converted_var = 0, Result = 0;

 access_to_null_ptr();
 Dead_code();
 Memory_leak();
 Detection_of_constant_condition();
 Illegal_dereferance_of_a_pointer();
 Out_of_bound_array_access();
 passed_value_never_used_main ();
 Overflow();
 Underflow();
 Divide_by_zero();
 Uninitialized_var ();
 Use_of_uninitialized_var ();
 Converted_var = Type_conversion(Conversion_var);
 Result = Variable_unused(var);

}