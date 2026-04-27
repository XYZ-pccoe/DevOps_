#include<stdio.h>
#include<unistd.h>

//bubble sort
void sort(int arr[],int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

//main function
int main(){
	int n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements: \n",n);
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	pid_t pid = fork();
	if(pid == 0) {  //child process
		printf("This is child process!");
		printf("Child Process PID = %d, PPID = %d",getpid(), getppid());
		sort(arr,n);
		printf("Array sorted by child: ");
		for(int i = 0; i < n; i++) printf("%d", arr[i]);
		printf("\nChild Exiting");
	} else {
		printf("This is parent process!");
		printf("Parent process PID = %d, PPID = %d",getpid(),getppid());
		sleep(10);  /*no wait means child finishes its execution and still the parent is 
unaware about its completition and so process table has its entry and so the child process becomes zombie!*/
		printf("parent finished!");
	}
	return 0;
}
