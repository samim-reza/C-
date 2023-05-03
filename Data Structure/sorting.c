#include <stdio.h>
//#define array for(int i=0; i<n; i++)
void bubbleSort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void selectionSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int indexMin=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[indexMin]>arr[j])
                indexMin=j;
        }
        if(indexMin!=i)
        {
            int temp=arr[i];
            arr[i]=arr[indexMin];
            arr[indexMin]=temp;
        }

    }
}
void insertionSort(int arr[], int n)
{
    for (int i=1; i<n; i++)
    {
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void countSort(char arr[])
{
    int RANGE=255;
    char output[strlen(arr)];
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];
    for (i = 0; arr[i]; ++i)
    {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}
void countingSort(int array[], int size)
{
    int output[10];
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    int count[10];
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    //bubbleSort(arr,n);
    //selectionSort(arr,n);
    //insertionSort(arr,n);
    //countSort(arr);
    countingSort(arr,n);
    for(int i=0; i<n; i++) printf("%d ",arr[i]);
}
