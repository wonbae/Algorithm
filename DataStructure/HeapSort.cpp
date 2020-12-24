#include <iostream> 
using namespace std; 

// To heapify a subtree rooted with node 'root' which is 
// an index in arr[]. 'n' is size of heap 
// heap을 구성하기를 heapify라 부름
void heapify(int arr[], int n, int root) 
{ 
	int largest = root; // Initialize largest as root 
	int left = 2*root + 1; // or left = (i + 1)*2 - 1 
	int right = 2*root + 2; // or right = (i + 1)*2 

	// If left child is larger than root 
	if (left < n && arr[left] > arr[largest]) 
		largest = left; 

	// If right child is larger than largest so far 
	if (right < n && arr[right] > arr[largest]) 
		largest = right; 

	// If largest is not root 
	if (largest != root) 
	{ 
		swap(arr[root], arr[largest]); 

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest); 
	} 
} 

// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i); 

	// One by one extract an element from heap 
	for (int i=n-1; i>=0; i--) 
	{ 
		// Move current root to end 
		swap(arr[0], arr[i]); 

		// call max heapify on the reduced heap 
		heapify(arr, i, 0); 
	} 
} 

/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
	for (int i=0; i<n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 

// Driver program 
int main() 
{ 
	int arr[] = {12, 11, 13, 5, 6, 7}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	heapSort(arr, n); 

	cout << "Sorted array is \n"; 
	printArray(arr, n); 
} 
