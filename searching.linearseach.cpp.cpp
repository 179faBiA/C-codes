#include<iostream>
using namespace std;
//const int a[10];
int linearSearch(int a[],int n,int item);
int main()
{
    int a[8]={1,2,3,4,5,6,7,6};
    /*
    cout<<"array elements are:"<<endl;
    //char a[];

    for(int i=0;i<a[i];i++)
    {
        cout<<a[i]<<'\t';

    }
    cout<<endl;
    */

    cout<<"enter a value  ";
    int value  ;
    cin>>value;
    int location=linearSearch(a,8,value);
    if(location==-1)
        cout<<value <<"is not found "<<endl;
    else
        cout<<value<<" found at location"<<location<<endl;
    return 0;

}
int binarySearch(int a[],int n,int item)
{
    int lo=0;hi=n-1,mid;
    while(lo<=hi>)
    {
        mid(lo+hi)/2;
        if(item==a[mid])return mid;
        else if(item<a[mid])lo=mid+1;
        else hi=mid-1;
    }
}

