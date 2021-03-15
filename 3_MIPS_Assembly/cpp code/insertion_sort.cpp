#include <iostream>

// Action: insert element elem in array a at positions i
void insert (int a[], int length, int elem, int i)
{
	int j;
	for (j = length - 1; j >= i; j--)
	{
		a[j+1] = a[j];
	}
	a[i] = elem;
}


// Result: smallest i for which holds: a[i] >= elem
int binarySearch (int a[], int length, int elem)
{
	int low=-1, high = length, mid;

	while (low < high - 1)
	{
		mid = (low + high) / 2;

		if (a[mid] >= elem)
			high = mid;
		else if (a[mid] < elem)
			low = mid;
	}

	return high;
}


// Action: sort table using the Insertion Sort Algorithm
void insertionSort (int a[], int length)
{
	int i;
	int *b = new int [length]; //initiallize a pointer b to array b[] with 'length' entries

	for (i = 0; i < length; i++) //for all array entries
	{
		int position = binarySearch (b, i, a[i]); //find the sorted position of a[i] 
		insert (b, i, a[i], position); //copy the value of the a[i] into b[position] 
	}

	for (i = 0; i < length; i++)
	{
		a[i] = b[i]; //copy sorted array b into array a 
	}

	delete [] b; //clear memory allocated for b
}


int main (void)
{
	int i, length; //initialize i, length 
	int *a; //initialize a pointer that stores the address of a variable of type int

	std::cout << "Insert the array size" << std::endl; //print to the monitor
	std::cin >> length; //store user intput in variable 'length'

	a = new int[length]; //new operator requests memory allocation, initializes it and returns the address of the memory to pointer a

	std::cout << "Insert the array elements, one per line" << std::endl; //print to the monitor
	for (i = 0; i < length; i++) 
	{
		std::cin >> a[i]; //let the user input values for each array entry of a
	}

	insertionSort (a, length); //sort table using the Insertion Sort Algorithm

	std::cout << "The sorted array is:" << std::endl; //print to the monitor
	for (i = 0; i < length; i++)    
	{
		std::cout << a[i] << std::endl; //print every entry in the array on a new line
	}

	return 0;
}