#include "../headers/Sarsa.hpp"

AgentSarsa :: AgentSarsa (int action_size, double gamma, double step_size_param, double e_greedy_probability) {
	this->action_size = action_size;
	this->step_size_param = step_size_param;
	this->e_greedy_probability = e_greedy_probability;
	this->gamma = gamma;
	srand(time(NULL)); 
} 

int AgentSarsa :: get_action (vector<double> state) {
	int action_return; 
	double q_value_return;
	vector<double> action_repeats;

	for (int i = 0; i < this->action_size; i++) {
		try {
			vector<double> prediction = this->q_value.get(state, {double(i)});
			// state is avaliable in q_value
			if (prediction[0] > q_value_return) {
				// we have a better q_value a.k.a better action
				action_return = i;
				q_value_return = prediction[0];
				action_repeats = {double(i)}; 	
			} 
			if (prediction[0] == q_value_return) {
				// ties broken randomly
				action_repeats.push_back(i);
			}
			predict_status = "GREEDY";
		} catch (...) {
			// state is not avaliable in q_value 
			this->q_value.add(state, {double(i)}, {0});
			q_value_return = 0; 
			action_repeats = {double(i)};
			action_return = rand() % this->action_size;
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
 	if (deciding <= (this->e_greedy_probability * 100)) {
		// explore
		return rand() % this->action_size;
		predict_status = "RANDOM BECAUSE OF EXPLORATION"; 
	} else {
		return action_return;
	}

	// return
	return action_return;
}

void AgentSarsa :: update (vector<double> state, int action, double reward, vector<double> next_state, int next_action) {
	double q_s_a = this->q_value.get(state, {double(action)})[0]; 
	double q_future;
	try {
		q_future = this->q_value.get(state, {double(action)})[0];
	} catch (...) {
		q_future = 0;
	} 
	double set_q = q_s_a + this->step_size_param * (reward + (this->gamma * q_future) - q_s_a);
	this->q_value.set(state, {double(action)}, {set_q}); 
}