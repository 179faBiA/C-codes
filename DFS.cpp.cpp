#include <stdio.h>
#include <stdlib.h>
#define white 1
#define gray 2
#define black 3
#define nil -1
#define inf 1000
//fabia

int vertex, time;
int G [100][100], color[100], prev[100],d[100],f[100];

void createGraph ();
void DFS ();
void DFS_Visit(int u);
void result();



int main()
{
    createGraph();
    DFS();
    result() ;

}


void createGraph()
{
    int i, maxEdge, source, destin;
    printf ("Enter number of vertex:");
    scanf ("%d", &vertex);
    maxEdge = vertex * (vertex-1);

    printf("\nChoose two vertex from 0 to %d and enter -1 -1 to end the edge input");
    for (i=1; i<=maxEdge; i++)
    {
        printf ("Enter edge %d: ",i);
        scanf ("%d%d", &source,&destin);
        if (source == -1 && destin == -1)
            break;

        if (source>=vertex || destin>=vertex || source<0 || destin <0)
        {
            printf ("Invalid \n");
            i--;
        }
        else
        {
            G[source][destin] = 1;
        }

    }

}

void DFS()
{
    int u ;
    for (u=0; u< vertex; u++)
    {
        color [u]= white;
        prev[u]= nil;
        f[u]=inf;
        d[u]=inf;
    }

    time=0;


    for (u=0; u< vertex; u++)
    {
        if(color[vertex]== white)
            DFS_Visit(u);
    }

}

   void DFS_Visit(int u)
   {

       int v;
       color[u]== gray;
       time++;
       d[u]=time;
       for (v=0; v<vertex;v++)
       {
           if(color[v]==white)
           {
               prev[v]=u;
               DFS_Visit(v);
           }
       }

      time++;
      f[u] =time;
      color[u]== black;
   }


void result()
{

    for(int i=0; i<vertex; i++)
        printf("%d%d%d\n",i,d[i],f[i]);
}
