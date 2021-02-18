#include "TerminalEngine.cpp" 
#include <iostream>
#include "headers/env.hpp" 
#include "headers/Sarsa.hpp"
using namespace std;

int main () {
	Env env = Env();	
	TerminalEngine engine = TerminalEngine();
	vector<double> state ({1,4}); 
	double delay = 5;
	double reward; 
	while (true) {	
		vector<double> next_state;

		// if we break
		auto key = engine.get_key_pressed();
		if (key == KEY_ENTER) {
			engine.end();
			cout<<"Program terminated"<<endl;
			break;
		}
		else if (key == KEY_DOWN) {
			frame fr = env.step(2);
			next_state = {double(fr.next_state[0]), double(fr.next_state[1])}; 
			reward = fr.reward;
		} 
		else if (key == KEY_UP) {
			frame fr = env.step(1);
			next_state = {double(fr.next_state[0]), double(fr.next_state[1])}; 
			reward = fr.reward;
		}
		else if (key == KEY_RIGHT) {
			frame fr = env.step(4);
			next_state = {double(fr.next_state[0]), double(fr.next_state[1])}; 
			reward = fr.reward;
		}
		else if (key == KEY_LEFT) {
			frame fr = env.step(3); 
			next_state = {double(fr.next_state[0]), double(fr.next_state[1])}; 
			reward = fr.reward;
		}

		// display everything
		engine.print("Reward: " + to_string(reward), 0, 0);
		engine.print("Action took: " + to_string(0), 0, 1);
		engine.print("State: " + to_string(state[0]) + " " + to_string(state[1]), 0, 2); 
		engine.print("************", 0, 3);	
		for (int y = 0; y < 7; y++) {
			engine.print("*", 0, y+4);
			for (int x = 0; x < 10; x++) {
				if (state[0] - 1 == x && state[1] == 7 - y) {
					engine.print("P", x+1, y+4); 
				}
				else if (x == 7 && 7 - y == 4) {
					engine.print("G", x+1, y+4);
				}
				else {
					engine.print("-", x+1, y+4);
				}
			}	
			engine.print("*", 11, y+4); 
		}
		engine.print("************", 0, 11);
		
		// wait (so we could see our display
		engine.wait(delay);
		
		// update state
		if (next_state.size() != 0) state = next_state; 
	}
}
