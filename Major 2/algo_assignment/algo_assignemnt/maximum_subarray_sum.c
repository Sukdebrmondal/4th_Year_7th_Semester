
// Write a C program to implement the Maximum Subarray Sum algorithm using divide and conquer approach.
#include<stdio.h>

int max(int a,int b,int c){
    if(a>b && a>c)
        return a;
    else if (b>a && b>c) 
        return b;
    else if (c>a & c>b)
        return c;
}

int combine(int arr[], int s, int m, int e)
{
    int sum = 0;
    int left_max = arr[m];
    for (int i = m; i >= s; i--){
        sum = sum + arr[i];
        if (sum > left_max)
            left_max = sum;
    }

    sum = 0;
    int right_max = arr[m + 1];
    for (int i = m + 1; i <= e; i++){
        sum = sum + arr[i];
        if (sum > right_max)
            right_max = sum;
    }

    return left_max + right_max;
}

int divide(int arr[],int s, int e){
    if(s == e){
        return arr[s];
    }
    else{
        int m = (e+s)/2;
        int left_sum = divide(arr,s,m);
        int right_sum = divide(arr,m+1,e);
        int comb_sum = combine(arr,s,m,e);
        return max(left_sum,right_sum,comb_sum);
    }
}

int main(){
    int n;
    printf("enter the number of elements in the array: \n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements one by one:\n");
    for (int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int a = divide(arr,0,n-1);
    printf("%d",a);
}


/*
enter the number of elements in the array: 
7
enter the elements one by one:
23 -34 6 -34 46 42 31
119

*/