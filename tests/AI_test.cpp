#include "../headers/Sarsa.hpp"
#include "../headers/env.hpp"

int main () {
	AgentSarsa agent = AgentSarsa(4);
	// we have get_action, already tested
	// test update
	// make sure to test every if or for loop
	agent.update({3.2,2.1}, 0, 3, {3.3, 2.2}, 0); // took the same action twice
	cout<<agent.print_q();	
	agent.update({3.3,2.2}, 0, -3, {3.4, 2.3}, 0); // same thing but got different reward
	cout<<agent.print_q();
	agent.update({3.2,2.1}, 0, 2.21, {3.3, 2.2}, 0); // took the same action twice
	cout<<agent.print_q();
}
