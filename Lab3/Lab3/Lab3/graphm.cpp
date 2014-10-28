//---------------------------------------------------------------------------
// graphm.cpp
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
//   -- Data file data3uwb provides an additional data set for part 1{}
//      it must be edited, as it starts with a description how to use it
//---------------------------------------------------------------------------

#include "graphm.h"
#include <limits> // for representing infinity
//----------------------------------------------------------------------------
//						CONSTRUCTOR/DESTRUCTOR
//----------------------------------------------------------------------------
//Default constructor
//T initialized to all sets all dist to infinity, all visited to false, all path to 0 
GraphM::GraphM(){
	//loop horizontally and vertically to max size
	for (int currentRow = 0; currentRow < MAXNODES; currentRow++) //outer
	{
		for (int currentColumn = 0; currentColumn < MAXNODES; currentColumn++) //inner
		{
			T[currentRow][currentColumn].dist = std::numeric_limits<int>::max();
			T[currentRow][currentColumn].path = 0;
			T[currentRow][currentColumn].visited = false;
			C[currentRow][currentColumn] = std::numeric_limits<int>::max(); 
			//adjacency matrix also set to max 
		}
	}


}

//----------------------------------------------------------------------------
//						MUTATORS
//----------------------------------------------------------------------------
//builds up graph node info and adjacency matrix of edges between each node reading from a data file
void GraphM::buildGraph(ifstream& infile){
	/*-number of nodes, followed by text description of each of the 1 through n nodes, one description per line(max 50 chars)
		- after that it's 3 ints representing an edge
		- example: if edge from 1 to 2 w / label of 10 it's 1 2 10
		- a zero signifies end of data for one graph
		- may be several graphs, each having 100 nodes
		- can assume text file has correctly formatted, valid data*/
	int a = 0; 
	int b = 0; 
	int c = 0; 
	//first, read in the number of nodes into "size" 
	infile >> size;
	
	//then, loop through n of size and insert these strings into the nodedata
	for (int currentNode = 0; currentNode < size + 1; currentNode++){
		data[currentNode].setData(infile);
	}
	infile >> a >> b >> c;
	while (a != 0){
		//cout << a << b << c << endl; 
		insertEdge(a, b, c); 
		infile >> a >> b >> c;
	}

}


//----------------------------------------------------------------------------
//insert an edge into graph between two given nodes 
void GraphM::insertEdge(const int source, const int dest, const int cost){
	//do data-checking if necessary
	
	C[source][dest] = cost; 
} 


//----------------------------------------------------------------------------
//remove an edge between two given nodes
void GraphM::removeEdge(const int& source, const int& dest){
	C[source][dest] = std::numeric_limits<int>::max();
} 

//----------------------------------------------------------------------------
//find the shortest path between every node to every other node in the 
//graph, i.e., TableType T is updated with shortest path information
//This is dijkstra
void GraphM::findShortestPath(){
	int v; 
	//Develop this algorithm from pseudocode
	for (int source = 1; source <= size; source++) {
		T[source][source].dist = 0;
	// finds the shortest distance from sourceto all other nodes 
		for (int i = 1; i <= size; i++) {
			if (T[source][i].visited == false && )


				v = findNext; //find v smallest and unmarked, shortest distance
			//mark as visited
			for (w adjacent to v) {
				
				if (w is not visited){
					T[source][w].dist = min(T[source][w].dist, T[source][v].dist + C[V][W]);
			}
		}
	}
} 
//----------------------------------------------------------------------------
//set all to "not visited" 
void GraphM::initArrayVisited(){

}



//----------------------------------------------------------------------------
//						ACCESSORS
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//uses couts to demonstrate that the algorithm works properly.
void GraphM::displayAll() const{

} 
//----------------------------------------------------------------------------
//Display from/to data
void GraphM::display(const int, const int) const{

} 
//----------------------------------------------------------------------------

//Print path from/to node
void GraphM::getPath(const int, const int) const{

} 

//----------------------------------------------------------------------------
//Print descriptions
void GraphM::getPathData(const int, const int) const{

} 
//----------------------------------------------------------------------------
//Find smallest unmarked V
//----------------------------------------------------------------------------
int GraphM::findNext(TableType data[], int low, int high)
{
	return 3; 
}