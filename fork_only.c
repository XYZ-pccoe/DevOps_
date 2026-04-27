#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// Bubble Sort
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
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pid_t pid = fork();

    if(pid == 0) {
        // Child Process
        printf("\n--- Child Process ---\n");
        printf("PID = %d, PPID = %d\n", getpid(), getppid());

        sort(arr, n);

        printf("Sorted by Child: ");
        for(int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else {
        // Parent Process
        printf("\n--- Parent Process ---\n");
        printf("PID = %d, PPID = %d\n", getpid(), getppid());

        sort(arr, n);

        printf("Sorted by Parent: ");
        for(int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        wait(NULL); // Parent waits for child
        printf("Child process finished\n");
    }

    return 0;
}
