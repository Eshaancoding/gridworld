## SARSA: Windy Gridworld

I am going to attempt to implement on-policy Sarsa to solve the task Windy Gridworld, a task detailed in page 130 from the Introduction to Reinforcement Learning by Sutton & Barto. The Sarsa algorithm is also detailed in that page. 

Both policies are stochastic, but overtime both become of the policies will become deterministic. Therefore, the two policies should be e-greedy policies. This will ensure exploration. e-greedy policies are described in page 100.

To run the algorithm, type `make AI` in the linux terminal. It will then show you the Episodes, Steps, Last total steps, and the total timesteps. Pay close attention to the "Last total steps", as that will tell how many timesteps the agent (a.k.a the computer) had to take to reach the goal state. If that number is around 15-20 after ~8000 total timesteps, the agent has successfully been trained on the environment. Simply hit `b` to break the program. 

You could also run the algorithm to see how the computer plays. Type `make AISim` in your linux terminal. This will show you the Last total reward, the total timesteps, the episode, the steps, the explore toggle, and the game itself. If the simulation is too fast, simply increase the `delay` variable (in milliseconds) in `AISim.cpp`. You could hit `b` to end the program (you may need to press it multiple times). You could use the explore toggle, which will decide whether the agent should look and execute new actions. The explore toggle is usually switched off (0 = off, 1 = on in the simulation) after it has been trained for a decent amount of timesteps. If the computer does not explore at beginning of training, the computer will do fairly poor at the environment. The agent should be trained after ~8000 total timesteps.

If you have any question, you are welcome to email me at eshaanbarkataki@gmail.com
