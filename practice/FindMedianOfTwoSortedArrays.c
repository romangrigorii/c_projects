#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int * nums1, int * nums2, int L1, int L2){
    int i1 = 0, i2 = 0, i = 0;
    int mid = (L1+L2)/2; 
    int out[mid];
    while (i<=mid){
        if (i2==L2){
            out[i] = nums1[i1];
            i1++;
        }
        else if(i1==L1){
            out[i] = nums2[i2];
            i2++;
        }
        else if(nums1[i1]<nums2[i2]){
            out[i] = nums1[i1];
            i1++;
        } else {
            out[i] = nums2[i2];
            i2++;
        }
        i++;       
    }
    if ((L1 + L2)%2) {
        return (double) out[mid];
    } else {
        return ((double) (out[mid] + out[mid-1]))/2;
    }
}

int main(){
    int vec1[] = {1,2};
    int vec2[] = {3,4};
    int vec3[] = {1,3};
    int vec4[] = {2};  
    printf("The median of vectors [1,2] and [3,4] is %lf\n", findMedianSortedArrays(vec1, vec2, sizeof(vec1)/sizeof(int), sizeof(vec2)/sizeof(int)));
    printf("The median of vectors [1,3] and [2] is %lf\n", findMedianSortedArrays(vec3, vec4, sizeof(vec3)/sizeof(int), sizeof(vec4)/sizeof(int)));
    return 0;
}