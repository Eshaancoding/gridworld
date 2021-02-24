#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <random>
using namespace std;

class TwoDimTable {
private:
	vector<vector<double>> inputOne;
	vector<vector<double>> inputTwo;
	vector<vector<double>> outputOne;
public:
	void setup ();
	void add (vector<double> input_one, vector<double> input_two, vector<double> output_one);  
	vector<double> get (vector<double> input_one, vector<double> input_two);
	void set (vector<double> input_one, vector<double> input_two, vector<double> output_one);
	string print_data ();
};
