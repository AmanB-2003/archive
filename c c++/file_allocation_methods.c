//C program for file allocation methods
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int m,n;
void contiguous_allocation(int num,int blocks,char name[m][n],int length[], int start_block[]){
    int start = 0;

    for (int i = 0; i < num; i++)
    {
        printf("Enter the name of the file %d :\n", i+1);
        scanf("%s",&name[i][0]);
        printf("Enter the length of the file %d :\n", i+1);
        scanf("%d",&length[i]);
        if (start+length[i] < blocks )       //enough space to allocate
        {
            start_block[i] = start;
            start=start + length[i];
            printf("The file %s is allocated.\n",name[i]);
        
        }
        else{
            printf("The file %s cannot be allocated.\n",name[i]);
            start_block[i] = 1000;
            length[i] = 0;
        }
    }

    printf("Files allocation table :\n");
    printf("%s%40s%40s\n","File Name","Start Block","Length");
    for (int i = 0; i < num; i++)
    {
        if(start_block[i] != 1000){
            printf("%s%40d%40d\n",name[i],start_block[i],length[i]);
        }
    }
}

void linked_allocation(int num,int blocks,char name[m][n],int length[], int start_block[]){
    int p,block[blocks];
    for (int i = 0; i < 100; i++)
    { block[i] = 0;}
    
    printf("Enter the number of blocks already allocated :\n");
    scanf("%d",&p);
    srand(time(0));
    for (int i = 0; i < p; i++)
    {  
        block[rand()%99] = 1;        //mark as already assigned
    }

     int start = 0;
        int j,end[10],i = -1;
        x : i++ ;
        printf("Enter the name of the file %d :\n", i+1);
        scanf("%s",&name[i][0]);
        printf("Enter the length of the file %d :\n", i+1);
        scanf("%d",&length[i]);
        if (start+length[i] < blocks - p )       //enough space to allocate
        {   if (block[start]== 1)
        {
            do
            {    start ++;
            } while (block[start]== 0);
            
        }
        
            start_block[i] = start;
            for ( j = start; j < start + length[i] ; j++)
            {
                if (block[j]== 0 )
                {
                    block[j] = 1;
                    if(j == start+length[i] -1 )
                    { printf("%d",j);}
                    else { printf("%d --> ", j);}
                }
                else
                {
                    start++;
                }
                
                
            }
            
            start= j;   end[i] = j;
            printf("The file %s is allocated.\n",name[i]);
        
        }
        else{
            printf("The file %s cannot be allocated.\n",name[i]);
            start_block[i] = 1000;
            length[i] = 0;
        }

    printf("Files allocation table :\n");
    printf("%s%20s%20s%20s\n","File Name","Start Block","Length","End Block");
    for (int k = 0; k < i+1; k++)
    {
        if(start_block[k] != 1000){
            printf("%s%20d%20d%20d\n",name[k],start_block[k],length[k],end[k]);
        }
    }  
    
}

void indexed_allocation(int num,int blocks,char name[m][n],int length[], int start_block[]){
    int index,block[blocks];
    for (int i = 0; i < 100; i++)
    { block[i] = 0;}
    
    printf("Enter the index block :  ");
    scanf("%d",&index);
    block[index] = 1;

     int start = 0;
        int j,k=0,end[10],i = -1;
        x : i++ ;
        printf("Enter the name of the file %d : ", i+1);
        scanf("%s",&name[i][0]);
        printf("Enter the length of the file %d : ", i+1);
        scanf("%d",&length[i]);
        int ind[length[i]];
        if (start+length[i] < blocks - index )       //enough space to allocate
        {   if (block[start]== 1)
        {
            do
            {    start ++;
            } while (block[start]== 0);
            
        }
        
            start_block[i] = start;
            for ( j = start; j < start + length[i] ; j++)
            {
                if (block[j]== 0 )
                {
                    block[j] = 1;
                    ind[k] = j; k++;
                }
                else
                {
                    start++;
                }
                
                
            }
            
            start= j;   end[i] = j;
            printf("The file %s is allocated.\n",name[i]);
                
        }
        else{
            printf("The file %s cannot be allocated.\n",name[i]);
            start_block[i] = 1000;
            length[i] = 0;
        }

    printf("Files allocation table :\n");
     for (int a = 0; a < length[i]; a++)
            {
                printf("%d ----> %d \n", index, ind[a]);
            }
    
}




int main(){
    char name[10][20];
    int start_block[10],length[10],num,blocks = 100;
    printf("Enter the number of files to be allocated :\n");
    scanf("%d",&num);

    contiguous_allocation(num,blocks,name,length,start_block);
    linked_allocation(num,blocks,name,length,start_block);
    indexed_allocation(num,blocks,name,length,start_block);
    return 0;
}
