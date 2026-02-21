#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0;
    int count = 0;

    int freq[2 * MAX + 1] = {0};
    int offset = MAX;  

    freq[offset] = 1;   

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(freq[sum + offset] > 0)
            count += freq[sum + offset];

        freq[sum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}