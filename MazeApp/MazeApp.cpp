// MazeApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../DataStructureLibrary/Graph.h"
#include "../DataStructureLibrary/Maze.h"

int main()
{
	Graph<std::string> graph({ "AX1", "AX2", "AX3", "AX4", "AX5" });
	
	graph.AddNodeEdges("AX1", { {"AX4", 3}, {"AX2", 2}, {"AX3", 6} });
	graph.AddNodeEdges("AX2", { {"AX1", 3}, {"AX3", 3}, {"AX4", 6} });
	graph.AddNodeEdges("AX3", { {"AX2", 3}, {"AX1", 6}, {"AX4", 4} });
	graph.AddNodeEdges("AX4", { {"AX1", 3}, {"AX2", 6}, {"AX3", 4}, {"AX5", 15} });
	graph.AddNodeEdges("AX5", { {"AX4", 15} });
	
	
	//auto result = graph.Prims();
	//auto path = std::get<0>(result);
	//auto& distance = std::get<1>(result);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
