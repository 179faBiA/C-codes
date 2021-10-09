#include<iostream>
using namespace std;
void bubbleSort(int a[],int size)
{
    int temp;
    for(int i=0;i < size;i++){
            for(int j=0;j<size-i-1;j++){
                if (a[j]>a[j+1]){
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
    }
}
int main()
{
    int a[]={2,4,6,8,9,4};
    //srand(time(0));
    cout<<"array before sorf"<<endl;
    for(int i=0;i<6;i++){
        cout<<a[i]<<endl;
    }

    bubbleSort(a,6);
    cout<<"array after sort"<<endl;
    for(int i=0;i<6;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
