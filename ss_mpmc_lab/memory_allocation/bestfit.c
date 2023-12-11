#include <stdio.h>

struct mem_details
{
    int size;
    int rem;
    int index;
    /* data */
}block[10],temp;

void sort(int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(block[j].rem >= block[j+1].rem){
                temp = block[j];
                block[j] = block[j+1];
                block[j+1] = temp;
            }
        }
    }
}

void partitioning_block(int n){
    for(int i=0;i<n;i++){
        printf("\nenter partition size : ");
        scanf("%d",&block[i].size);
        block[i].rem = block[i].size;
        block[i].index = i;
    }
}

void request_allocation(int req,int n){
    int flag = 0;
    int i;
    sort(n);
    for(i=0;i<n;i++){
        if(block[i].rem >= req){
            block[i].rem -= req;
            flag = 1;
            break;
        }
    }
    if(flag==1)
        printf("request allocated at %d",block[i].index);
    else
        printf("request not allocated");
}

void main(){
    int n;
    int data;
    printf("\nenter no of partitions : ");
    scanf("%d",&n);
    partitioning_block(n);

    while(1){
        printf("\nenter block :");
        scanf("%d",&data);
        request_allocation(data,n);
    }
}