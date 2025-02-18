#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
   
    int n;
    printf("Enter size : ");
    scanf("%d",&n);
        
    int k;
    printf("Enter k : ");
    scanf("%d",&k);
    
    int arr[n];
    int maxNum = 0;
    
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        
        if(maxNum < arr[i]) {
            maxNum = arr[i];
        }
    }
    
    int freq[maxNum+1];
    int cntSub = 0;
    
    for(int i=0;i<n;i++) {
        int cnt = 0;
        memset(freq,0,sizeof(freq));
        for(int j=i;j<n;j++) {
            freq[arr[j]]++;
            
            if (freq[arr[j]] == 1)
            {
                cnt++;
            }
            
            if(cnt == k) {
                cntSub++;
                for(int k=i;k<=j;k++) {
                    printf("%d ",arr[k]);
                }
                printf("\n");
            }else if(cnt > k) {
                break;
            }
        }
    }
    
    printf("subCount : %d\n",cntSub);
    return 0;
}
