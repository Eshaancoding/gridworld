#include <iostream>
#include "../headers/env.hpp"

int main () {
	Env env = Env();
	int current_frame[2] = {1,4};
	cout<<"Initial frame: "<<current_frame[0]<<" "<<current_frame[1]<<endl;
	
	while (true) {
		cout<<"Action: ";
		int action;
		cin>>action;
		cout<<endl;
		if (action > 4) break;
		frame fr = env.step(action);	
		fr.print();
	}
}
