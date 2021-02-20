#include "../headers/Table.hpp"

TwoDimTable q_value;
int action_size = 4;
double e_greedy_probability = 0.1;
string predict_status;

int get_action (vector<double> state) {
	int action_return = -numeric_limits<int>::infinity(); 
	double q_value_return = -numeric_limits<double>::infinity();
	vector<int> action_repeats;
	
	for (int i = 0; i < action_size; i++) {
		bool is_avaliable = true;
		vector<double> prediction;
		try {
			prediction = q_value.get(state, {double(i)});
		} catch (...) {
			// state is not avaliable in q_value
			is_avaliable = false;
		}
		if (is_avaliable) {
			// state is avaliable in q_value
			if (prediction[0] > q_value_return) {
				// we have a better q_value a.k.a better action
				action_return = i;
				q_value_return = prediction[0];
				action_repeats = {i};	
			} 
			else if (prediction[0] == q_value_return) {
				// ties broken randomly
				action_repeats.push_back(i);
			}
			predict_status = "GREEDY"; 
		} else {
			q_value.add(state, {double(i)}, {0});
			q_value_return = 0; 
			action_repeats = {i};
			action_return = rand() % action_size;
			predict_status = "RANDOM BECAUSE NOT IN TABLE";
		}
	} 

	// if there is action repeats, then ties are broken randomly 
	if (action_repeats.size() > 1) {
		int random_action = rand() % action_repeats.size(); 
		action_return = action_repeats[random_action]; 
		predict_status = "GREEDY TIES BROKEN RANDOMLY";
	}	

	// with random probability e, we choose random action (for exploration) 
	int deciding = rand() % 100;
 	if (deciding <= (e_greedy_probability * 100)) {
		// explore	
		predict_status = "RANDOM BECAUSE OF EXPLORATION"; 
		return rand() % action_size;
	} else {
		return action_return;
	}
}
