#include <iostream> 
#include <vector>
#include "../headers/Table.hpp"
using namespace std;
int main () {
	TwoDimTable table;
	table.add({2,3,1}, {56,2123}, {2,31});
	cout<<"Array: "<<table.get({2,3,1}, {56, 2123})[0]<<" "<<table.get({2,3,1}, {56, 2123})[1]<<endl;
	table.set({2,3,1}, {56,2123}, {1,35});
	cout<<"Array: "<<table.get({2,3,1}, {56, 2123})[0]<<" "<<table.get({2,3,1}, {56, 2123})[1]<<endl;
}
