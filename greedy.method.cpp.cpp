
#include<bits/stdc++.h>
using namespace std;


int *Greedy_Method(int Coin[], int coin, int V)
{
    const int n=4;
int c[n]= {30,20,5,1},ans[n],ans1[n];

int main()
{
    int num,s=40,sum=0,sum1=0,p;
    for(int i=0; i<n; i++)
    {
        while(s>0)
        {
            if(c[i]<=s)
            {
                num=s/c[i];
                s=s-c[i]*num;
                ans[i]=num;
                sum+=ans[i];

                if(ans[i]>1)
                    p=c[i]*i;
                else
                    p=c[i];
                ans1[i]=p;
                sum1+=ans1[i];
            }
            break;
        }
    }
    cout<<"Greedy needs minimum "<<sum<<" coins."<<" ";

    for(int i=0; i<n; i++)
    {
        cout<<ans1[i];
        cout<<" ";
    }
    cout<<"= "<<sum1<<endl;

    return 0;
}

}

int *DP_Method(int Coin[], int coin, int V)
{
    int typ, lim, i, j;
    for(i=1; i <= typ; i++)
    {
        cin >> Coin[i];
    }
    int T[typ+1] [lim+1];

    for(i=0; i<=typ; i++)
    {
        for(j=0; j <= lim; j++)
        {
            if(j == 0)
            {
                T[i][j]=0;
            }
            else if(i == 0)
            {
                T[i][j]= 99;
            }
            else
            {
                if(j-Coin[i] >= 0)
                {
                    if(T[i-1][j] <= 1+ T[i][j-Coin[i]])
                        T[i][j] = T[i-1][j];
                    else
                        T[i][j] = 1+T[i][j-Coin[i]];
                }
                else
                    T[i][j] = T[i-1][j];
            }
        }
    }

    i = typ;
    j = lim;
    int total = 0;
    cout << "DP need minimum "<< T[i][j] <<" coins.";

    while(T[i][j] != 0)
    {
        if(T[i-1][j] == T[i][j])
            i--;
        else
        {
            //cout << Coin[i];
            cout << "+" << Coin[i]; ///i can't control the first sign
            j = j- Coin[i];
            total = total+Coin[i];
        }

    }
    cout << "=" << total;
    cout << endl << endl;

    static int arr2[]= {total, i};
    return arr2;
}
void RevArr(int Arr[],int n)
{
    int s = 0;
    int l = n-1;
    while(s < l)
    {
        swap(Arr[s],Arr[l]);
        s++;
        l--;
    }
}

int main()
{
    int coin, V, i, j;
    cout<<"Coin limit: ";
    cin >> V;
    cout << "Coin type: ";
    cin >> coin;

    int Coin[coin + 1];
    cout<<"Coins: ";

    for(i=1; i <= coin; i++)
    {
        cin >> Coin[i];
    }

    sort(Coin, Coin+coin);
    RevArr(Coin, coin);


    int *func1 = Greedy_Method(Coin, coin, V);
    int *func2 = DP_Method(Coin, coin, V);

    if(func2[0] == V and func2[1] < func1[1] )
        cout<<endl<<"Greedy couldn't give the optimal solution but DP did.";
    else if(func1[0] != V and func2[0] == V)
        cout<<endl<<"Greedy was unable to solve but DP did.";
    else
        cout<<endl<<"Greedy and DP both are optimal.";


    return 0;
}
