AIDemo:
	@c++ -std=c++11 AIDemo.cpp src/* -lncurses -o main && ./main && rm main
AI: 
	@c++ -std=c++11 AI.cpp src/* -lncurses -o main && ./main && rm main
Manual:
	@c++ -std=c++11 Manual.cpp src/* -lncurses -o main && ./main && rm main
