#include<stdio.h>
#include <stdlib.h>
merg (int a[], int lb, int mid, int ub)
{
  int k[1000];
  int t = 0;
  int i = lb;
  int j = mid + 1;
  while (i <= mid && j <= ub)
    {
      if (a[i] < a[j])
	{
	  k[t] = a[i];
	  i++;
	}
      else
	{
	  k[t] = a[j];
	  j++;
	}
      t++;
    }
  if (i > mid)
    {
      while (j <= ub)
	{
	  k[t] = a[j];
	  j++;
	  t++;
	}
    }
  else
    {
      while (i <= mid)
	{
	  k[t] = a[i];
	  i++;
	  t++;
	}
    }
  for (i = lb; i <= ub; i++)
    {
      a[i] = k[i - lb];
    }
}

mergsort (int a[], int lb, int ub)
{
  if (lb < ub)
    {
      int mid = (lb + ub) / 2;
      mergsort (a, lb, mid);
      mergsort (a, mid + 1, ub);
      merg (a, lb, mid, ub);

    }
}

int
main ()
{
  int a[1000], n, lb, ub, mid, i;
  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }
  lb = 0;
  ub = n - 1;
  mergsort (a, lb, ub);
  for (i = 0; i < n; i++)
    {
      printf ("%d ", a[i]);
    }

}

