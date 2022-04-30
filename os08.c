#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	int status;
	int total_mark; 
	int courses_count;
	int average; 
	// char sayHello[];
	// char name[];
	// FILE *fp;

	int pid1 = vfork();
	int pid2 = fork();

	if (pid1 < 0 || pid2 < 0) {
		printf("an error occurred while creating process");
	}
	else if (pid1 == 0 && pid2 != 0) { // in process 1
		int childpid1 = vfork();
		int childpid2 = vfork();

		if (childpid1 < 0 || childpid2 < 0) {
			printf("an error occurred while creating process");
		}

		else if (childpid1 == 0 && childpid2 != 0) { // process 1.1
			total_mark = 18 + 13 + 20;
			exit(0);
		}
		else if (childpid1 != 0 && childpid2 == 0) { // process 1.2
			sleep(1);
			courses_count = 3;
			exit(0);
		}

		else if (childpid1 > 0 &&  childpid2 > 0) { // process 1
			average = total_mark / courses_count;
			printf("average: %d \n", average);
			exit(0);
		}
	}


	
	else if (pid1 != 0 && pid2 == 0) { // process 2

		sleep(2);
		printf("process 2")
		// int childpid3 = fork();
		// int childpid4 = fork();

		// if (childpid3 < 0 || childpid4 < 0) {
		// 	printf("an error occurred while creating process\n");
		// }

		// else if (childpid3 == 0 && childpid4 != 0) { // process 2.1
		// 	// fp = fopen("name.txt", "w");
		// 	// if(fp == NULL) {
		// 	// 	printf("file can't be opened\n");
		// 	// 	exit(1);
		// 	// }
		// 	// fprintf(fp, "%s", 'Amin');
		// 	// fclose(fp);
		// 	printf("process 3");
		// 	exit(0);
		// }
		// else if (childpid3 != 0 && childpid4 == 0) { //process 2.2
		// 	sleep(1);
		// 	printf("process 4");
		// 	// fp = fopen("name.txt", "r");
		// 	// if(fp == NULL) {
		// 	// 	printf("file can't be opened\n");
		// 	// 	exit(1);
		// 	// }
		// 	// fgets(name, 50, fp);
		// 	// printf("%s", name);
		// 	// fclose(fp);
		// 	exit(0);
		// }

		// else if (childpid3 > 0 && childpid4 > 0) { //process 2
		// 	waitpid(childpid4, &status, 0);
		// 	printf("parent of 3 and 4");
		// 	// sayHello = "Hello ";
		// 	// strcat(sayHello,name);
		// 	// printf("%s \n", sayHello);
		// 	exit(0);
		// }

	}
	else if (pid1 > 0 && pid2 > 0) { // parent of all
		printf("your avg > %d \n", average);
		// waitpid(pid2, &status, 0);
		// printf("%s, Your average in this semister is> %d \n", sayHello, average);
	}
	
	return 0;
}