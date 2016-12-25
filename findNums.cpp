/***************************************************************************************************************************************************
	Author: Antonio Santos
	Description: This program finds the missing numbers in an array of values.
	Last update: 12/18/16
***************************************************************************************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
	int arrayMAX = 100;
	int array[arrayMAX];
	int randNum, holder, iterations = 0;
	int counter = 0;
	int bug = 0;
	int maxReachable = 1000;
	int minReachable = 1;

	srand(time(0));
	
	
	//creates array of values - linear time
	cout << "-----ARRAY OF VALUES-----" << endl;
	for(int i = 0; i < arrayMAX; i++){
		array[i] = rand()%maxReachable + minReachable;
		cout << array[i] << " | ";
	}	
	cout << endl << endl;
	


	//sorts array of values - O(N) 
/*
comment out the lines that start with *//* to see the iterations increase 2x
*/
	cout << "Sorting array";
	while(counter != arrayMAX - 1){
		iterations++;
		if(array[counter + 1] < array[counter]){
/**/			while(array[counter + 1] < array[counter]){
				holder = array[counter];
				array[counter] = array[counter + 1];
				array[counter + 1] = holder;
/**/				if(counter > 1)
/**/					counter--;
/**/				else if(counter < 1)
/**/					counter++;
/**/				iterations++;
/**/			}
			counter = 0;
		}
		else
			counter++;
	}	
	cout << endl <<  "Sorted in " << iterations << " iterations." << endl;
	cout <<  "-----ARRAY OF SORTED VALUES-----" << endl;
	for(int i = 0; i < arrayMAX; i++){
		cout << array[i] << " | ";
	}
	cout << endl << endl;	

	

	//goes through array and sees what is missing
	cout << "-----MISSING NUMBERS-----" << endl;
	if(array[0] == 2){
		cout << "1";
		bug++;
	}
	else if(array[0] > minReachable){
		cout << minReachable << "-" << array[0] - 1;
		bug++;
	}
	for(int i = 0; i < arrayMAX; i++){
		if(i == arrayMAX - 1){ 
			if(array[i] < maxReachable){
				if(array[i] + 1 == maxReachable)
					cout << ", " << maxReachable;
				else
					cout << ", " << array[i] + 1 << "-" << maxReachable;
			}
			else if(array[i] == maxReachable)
				cout << endl;
		}		
		else if(array[i] + 1 == array[i + 1])
			cout << "";
		else if(array[i] != array[i + 1]){
			if(bug > 0){
				cout << ", ";
			}
			if(array[i] + 2 == array[i + 1])
				cout << array[i] + 1; 
			else 
				cout << array[i] + 1 << "-" << array[i + 1] - 1;
			bug++;
		}

	}
	cout << endl << endl;
	return 0;
}
