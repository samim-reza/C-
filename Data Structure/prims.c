
#include <stdio.h>
#define max 5
int matrix[max][max];
void init()
{
    for(int i=0;i<max;i++)
        for(int j=0;j<max;j++)
            matrix[i][j]=0;
}
void print()
{
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
}
int main() {
    int edge,a,b,cost;
    printf("Enter the number of edge: ");
    scanf("%d",&edge);
    init();
    while(edge-->0)
    {
        scanf("%d%d%d",&a,&b,&cost);
        matrix[a][b]=cost;
        matrix[b][a]=cost;
    }
    print();
    int visit[max]={0};
    edge=0;
    cost=0;
    visit[1]=1;
    while(edge<max-1){

        int min=9999;
        int x=0,y=0;

        for(int i=0;i<max;i++){
            if(visit[i]){
                for(int j=0;j<max;j++){
                    if(!visit[j]&&matrix[i][j]){
                        if(matrix[i][j]<min){
                            x=i;
                            y=j;
                            min=matrix[i][j];
                        }
                    }
                }
            }
        }
        printf("%d %d\n",x,y);
        cost+=matrix[x][y];
        visit[y]=1;
        edge++;
    }
    printf("minimum cost %d\n",cost);
    return 0;
}
