#include <stdio.h>
#include <stdlib.h>

// function to sort array
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
    int n, head, direction, disk_size;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter the request queue:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size (e.g., 200): ");
    scanf("%d", &disk_size);

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

        // Go to end
        int distance = abs((disk_size - 1) - current);
        printf("%d -> %d = %d\n", current, disk_size - 1, distance);
        total_movement += distance;

        // Jump to start (0)
        distance = disk_size - 1; // from end to 0
        printf("%d -> %d = %d\n", disk_size - 1, 0, distance);
        total_movement += distance;

        current = 0;

        // Move right again
        for(int i = 0; i < n; i++) {
            if(req[i] < head) {
                int d = abs(req[i] - current);
                printf("%d -> %d = %d\n", current, req[i], d);
                total_movement += d;
                current = req[i];
            }
        }
    }
    else { // LEFT

        // Move left
        for(int i = n-1; i >= 0; i--) {
            if(req[i] <= head) {
                int distance = abs(req[i] - current);
                printf("%d -> %d = %d\n", current, req[i], distance);
                total_movement += distance;
                current = req[i];
            }
        }

        // Go to 0
        int distance = abs(current - 0);
        printf("%d -> %d = %d\n", current, 0, distance);
        total_movement += distance;

        // Jump to end
        distance = disk_size - 1;
        printf("%d -> %d = %d\n", 0, disk_size - 1, distance);
        total_movement += distance;

        current = disk_size - 1;

        // Move left again
        for(int i = n-1; i >= 0; i--) {
            if(req[i] > head) {
                int d = abs(req[i] - current);
                printf("%d -> %d = %d\n", current, req[i], d);
                total_movement += d;
                current = req[i];
            }
        }
    }

    float avg_seek_time = (float)total_movement / n;

    printf("\nTotal Head Movement = %d\n", total_movement);
    printf("Average Seek Time = %.2f\n", avg_seek_time);

    return 0;
}
