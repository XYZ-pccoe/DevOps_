#include <stdio.h>

void fifo(int frames[], int n_frames, int ref[], int n_ref) {
    int page_faults = 0;
    int index = 0;  // points to next position to replace

    // Initialize frames as empty
    for (int i = 0; i < n_frames; i++) {
        frames[i] = -1;
    }

    printf("\nFIFO Page Replacement\n");

    // Process each page
    for (int i = 0; i < n_ref; i++) {
        int page = ref[i];
        int found = 0;

        // Check if page already exists (HIT)
        for (int j = 0; j < n_frames; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        // If page not found → Page Fault
        if (!found) {
            frames[index] = page;   // replace page
            index = (index + 1) % n_frames;  // move pointer circularly
            page_faults++;
        }

        // Print frames after each step
        printf("After accessing %d: ", page);
        for (int j = 0; j < n_frames; j++) {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults = %d\n", page_faults);
}

int main() {
    int n_frames, n_ref;

    printf("Enter number of frames: ");
    scanf("%d", &n_frames);

    printf("Enter number of pages: ");
    scanf("%d", &n_ref);

    int ref[n_ref];
    printf("Enter reference string: ");
    for (int i = 0; i < n_ref; i++) {
        scanf("%d", &ref[i]);
    }

    int frames[n_frames];

    fifo(frames, n_frames, ref, n_ref);

    return 0;
}
