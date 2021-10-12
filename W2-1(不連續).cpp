#include<iostream>
void allocArray(int ***p, int m, int n)
{
    int **Arr = new int* [m];
    for(int i = 0; i < m; i++){
        Arr[i] = new int[n];
    }
    *p = Arr;//☆
}

int main()
{
  int **array, *a;
  int j, k;
  allocArray(&array, 5, 10);
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      array[j][k] = j * 10 + k;
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      printf("%p\n ", &(array[j][k])); //%p→指针形式十六进制(打印地址，若輸出數據不足8位數會自動在左邊補0)。
                                     //%x→普通十六进制。
}
