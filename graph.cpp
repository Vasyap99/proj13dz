#include "graph.h"

Graph::Graph() {
    for(int i=0;i < SIZE; i++)
      for(int j=0; j< SIZE; j++)
        matrix[i][j] = 0;
    vertexCount = 0;
}
// ?????????? ???????
void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount] = vnumber;
    vertexCount++;
}
// ?????????? ?????
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}
// ???????? ????????????? ?????
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
// ???????? ????????????? ???????
bool Graph::vertexExists(int v)
{
    for(int i=0;i<vertexCount;i++)
       if(vertexes[i] == v)
          return true;
    return false;
}






// ????? ??????????? ??????????
#define VERYBIGINT 1000000
//1000000000


int Graph::findMinWayDFS(int from, int to) {
   int*m=new int[SIZE];
   int cmin=VERYBIGINT;
   for(int j=0;j<SIZE;j++) m[j]=0;
   int r=findMinWayDFS1(m,0,cmin,from, to);
   delete[]m;
   return cmin;
}

int Graph::findMinWayDFS1(int*m,int v,int &cmin, int from, int to) {
   int min=VERYBIGINT;    
    
   m[from]=1;    
    
   if(from==to) {
       if(cmin>v) cmin=v;
       return matrix[from][to];
   } 
   //
   bool b=false;  int xi=0;
   for(int i=0;i<vertexCount;i++){
      if(matrix[from][vertexes[i]]!=0 && m[vertexes[i]]!=1){
         bool b=true;
         // 
         int*m1=new int[SIZE];          
         for(int j=0;j<SIZE;j++) m1[j]=m[j];         
         //
         int r1=findMinWayDFS1(m1,v+matrix[from][vertexes[i]],cmin,vertexes[i], to); 
         delete[]m1;
         //if(r1==VERYBIGINT) continue;
         if(min>r1) {min=r1; xi=vertexes[i];}
      }  
   }
   if((!b) || min==VERYBIGINT) return VERYBIGINT;
   else return matrix[from][xi]+min;
}
