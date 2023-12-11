#include <stdio.h>

int pageIsFound(int frame[],int count,int request){
    for(int i=0;i<count;i++){
        if(frame[i]==request)
            return 1;
    }
    return 0;
}

void fifo(int arr[],int n, int frame[],int no_frames){
    int fifoArr[no_frames][n];
    int front=0,count=0,p=0,j,k,i;
    for(i=0;i<n;i++){
        if(pageIsFound(frame,count,arr[i])){}
        else{
            p++;
            frame[front] = arr[i];
            front = (front+1)%no_frames;
            if(count != no_frames)
                count++;
        }
        for(j=0,k=0;j<no_frames;j++){
            if(k<count)
                fifoArr[k++][i] = frame[j];
            else 
                fifoArr[k++][i] = -1;
        }

    }

    // dispalying the frame

    for(i=0;i<no_frames;i++){
        for(j=0;j<n;j++){
            if(fifoArr[i][j] != -1)
                printf("%d  ",fifoArr[i][j]);
            else 
                printf("   ");
        }
        printf("\n");
    }
    printf("Page Faults(in FIFO) = %d\n",p);
}

void main(){
    printf("FIFO Page Replacement Algorithm\n");
    int no_of_request,i,no_of_frames;
    printf("Enter the number of frames: ");
    scanf("%d",&no_of_frames);
    printf("Enter the number of page requests: ");
    scanf("%d",&no_of_request);
    printf("Enter the page string each seperated by a space\n");
    int request_arr[no_of_request],Frame[no_of_frames];
    for(i=0;i<no_of_request;i++){
        scanf("%d",&request_arr[i]);
    }
    printf("\nPages\n");
    for(i=0;i<no_of_request;i++){
        printf("%d  ",request_arr[i]);
    }
    printf("\nPage Frames\n");
    fifo(request_arr,no_of_request ,Frame,no_of_frames);
}