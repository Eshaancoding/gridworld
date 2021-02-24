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

	int delay = 10000; 
	Env env = Env();
	AgentSarsa agent = AgentSarsa (action_size, gamma, step_size_param, e_greedy_probability); // 4 actions: left, right, down, up
	unsigned int episode = 0; 
	double total_reward = 0;
	unsigned int steps = 0;
	TerminalEngine engine = TerminalEngine(true, true, false);
	bool should_display = true; 
	if (!should_display) {
		engine.end();	
	}
	
	double last_total_reward = 0;
	bool exploration = true;
	bool is_done = false;
	unsigned int total_timesteps = 0;

	while (!is_done) {
		vector<double> state ({1,4}); // its the starting state
		int action = agent.get_action(state);
		
		while (true) {
			total_timesteps++;
			frame fr = env.step(action);
			vector<double> next_state = {double(fr.next_state[0]), double(fr.next_state[1])};
			int next_action = agent.get_action(next_state);
			agent.update (state, action, fr.reward, next_state, next_action);
			total_reward += fr.reward;
	
			int key; 
			if (should_display) key = engine.get_key_pressed();
			steps++;

			if (key == 'e') {
				exploration = !exploration;
				agent.set_exploration(exploration);
			}
			
			// display everything
			if (should_display) {
				string action_code = "";
				if (action == 0) action_code = "UP  ";
				if (action == 1) action_code = "DOWN";
				if (action == 2) action_code = "LEFT";
				if (action == 3) action_code = "RIGHT"; 
				engine.print("Last Total Reward: " + to_string(last_total_reward) + "                            ", 0, 3);
				engine.print("************", 0, 4);	
				for (int y = 0; y < 7; y++) {
					engine.print("*", 0, y+5);
					for (int x = 0; x < 10; x++) {
						if (state[0] - 1 == x && state[1] == 7 - y) {
							engine.print("P", x+1, y+5); 
						}
						else if (x == 7  && 7 - y == 4) {
							engine.print("G", x+1, y+5);
						}
						else {
							engine.print("-", x+1, y+5);
						}
					}	
					engine.print("*", 11, y+5); 
				}
				string clear_space = "                                                               ";
				engine.print("************", 0, 12);
				engine.print("Episodes: " + to_string(episode) + clear_space, 0, 14);
				engine.print("Steps: " + to_string(steps) + clear_space, 0, 15); 
				engine.print("Explore toggle (Press E): " + to_string(exploration) + clear_space, 0, 16);
				engine.print("Agent predict status: " + agent.predict_status + clear_space, 0, 17);
				engine.print("Total timesteps: " + to_string(total_timesteps) + clear_space, 0, 18); 
			}
			
			// update action and state
			state = next_state;
			action = next_action;
			engine.wait(delay);
			
			// if episode ends
			if (fr.done) {
				last_total_reward = total_reward;
				episode++;	
				steps = 0; 
				total_reward = 0;
				break;
			}
			
			if (should_display && key == 'b') {
				is_done = true;
				break;
			}
		}
	}
	engine.end();
	cout<<"Program terminated."<<endl;
}
