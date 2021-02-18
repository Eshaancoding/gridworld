#include <iostream>
#include <vector>
using namespace std;

class frame {
public:
	double reward;
	int state[2]; // playerPosX, playerPosY
	int action; // 1 = up, 2 = down, 3 = left, 4 = right
	int next_state[2]; // playerPosX, playerPosY
	bool done; // remember that if episode terminate, Q(s,a) = 0
	void print();
};

class Env {
private:
	int playerPosX;
	int playerPosY;	
public: 
	Env (); // reset variables
	frame step(int action); // exec action in env, get reward and next_state
}; 
