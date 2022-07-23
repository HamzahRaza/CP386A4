//Syed Raza 170975760
//Github: HamzahRaza https://github.com/HamzahRaza/CP386A4
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <sys/mman.h>

struct process {
	int startAddress;
	char name[2];
	int memoryAllocation;
};

int main(int argc, char *argv[]) {
	//allocate initial 1 mb
	int *start;
	start = malloc(atoi(argv[1]));
//	int *ptr = mmap(NULL, atoi(argv[1]), PROT_EXEC, MAP_SHARED, 0, 0);
	printf("Allocated %d bytes of memory\n", atoi(argv[1]));

	char command[2];
	char process[2];
	int size;
	char b;
	struct process processes[15];
	int process_count = 0;

	do {
		printf("allocator>");
		scanf("%s", command);

		if (strcmp(command, "RQ") == 0) {
			scanf("%s", process);
			scanf("%d", &size);
			scanf("%c", &b);

//			int *ptr1 = mmap(NULL, size, PROT_EXEC, MAP_SHARED, 0, 0);
//			if (ptr1 == MAP_FAILED) {
//				printf("Error\n");
//				return 0;
//			}

			strcpy(processes[process_count].name, process);
			processes[process_count].startAddress = (int*) malloc(size);
			processes[process_count].memoryAllocation = size;
			process_count = process_count + 1;
		}

		printf("command: %s %d\n", processes[0].name,
				processes[0].startAddress);
	} while (strcmp(command, "Exit") != 0);

}
