#include "TerminalEngine.cpp" 
#include <iostream>
#include "headers/env.hpp" 
#include "headers/Sarsa.hpp"
using namespace std;

int main () {
	int action_size = 4;
	double gamma = 1;
	double step_size_param = 0.5;
	double e_greedy_probability = 0.1;

	Env env = Env();
	AgentSarsa agent = AgentSarsa (action_size, gamma, step_size_param, e_greedy_probability); // 4 actions: left, right, down, up
	vector<double> state ({1,4}); // its the starting state
	int action = agent.get_action(state);
	unsigned int episode = 0; 
	double total_reward = 0;
	unsigned int steps = 0;
	TerminalEngine engine = TerminalEngine(true, true, false);
	bool should_display = true; 
	if (!should_display) {
		engine.end();	
	}
	
	double last_steps;
	double total_timesteps;

	while (true) {
		frame fr = env.step(action);
		vector<double> next_state = {double(fr.next_state[0]), double(fr.next_state[1])};
		int next_action = agent.get_action(next_state);
		agent.update (state, action, fr.reward, next_state, next_action);

		int key; 
		if (should_display) key = engine.get_key_pressed();
		steps++;
		total_timesteps++;

		if (should_display && key == 'b') break;	

		// if episode ends
		if (fr.done) {
			last_steps = steps;
			episode ++;	
			steps = 0; 
		}

		// display everything
		if (should_display) {	
			engine.print("Episodes: " + to_string(episode) + "                               ", 0, 0);
			engine.print("Steps: " + to_string(steps) + "                               ", 0, 1); 
			engine.print("Last total steps: " + to_string(last_steps) + "                          ", 0, 2);
			engine.print("Total timesteps: " + to_string(total_timesteps) + "               ", 0, 3);
		}
		// update action and state
		state = next_state;
		action = next_action;
	}
	engine.end();
	cout<<"Program terminated."<<endl;
}
