//lookup table, lookup[3][4] = 4^4 - 3^4
//lookup[2] [3] = 3^3 - 2^3
//lookup[9][5] = 0 - 9^5


len = 0;
sum = 0;
while (N< 1 billion)
{
index = 0;
 
 
 do
 {
  sum += lookup[number[index]][len];
 } while ((++number[index] == 10) && ((number[index] = 0) || 1) && ++index > len && ++len);
 
 if (N == sum) print;
N++;
}

//=======================================================
#include <iostream>

using namespace std;

long tableLookup[10][10];


void
print ()
{
  int i = 0, j = 0;

  for (i = 1; i < 10; i++)
    for (j = 0; j < 10; j++)
      cout << tableLookup[i][j] << "  ";

}

void
initializeLookup ()
{
  int i = 0, j = 0;

  for (i = 1; i < 10; i++)
    for (j = 0; j < 10; j++)
      tableLookup[i][j] = j;


  for (i = 2; i < 10; i++)
    for (j = 0; j < 10; j++)
      tableLookup[i][j] = tableLookup[i - 1][j] * j;


  for (i = 1; i < 10; i++)
    {
      for (j = 0; j < 9; j++)
 {
   tableLookup[i][j] = tableLookup[i][j + 1] - tableLookup[i][j];
 }
      tableLookup[i][9] = -tableLookup[i][9];
    }
}

int
main ()
{

  int digitArray[10] = { 0 };

  long int N = 0, nLength = 1;

  long sum = 0, n = 0;

  int index = 0;

  cout << "Enter your max number :";

  cin >> N;

  initializeLookup ();

  n = 1;

  while (n <= N)
    {
      index = 0;

      do
 {
   sum += tableLookup[nLength][digitArray[index]];

   ++digitArray[index];

 }
      while (digitArray[index] == 10 && !(digitArray[index] = 0)
      && ((++index >= nLength && ++nLength) || 1));

      if (sum == n)
 {
   cout << n << endl;
 }
      n++;
    }
  return 0;
}
