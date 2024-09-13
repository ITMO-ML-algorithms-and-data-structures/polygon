#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
	int LEN = 100;
    int * list = (int *)malloc(sizeof(int) * LEN);
    for (int i = 0; i < LEN; i++) {
    	list[i] = rand() % 99 + 1;
    }
    int cnt = 0;
    int * starts = (int *)malloc(sizeof(int) * (cnt + 1));
    int * ends = (int *)malloc(sizeof(int) * (cnt + 1));
    int s = 30;
    for (int i = 0; i < LEN; i++) {
    	int local_sum = 0;
    	for (int j = i; j < LEN; j++) {
    		local_sum = local_sum + list[j];
    		//printf("%d - %d: %d\n", i, j, local_sum);
    		if (local_sum == s) {
    			//printf("OK\n");
    			starts[cnt] = i;
    			ends[cnt] = j;
    			cnt++;
    			starts = (int *)realloc(starts, sizeof(int) * (cnt + 1));
    			ends = (int *)realloc(ends, sizeof(int) * (cnt + 1));
    		}
    	}
    }
    for (int i = 0; i < LEN; i++) {
    	printf("%d ", list[i]);
    }
    printf("\n%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
    	int start = starts[i];
    	int end = ends[i];
    	int local_sum = 0;
    	for (int j = start; j <= end; j++) {
    		printf("%d(%d) ", list[j], j);
    		local_sum = local_sum + list[j];
    	}
    	printf("= %d\n", local_sum);
    }
    free(list);
    free(starts);
    free(ends);
    return 0;
}