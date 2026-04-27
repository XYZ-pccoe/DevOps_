#include <stdio.h>


void lru(int frames[], int n_frames, int ref[], int n_ref) {
    int page_faults = 0;
    int time = 0;
    int recent[100]; 

   
    for (int i = 0; i < n_frames; i++) {
        frames[i] = -1;
        recent[i] = -1;
    }

    printf("\n LRU Page Replacement \n");

    for (int i = 0; i < n_ref; i++) {
        int page = ref[i];
        int found = 0;

        for (int j = 0; j < n_frames; j++) {
            if (frames[j] == page) {
                found = 1;
                recent[j] = time++; 
                break;
            }
        }

        if (!found) {
            page_faults++;
            int min_time = 9999, replace_index = 0;
            for (int j = 0; j < n_frames; j++) {
                if (recent[j] < min_time) {
                    min_time = recent[j];
                    replace_index = j;
                }
            }
            frames[replace_index] = page;
            recent[replace_index] = time++;
        }
        printf("After accessing %d: ", page);
        for (int j = 0; j < n_frames; j++) {
            if (frames[j] == -1) printf("- ");
            else printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults = %d\n", page_faults);
}

int main() {
    int n_frames, n_ref;

    printf("Enter number of page frames: ");
    scanf("%d", &n_frames);

    printf("Enter number of page references: ");
    scanf("%d", &n_ref);

    int ref[n_ref];
    printf("Enter the reference string: ");
    for (int i = 0; i < n_ref; i++) {
        scanf("%d", &ref[i]);
    }

    int frames[n_frames];
    lru(frames, n_frames, ref, n_ref);

    return 0;
}
