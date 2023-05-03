#include <stdio.h>
int binSearch(int arr[], int size, int search)
{
    int left=0, right=size-1, mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(arr[mid]==search)
            return mid;
        if(arr[mid]>search)
            right=mid-1;
        else
            left=mid+1;
    }
    return -1;

}
int main()
{
    int n,i=0;
    scanf("%d",&n);
    int arr[n];
    while(i<n)
    {
        scanf("%d",&arr[i++]);
    }
    int r=binSearch(arr,n,2);
    if(r==-1)
        printf("Not Available");
    else
        printf("Index: %d",r);
}
