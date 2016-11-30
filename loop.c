/* 3.60
   A. rdi holds x;
      ecx/rcx holds n; 
      rax holds the result; 
      rdx holds the mask. 
   B. result = 0
      mask = 1
   C. mask != 0
   D. mask <<= n
   E. result |= (mask & x)
   F. (shown below)
*/

long loop(long x, long n)
{
  long result = 0;
  long mask;
  for (mask = 1; mask != 0; mask = mask << n){
	 result |= (mask & x);
  }
  return result;
}
