#include "graph.h"

GRAPH prims(GRAPH graph);
GRAPH graph_init(num size);
num graph_getNumberOfEdges(GRAPH graph);

GRAPH prims(GRAPH graph) {
	GRAPH mst = graph_init(graph->size);

	int i, j, n=graph_getNumberOfEdges(graph);
	int min=1000;
	int near[17];
	int t[2][15];
	
	for(i=0;i<=17;i++){
		near[i]=min;
	}

	//initialization of "near" array
	//find min cost edge
	for(i=1;i <= n;i++){
        for(j=i;j <= n;j++){
            if(mst[i][j] < min){
                min=mst[i][j];
                u=i;
                v=j;
            }
        }
    }
	t[0][0]=u;
    t[1][0]=v;
    
	near[u]=near[v]=0;

	//which edge is nearer
	for(i=1;i<=n;i++){
        if(near[i]!=0){
            if(mst[i][u]<mst[i][v])
                near[i]=u;
            else
                near[i]=v;
        }
    }

	for(i=1 ; i< n-1 ; i++){
        min=100;
        for(j=1 ; j<=n ; j++){
            if(near[j] != 0 && mst[j][near[j]]<min){
                k=j;
                min=mst[j][near[j]];
            }           
        }
        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;
    
        for(j=1;j<=n;j++){
            if(near[j]!=0 && mst[j][k]<mst[j][near[j]]){
                near[j]=k;
            }
        }
    }

	for(i=0;i<n-1;i++){
        printf("%d", t[0][i]);
    }

	return NULL;
}

