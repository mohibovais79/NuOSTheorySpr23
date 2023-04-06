#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int row=5;
int col=4;

int row_boundary(){
    printf("\n");
    for(int i=0;i<col;i++){
        printf("-----");
    }
    printf("\n");
}

int countAlive(int a[row][col],int r,int c ){
    int i,j,count=0;
    for(i=r-1;i<=r+1;i++){
        for(j=c-1;j<=c+1;j++){
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col)){
                continue;
            }
            if(a[i][j]==1){
                count++;
            }
        }
    }
    return count;
}

int main(){
    pid_t p[2];
    int a[row][col],b[row][col];
    int i,j;
    int liveCell;
    int userRow,userCol,initial;
    //generate matrix canvas with random values (live and dead cells)
    for(i=0; i<row; i++){
        for(j=0;j<col;j++){
            a[i][j] = 0;
        }
    }

    printf("here is the board  initially how many alive cells you want ? \n");
    scanf("%d",&initial);
    for (int k = 0; k < initial; k++)
    {
        
    scanf("%d",&userRow);
    scanf("%d",&userCol);
    a[userRow][userRow]=1;
    }

    for ( int pid = 0; pid <2 ; pid++)


    {
        p[pid]=fork();
    
    

     for(i=0; i<row; i++){
        for(j=0;j<col;j++){
            liveCell = countAlive(a,i,j);
            if (p[pid]>0)
            {
                /* code */
            
            
            if(a[i][j]==1 && (liveCell==2 || liveCell==3)){
                b[i][j]=1;
            }}
            if (p[pid]==0){
 
            else if(a[i][j]==0 && liveCell==3){
                b[i][j]=1;
            }
            
 
            else{
                b[i][j]=0;
            }
            }
            
        }
    }
    }

    //print next generation
    printf("\nNext Generation:");
     row_boundary(row);
    for(i=0; i<row; i++){
        printf(":");
        for(j=0;j<col;j++){
            printf("  %d  :",b[i][j]);
        }
        row_boundary(row);
    }
 
    return 0;







}