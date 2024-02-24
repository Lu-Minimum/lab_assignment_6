#include <stdio.h>

int search(int numbers[], int low, int high, int value) 
{
	//Check for null or invalid bound
	//though the program would have errors long before this would be called
	if (numbers==NULL||low<0||high<low) {
		return -1;
	}

	//Check if the lower bound and the upper bound are the same
	if (low==high) {
		//Check value
		if (numbers[low]==value) {
			return low;
		}

	} else {
		//Search lower half
		int a = search(numbers, low, (low+high)/2, value);
		if (a>=0) {
			return a;
		}
		
		//Search upper half
		a = search(numbers, ((low+high)/2)+1, high, value);
		if (a>=0) {
			return a;
		}
	}
	
	//Default return value is -1
	//Returns when value is not found
	return -1;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}