#include <stdio.h>

void optimal(int frames[], int n_frames, int ref[], int n_ref) {
    int page_faults = 0;

    // Initialize frames
    for (int i = 0; i < n_frames; i++) {
        frames[i] = -1;
    }

    printf("\nOptimal Page Replacement:\n");

    for (int i = 0; i < n_ref; i++) {
        int page = ref[i];
        int found = 0;

        // 🔷 Check if page already exists (HIT)
        for (int j = 0; j < n_frames; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        // 🔷 If page NOT found (PAGE FAULT)
        if (!found) {
            page_faults++;

            int empty_index = -1;

            // 🔷 Step 1: Check for empty frame
            for (int j = 0; j < n_frames; j++) {
                if (frames[j] == -1) {
                    empty_index = j;
                    break;
                }
            }

            // 🔷 If empty frame available → fill it
            if (empty_index != -1) {
                frames[empty_index] = page;
            }
            else {
                // 🔷 Step 2: Apply Optimal Replacement
                int replace_index = -1;
                int farthest = -1;

                for (int j = 0; j < n_frames; j++) {
                    int k;

                    // Look into future
                    for (k = i + 1; k < n_ref; k++) {
                        if (frames[j] == ref[k]) {
                            if (k > farthest) {
                                farthest = k;
                                replace_index = j;
                            }
                            break;
                        }
                    }

                    // 🔷 If page is NOT used again
                    if (k == n_ref) {
                        replace_index = j;
                        break;
                    }
                }

                // 🔴 Safety fix (important)
                if (replace_index == -1) {
                    replace_index = 0;
                }

                // Replace page
                frames[replace_index] = page;
            }
        }

        // 🔷 Print frames after each step
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

    optimal(frames, n_frames, ref, n_ref);

    return 0;
}