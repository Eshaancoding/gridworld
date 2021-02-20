#include <iostream>
#include <string>
#include "Table.hpp"
using namespace std;

class AgentSarsa {
private:
	double step_size_param;
 	double e_greedy_probability;
	double gamma; 
	TwoDimTable q_value;
	int action_size;
public:
	string predict_status;
	AgentSarsa (int action_size, double gamma = 1, double step_size_param = 0.5, double e_greedy_probability = 0.1);
	int get_action (vector<double> state); 
	// update q value and policy
	void update (vector<double> state, int action, double reward, vector<double> next_state, int next_action);
	string print_q ();
};
