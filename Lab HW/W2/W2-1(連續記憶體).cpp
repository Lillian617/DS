/*Dynamic consecutive memory allocation in array
    用 Array 配置連續的記憶體*/


#include<iostream>
void allocArray(int ***p, int m, int n)
{
    int **Arr = new int *[m];
    *Arr = new int [m*n];
    for(int i = 1; i < m; i++){
        *(Arr+i) = *(Arr+i-1)+n; //設定每一列的第一個元素的位置為前一列第一個的+n個位置。
    }
    *p = Arr;
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
      printf("%p ", &(array[j][k])); //%p→指针形式十六进制(打印地址，若輸出數據不足8位數會自動在左邊補0)。
                                     //%x→普通十六进制。
}
