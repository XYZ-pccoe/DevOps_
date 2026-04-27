#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter the disk request queue:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int total_movement = 0;

    printf("\nHead Movement:\n");

    for(int i = 0; i < n; i++) {
        int distance = abs(req[i] - head);
        total_movement += distance;

        printf("%d -> %d = %d\n", head, req[i], distance);

        head = req[i];
    }

    float avg_seek_time = (float)total_movement / n;

    printf("\nTotal Head Movement = %d\n", total_movement);
    printf("Average Seek Time = %.2f\n", avg_seek_time);

    return 0;
}
