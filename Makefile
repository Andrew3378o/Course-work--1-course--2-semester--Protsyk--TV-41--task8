
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

course_work: task8.cpp generate.cpp print.cpp utils.cpp solve.cpp
	$(CXX) $(CXXFLAGS) -o course_work task8.cpp generate.cpp print.cpp utils.cpp solve.cpp

