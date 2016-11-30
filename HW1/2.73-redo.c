/* Addition that saturates to TMin or TMax */

int saturating_add(int x, int y)
{
  int rest;
  if (__builtin_add_overflow(x, y, &rest) == 1)
    if (x<0)
      return TMin;
    else
      return TMax;
  else
    return x+y;
}
