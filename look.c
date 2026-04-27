#include <stdio.h>
#include <stdlib.h>

// sort function
void sort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, head, direction;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter the request queue:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &direction);

    sort(req, n);

    int total_movement = 0;
    int current = head;

    printf("\nHead Movement:\n");

    if(direction == 1) { // RIGHT

        // Move right
        for(int i = 0; i < n; i++) {
            if(req[i] >= head) {
                int distance = abs(req[i] - current);
                printf("%d -> %d = %d\n", current, req[i], distance);
                total_movement += distance;
                current = req[i];
            }
        }

        // Then move left (remaining requests)
        for(int i = n-1; i >= 0; i--) {
            if(req[i] < head) {
                int distance = abs(req[i] - current);
                printf("%d -> %d = %d\n", current, req[i], distance);
                total_movement += distance;
                current = req[i];
            }
        }

    } else { // LEFT

        // Move left
        for(int i = n-1; i >= 0; i--) {
            if(req[i] <= head) {
                int distance = abs(req[i] - current);
                printf("%d -> %d = %d\n", current, req[i], distance);
                total_movement += distance;
                current = req[i];
            }
        }

        // Then move right
        for(int i = 0; i < n; i++) {
            if(req[i] > head) {
                int distance = abs(req[i] - current);
                printf("%d -> %d = %d\n", current, req[i], distance);
                total_movement += distance;
                current = req[i];
            }
        }
    }

    float avg_seek_time = (float)total_movement / n;

    printf("\nTotal Head Movement = %d\n", total_movement);
    printf("Average Seek Time = %.2f\n", avg_seek_time);

    return 0;
}
