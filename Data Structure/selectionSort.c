#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    for(int j=0; j<n-1; j++)
    {
        int temp=arr[j];
        for(int i=j; i<n; i++)
        {
            if(arr[i]<temp)
            {
                temp=arr[i];
                x=i;
            }
        }
        int temp2=arr[j];
        arr[j]=temp;
        arr[x]=temp2;
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}
