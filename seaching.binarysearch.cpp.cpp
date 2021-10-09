#include<bits/stdc++.h>
using namespace std;
int bin_Search(int *a, int n, int element);


int main()
{
    int n,temp,pos;
    cin >> n;

    int arr[n];
    for (int i = 0; i< n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++){
        temp = arr[i];
        pos = i;

        while(pos > 0 && arr[pos-1] < temp)
        {
            arr[pos] = arr[pos-1];
            pos--;
        }
        arr[pos] = temp;
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int num;
    cin >> num;
    int location = bin_Search(arr, n, num);

    if(location == -1)
        cout << "-1" << endl;
    else
        cout << location+1 << endl;

    return 0;
}


int bin_Search(int *a, int n, int item)
{
    int lo = 0, hi = n+1, mid;

    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(item == a[mid]) return mid;
        else if(item < a[mid]) lo= mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
