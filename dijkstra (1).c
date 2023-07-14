#include<stdio.h>
#define V 5
#define INF 9999

int selectmin(int val[V],int isvisited[V])
{
  int i,min=INF;
  int vertex;
  for(i=0;i<V;i++)
  {
    if(isvisited[i]==0 && val[i]<min)
    {
      vertex=i;
      min=val[i];
    }
  }
  return vertex;
}

void dijkstra(int G[][V],int start)
{
  int isvisited[V],val[V];
  int i,j;
  for(i=0;i<V;i++)
  {
    isvisited[i]=0;
    val[i]=INF;
  }
  val[start]=0;
  for(i=0;i<V-1;i++)
  {
    int k=selectmin(val,isvisited);
    isvisited[k]=1;
    for(j=0;j<V;j++)
    {
      if(G[k][j]!=0 && isvisited[j]==0 && val[k]!=INF && (val[k]+G[k][j]<val[j]))
        val[j]=val[k]+G[k][j];
    }
  }
  for(i=0;i<V;i++)
  {
     if(start!=i)
        printf("Distance from vetrx %d ---> to %d: is:-  %d\n",start+1,i+1,val[i]);
  }
}

int main()
{
  int i,j;
  int G[V][V];
  printf("Enter adjencency matrix of graph: \n");
  for(i=0;i<V;i++)
  {
     for(j=0;j<V;j++)
     {
         printf("enter weight %d to %d: ",i,j);
         scanf("%d",&G[i][j]);
     }
  }   
 printf("The 5X5 adjencency matrix of graph; You inputed is as follows:-\n");
 for(i=0;i<V;i++){
     for(j=0;j<V;j++){
         printf("%d\t",G[i][j]);
         }
         printf("\n");
     }           
 printf("\n\nUsing the Dijkstra's Algorithm:-\n\n");
 dijkstra(G,0); 
 return 0;
}
