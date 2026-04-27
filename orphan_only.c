#include<stdio.h>
#include<unistd.h>

void sort(int arr[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n - i -1; j++){
			if(arr[j] > arr[j+1]){
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
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements: \n",n);
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	pid_t pid = fork();
	if(pid == 0){
		printf("This is a child process!");
		printf("Before parent exit: PID = %d and PPID = %d",getpid(), getppid());
		sleep(5);
		printf("after parent exit: PID = %d and PPID = %d", getpid(),getppid());
		sort(arr,n);
		printf("Array sorted by child: ");
		for(int i = 0; i < n; i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
	} else {
		printf("\nParent Process!");
		printf("PId = %d and PPID = %d",getpid(),getppid());
		printf("Parent exiting!");
		// no wait -> parent ends -> child still exists -> orphan (without parent process)
	}


	return 0;
}
