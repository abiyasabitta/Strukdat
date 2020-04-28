#include<stdio.h>

int total_prima(int *a)
{
    int angka=3, count, pembagi, jumlah=2;
    for (count = 2; count <= *a;)
  {
    for (pembagi = 2; pembagi <= angka - 1; pembagi++)
    {
      if (angka%pembagi == 0)
        break;
    }
    if (pembagi == angka)
    {
      jumlah += angka;
      count++;
    }
    angka++;
  }
    printf("Total %d bilangan prima adalah %d\n", *a, jumlah);
  return 0;
}


int main()
{
    int angka;
    scanf("%d", &angka);
    if(angka !=0) total_prima(&angka);
    else{
        printf("Total 0 bilangan prima adalah 0\n");
    }
    

    return 0;
}