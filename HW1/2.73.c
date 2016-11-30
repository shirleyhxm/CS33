/* Addition that saturates to TMin or TMax */

int saturating_add(int x, int y)
{
  if ((x & 0x10000000)==0 && (y & 0x10000000)==0 && ((x+y) & 0x10000000)!=0)
    return TMax;
  else if ((x & 0x10000000)!=0 && (y & 0x10000000)!=0 && ((x+y) & 0x10000000)==0)
    return TMin;
  else
    return x+y;
}

/*
int saturating_add(int x, int y)
{
  if (x>>31 && y>>31 && ~((x+y)>>31))
    return TMin;
  else if (~(x>>31) && ~(y>>31) && (x+y)>>31)
    return TMax;
  else
    return x+y;
}
*/


/* arithmatic shift */ 
/* bool _builtin_add_overflow(int x, int y, &rest),
   1 if overflow,
   rest can be any type */
