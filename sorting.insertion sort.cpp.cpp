#include<stdio.h>
int main()

{
    int n;
    scanf("%d",&n);

    int arr[n],i,temp,pos;
    for(i=0;i<n;i++)
    {
        scanf("%d" ,&arr[i]);
    }
    for(i=1;i<n;i++)
    {
        temp = arr[i];
        pos = i;
        while(pos>0 && arr[pos-1]>temp)
        {
            arr[pos] = arr[pos-1];
            pos--;
        }
        arr[pos] = temp;
    }
}
