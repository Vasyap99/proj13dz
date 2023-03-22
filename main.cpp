#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include "graph.h"

Graph g;

int main(int argc, char** argv) {
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);       
    g.addVertex(6);
    g.addVertex(7);
    g.addVertex(8);
    g.addVertex(9);    
    g.addVertex(10);        

    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    //g.addEdge(0,3,1);
    g.addEdge(2,5,1);
    g.addEdge(1,4,1);
    //g.addEdge(4,3,1);
    g.addEdge(5,3,1);
    g.addEdge(4,7,1);
    //g.addEdge(3,6,1);
    g.addEdge(3,7,1);
    g.addEdge(3,8,1);
    //g.addEdge(5,8,1);
    g.addEdge(8,6,1);
    g.addEdge(7,6,1);
	
	for(int i=0;i<10;i++) for(int j=0;j<10;j++){
	   int res=g.findMinWayDFS(i, j);
       std::cout << (res<3 ? "y ":"n ") << i << ':'<< j << ' '<< res << std::endl;		
	}
	
		  
	return 0;
}
