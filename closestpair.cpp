// ********************************************************************************
// 	Name: Ryan Pierce
// 	Date: 1-25-2021
//	Purpose: This program generates an array with 10 random numbers in them,
//		 it will then use a function to find the closest pair and their
//		 distance from each other using a decrease and conquer algorithm
// ********************************************************************************


#include <iostream>
#include <cstdlib>

using namespace std;

void closestPair(int arr[], int left, int right, int& index1, int& index2, int& distance); //uses divide and conquer
void closestPair2(int arr[], int left, int right, int& index1, int& index2, int& distance); //uses better coded version of divide and conquer

void closestPair3(int arr[], int left, int right, int& index1, int& index2, int& distance); // uses decrease and conquer


int main(){

	const int N = 10; //constant size of array
	int arr[N]; // array creation

	srand(time(0)); //random seed for generating

	//fill array with random integers
	for(int i = 0; i < N; i++){
		arr[i] = (rand() % 100) + 1;
	}

	//print array to screen
	for(int j = 0; j < N; j++){
		cout << arr[j] << "\t";
	}
	cout << endl << endl;

	//set index1 and index2 and distance to initial values
	int index1 = arr[0];
	int index2 = arr[9];
	int distance = abs(index1 - index2);

	//closestPair(arr, 0, 9, index1, index2, distance); 
	//closestPair2(arr, 0, 9, index1, index2, distance);
	closestPair3(arr, 0, 9, index1, index2, distance);


	cout << "Closest pair = " << index1 << "," << index2 << endl;
	cout << "Distance = " << distance << endl;

	return 0;
}

//first function for divide and conquer
void closestPair(int arr[], int left, int right, int& index1, int& index2, int& distance){
	//if left and right indexes intersect then stop
	if(left == right){
		return;
	//else do this
	}else{
		//if left and right indexes are next to each other do this
		if(left + 1 == right){
			//if integer in left index is less than the one in the right index do this
			if(arr[left] < arr[right]){
				//if the subraction is less than value in distance then the subtraction value will be new distance
				//and index1 will be integer in left index and index2 will be integer in right index
				if( (arr[right] - arr[left]) < distance ){
					distance = arr[right] - arr[left];
					index1 = arr[left];
					index2 = arr[right];
				}
			//else do this
			}else{
				//if the subtraction is less than value in distance then the subtraction value will be new distance
				//and index1 will be integer in left index and index2 will be integer in right index
				if( (arr[left] - arr[right]) < distance ){
					distance = arr[left] - arr[right];
					index1 = arr[left];
					index2 = arr[right];
				}
			}
		//else do this
		}else{
			//if value in left index is less than value in right index dpo this
			if(arr[left] < arr[right]){
				//if the value of the subtraction between values in left and right indexes are less than distance then the 
				//subtraction value will be new distance and index1 will be the left index's value and index2 will be the right index's value
				if( (arr[right] - arr[left]) < distance){
					distance = arr[right] - arr[left];
					index1 = arr[left];
					index2 = arr[right];
				}
			//else do this
			}else{
				//if the subtraction value is less than the distance value then the subtraction value will be the new distance value
				//and index1 value will be the left index's value and index2 value will be the right index's value
				if( (arr[left] - arr[right]) < distance){
					distance = arr[left] - arr[right];
					index1 = arr[left];
					index2 = arr[right];
				}
			}
			//call the function recursively 3 times to get all comparison combinations
			closestPair(arr, left + 1, right, index1, index2, distance); //move left index to the right by 1 
			closestPair(arr, left, right - 1, index1, index2, distance); //move right index to the left by 1
			closestPair(arr, left + 1, right - 1, index1, index2, distance); //move both left index to the right and right index to the left by 1
		}
	}
}

//second function for divide and conquer that improves code from first function
void closestPair2(int arr[], int left, int right, int& index1, int& index2, int& distance){
	//if left and right indexes intersect then stop
	if(left  == right){
		return;
	//else do this
	}else{
		//if the left and right indexes are next to each other do this
		if(left + 1 == right){
			//if the absolute value of the subtraction between values in the left and right indexes is less than the distance then
			//the subtraction value will be new distance and index1 will be value in left index and index2 will be value in right index
			if( abs(arr[left] - arr[right]) < distance ){
				distance = abs(arr[left] - arr[right]);
				index1 = arr[left];
				index2 = arr[right];
			}
		//else do this
		}else{
			//if the absolute value of the subtraction between values in the left and right indexes is less than the distance then
			//the subtraction value will be new distance and index1 will be value in left index and index2 will be value in right index
			if( abs(arr[left] - arr[right]) < distance){
				distance = abs(arr[left] - arr[right]);
				index1 = arr[left];
				index2 = arr[right];
			}
			//call function 3 times recursively to get all comparison combinations
			closestPair2(arr, left + 1, right, index1, index2, distance); //move left index to the right by 1
			closestPair2(arr, left, right - 1, index1, index2, distance); //move right index to the left by 1
			closestPair2(arr, left + 1, right - 1, index1, index2, distance); //move both left index to the right and right index to the left by 1
		}
	}
}

//function that uses decrease and conquer algorithm
void closestPair3(int arr[], int left, int right, int& index1, int& index2, int& distance){
	//if left and right indexes intersect stop
	if(left == right){
		return;
	//else do this
	}else{
		//loop to get every comparison combination from left index to the right index
		for(int i = left; i < right; i++){
			int temp = abs(arr[i] - arr[right]); //temp holds value of the abolute value of the subtraction between values in index
			//if temp is less than distance then temp will be new distance and index1's 
			//value will be index i's value and index2 will be the right index's value
			if(temp < distance){
				distance = temp;
				index1 = arr[i];
				index2 = arr[right];
			}
		}
		//function call recursively that moves left index to the right by 1
		closestPair3(arr, left + 1, right, index1, index2, distance);
	}
}
