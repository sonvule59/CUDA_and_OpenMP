__global__ void __global_func ( int *a, int *b, int *c )
{
  int i = threadIdx.x;
  int j = threadIdx.y;
  int k = threadIdx.z;

  if ( i == 0 && j == 0 && k == 0 )
  {
    c[0] = a[0] * b[0];
  }
  else if ( i == 0 && j == 0 && k != 0 )
  {
    c[k] = a[0] * b[k];
  }
  else if ( i == 0 && j != 0 && k == 0 )
  {
    c[j] = a[j] * b[0];
  }
  else if ( i == 0 && j != 0 && k != 0 )
  {
    c[k] = a[j] * b[k];
  }
  else if ( i == 1 && j == 0 && k == 0 )
  {
    c[0] = a[1] * b[0];
  }
  else if ( i == 1 && j == 0 && k != 0 )
  {
    c[k] = a[1] * b[k];
  }
  else if ( i == 1 && j != 0 && k == 0 )
  {
    c[j] = a[1] * b[0];
  }
  else if ( i == 1 && j != 0 && k != 0 )
  {
    c[k] = a[j] * b[k];
  }
  else if ( i == 2 && j == 0 && k == 0 )
  {
    c[0] = a[2] * b[0];
  }
  else if ( i == 2 && j == 0 && k != 0 )
  {
    c[k] = a[2] * b[k];
  }
  else if ( i == 2 && j != 0 && k == 0 )
  {
    c[j] = a[2] * b[0];
  }
  else if ( i == 2 && j != 0 && k != 0 )
  {
    c[k] = a[j] * b[k];
  }
  else if ( i == 3 && j == 0 && k == 0 )
  {
    c[0] = a[3] * b