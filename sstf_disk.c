#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int req[n], visited[n];

    printf("Enter the disk request queue:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        visited[i] = 0; // mark all as not visited
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int total_movement = 0;

    printf("\nHead Movement:\n");

    for(int count = 0; count < n; count++) {

        int idx = -1;
        int min = 9999;

        // find nearest request
        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                int distance = abs(req[i] - head);
                if(distance < min) {
                    min = distance;
                    idx = i;
                }
            }
        }

        // move head
        printf("%d -> %d = %d\n", head, req[idx], min);

        total_movement += min;
        head = req[idx];
        visited[idx] = 1;
    }

    float avg_seek_time = (float)total_movement / n;

    printf("\nTotal Head Movement = %d\n", total_movement);
    printf("Average Seek Time = %.2f\n", avg_seek_time);

    return 0;
}
