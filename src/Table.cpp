#include "../headers/Table.hpp"

vector<double> TwoDimTable :: get (vector<double> input_one, vector<double> input_two) {
	vector<double> output; 
	// search for output
	for (int i = 0; i < this->inputOne.size(); i++) {
		if (input_one == this->inputOne[i] && input_two == this->inputTwo[i]) {
			output = this->outputOne[i];
			break;
		}
	}
	if (output.size() == 0) {
		double random_number = (rand() % 1000) / double(1000);
		this->add(input_one, input_two, {random_number});
		return {random_number};
	}
	else return output;
}

void TwoDimTable :: setup () {
	srand(time(NULL));
	this->add({8,4}, {double(0)}, {double(0)});
	this->add({8,4}, {double(1)}, {double(0)});
	this->add({8,4}, {double(2)}, {double(0)});
	this->add({8,4}, {double(3)}, {double(0)});
}

void TwoDimTable :: set (vector<double> input_one, vector<double> input_two, vector<double> output_one) {
	// search for output
	for (int i = 0; i < this->inputOne.size(); i++) {
		if (input_one == this->inputOne[i] && input_two == this->inputTwo[i]) {
			this->outputOne[i] = output_one; 
			break;
		}
	}
}

void TwoDimTable :: add (vector<double> input_one, vector<double> input_two, vector<double> output_one) {
	this->inputOne.push_back(input_one);
	this->inputTwo.push_back(input_two);
	this->outputOne.push_back(output_one);
}

string TwoDimTable :: print_data () {
	string return_data;
	return_data += "Print table: \n";
	for (int i = 0; i < this->inputTwo.size(); i++) {
		return_data += "InputOne: ";
		for (auto x : this->inputOne[i]) {
			return_data += to_string(x) + " ";
		}		
		return_data += "| InputTwo: ";
		for (auto x : this->inputTwo[i]) {
			return_data += to_string(x) + " ";
		}
		return_data += "| Output: ";
		for (auto x : this->outputOne[i]) {
			return_data += to_string(x) + " "; 
		}
		return_data += "\n";
	} 
	return_data += "Print table done \n";
	return return_data;
}
