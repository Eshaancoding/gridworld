#include "TerminalEngine.cpp" 
#include <iostream>
#include "headers/env.hpp" 
#include "headers/Sarsa.hpp"
using namespace std;

int main () {
	Env env = Env();
	AgentSarsa agent = AgentSarsa (4); // 4 actions: left, right, down, up
	vector<double> state ({1,4}); // its the starting state
	int action = agent.get_action(state);
	unsigned int episode = 0; 
	double total_reward = 0;
	unsigned int steps = 0;
	TerminalEngine engine = TerminalEngine(false, true, false);

/* 
	Look at current_state and next_state variables. Something is weird here
*/


	
	while (true) {
		frame fr = env.step(action);
		vector<double> next_state = vector<double>(fr.next_state[0], fr.next_state[1]);
		int next_action = agent.get_action(next_state);
		agent.update (state, action, fr.reward, next_state, next_action);
		total_reward += fr.reward;
	
		auto key = engine.get_key_pressed();
		steps++;
	
		// if episode ends
		if (fr.done) {
			episode ++;	
			steps = 0; 
			total_reward = 0;
		}

		// display everything
		string action_code = "";
		if (action == 1) action_code = "UP  ";
		if (action == 2) action_code = "DOWN";
		if (action == 3) action_code = "LEFT";
		if (action == 4) action_code = "RIGHT"; 
		engine.print("Reward: " + to_string(fr.reward), 0, 0);
		engine.print("Action took: " + action_code, 0, 1);
		engine.print("State: " + to_string(state[0]) + " " + to_string(state[1]), 0, 2); 
		engine.print("Next state: " + to_string(fr.next_state[0]) + " " + to_string(fr.next_state[1]), 0, 3);
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
		engine.print("************", 0, 12);
		engine.print("Action status: " + agent.predict_status + "                                ", 0, 13);
		engine.print("Episodes: " + to_string(episode), 0, 14);
		engine.print("Steps: " + to_string(steps), 0, 15); 
		// update action and state
		state = next_state;
		action = next_action;
	}
}
