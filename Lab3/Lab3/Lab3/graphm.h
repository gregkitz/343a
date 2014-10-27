//---------------------------------------------------------------------------
// graphm.h
// Greg Kitzmiller
// Lab 3 - Dijykstra's Shortest Path Algorithm Implementation 
//---------------------------------------------------------------------------
// This GraphM class implements of connected nodes with weights. 
// It contains methods to build, destruct, and modify graphs. 
// It also can find the shortest distance (weight) between nodes and output
// Dijkstra's algorithm in action. It also has output functionality to 
// output all paths or specific shortest paths. 
//
// Assumptions:
//   -- A valid data file is supplied. 
//   -- text files "data31.txt" and "data32.txt" are formatted as described 
//   -- Data file data3uwb provides an additional data set for part 1;
//      it must be edited, as it starts with a description how to use it
//---------------------------------------------------------------------------


#ifndef _GRAPHM_H
#define _GRAPHM_H_
#include "nodedata.h"

const int MAXNODES = 100; 

class GraphM {
private:
	struct TableType {
		bool visited; //whatever node has been visited	
		int dist;  //shortest distance from source known so far
		int path; //previous node on the path of min dist
	};

	NodeData data[MAXNODES]; // data for graph nodes
	int C[MAXNODES][MAXNODES]; // Cost array, the adjacency matrix
	int size; // number of nodes in the graph
	TableType T[MAXNODES][MAXNODES]; //stores visited distance path 


public: 
	//Default constructor
	//T initialized to all sets all dist to infinity, all visited to false, all path to 0 
	GraphM(); //default constructor
	void buildGraph(ifstream&); //insert data
	
	void insertEdge(const int, const int, const int); // insert an edge into graph between two given nodes 
	void removeEdge(); //remove an edge between two given nodes
	void findShortestPath(); //find the shortest path between every node to every other node in the 
		//graph, i.e., TableType T is updated with shortest path information
	void displayAll() const; //uses couts to demonstrate that the algorithm works properly.
	void display(const int, const int) const; //Display from/to data
	void initArrayVisited(); //set all to "not visited" 
	void getPath(const int, const int) const; //Print path from/to node
	void getPathData(const int, const int) const; //Print descriptions
	int findNext(TableType[], int, int); //helper - find sallest unmarked V

	

};
#endif