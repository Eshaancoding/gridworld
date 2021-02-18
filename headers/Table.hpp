#include <iostream>
#include <vector>
using namespace std;

class TwoDimTable {
private:
	vector<vector<double>> inputOne;
	vector<vector<double>> inputTwo;
	vector<vector<double>> outputOne;
public:
	void add (vector<double> input_one, vector<double> input_two, vector<double> output_one);  
	vector<double> get (vector<double> input_one, vector<double> input_two);
	void set (vector<double> input_one, vector<double> input_two, vector<double> output_one);
};
