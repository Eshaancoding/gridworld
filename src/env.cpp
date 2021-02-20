#include "../headers/env.hpp"

void frame :: print() {
	cout<<"---------FRAME--------"<<endl;
	cout<<"Reward: "<<this->reward<<endl;
	cout<<"State: "<<this->state[0]<<" "<<this->state[1]<<endl;
	cout<<"Action taken: "<<this->action<<endl;
	cout<<"Next State: "<<this->next_state[0]<<" "<<this->next_state[1]<<endl;
	cout<<"Done: "<<done<<endl;
	cout<<"---------FRAME--------"<<endl;
	cout<<endl;
} 

Env :: Env () {
	this->playerPosX = 1; 
	this->playerPosY = 4; 
}

frame Env :: step (int action) {
	frame return_frame; 
	return_frame.done = false;	
	// store state in frame 
	return_frame.state[0] = this->playerPosX;
	return_frame.state[1] = this->playerPosY; 
	
	// store action in frame
	return_frame.action = action;
	
	// execute action
	if (action == 0) this->playerPosY += 1;
	if (action == 1) this->playerPosY -= 1;
	if (action == 2) this->playerPosX -= 1;
	if (action == 3) this->playerPosX += 1; 

	// if player is in the wind zone, playerPosY increases
	if (this->playerPosX == 4 || this->playerPosX == 5 || this->playerPosX == 6 || this->playerPosX == 9) 
		this->playerPosY += 1;
	if (this->playerPosX == 7 || this->playerPosX == 8) 
	 	this->playerPosY += 2;	

	// check if player is out of bounds
	if (this->playerPosX > 10) this->playerPosX = 10; 
	if (this->playerPosX < 1) this->playerPosX = 1; 
	if (this->playerPosY > 7) this->playerPosY = 7;
	if (this->playerPosY < 1) this->playerPosY = 1; 

	// update next_state
	return_frame.next_state[0] = this->playerPosX;
	return_frame.next_state[1] = this->playerPosY;	
	
	// determine reward
	if (this->playerPosX == 8 && this->playerPosY == 4) {
		return_frame.reward = 1;
		return_frame.done = true;	
		// reset player position.
		this->playerPosX = 1; 
		this->playerPosY = 4; 
	}
	else return_frame.reward = -1;
	
	// return frame
	return return_frame;	
}
