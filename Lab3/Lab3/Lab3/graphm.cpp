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

}

//----------------------------------------------------------------------------
//						MUTATORS
//----------------------------------------------------------------------------
//builds up graph node info and adjacency matrix of edges between each node reading from a data file
void GraphM::buildGraph(ifstream&){


}


//----------------------------------------------------------------------------
//insert an edge into graph between two given nodes 
void GraphM::insertEdge(const int, const int, const int){

} 


//----------------------------------------------------------------------------
//remove an edge between two given nodes
void GraphM::removeEdge(){
} 

//----------------------------------------------------------------------------
//find the shortest path between every node to every other node in the 
//graph, i.e., TableType T is updated with shortest path information
//This is dijkstra
void GraphM::findShortestPath(){
	
	//Develop this algorithm from pseudocode
	//for (int source = 1; source <= nodeSize; source++) {
	//	T[source][source].dist = 0;
	//	// finds the shortest distance from sourceto all other nodes 
	//	for (int i = 1; i <= nodeSize; i++) {
	//		find v //not visited, shortest distance at this point 
	//			mark v visited
	//		for each w adjacent to v
	//		if (w is not visited)
	//			T[source][w].dist = min(T[source][w].dist, T[source][v].dist + C[V][W])
	//	}
	//}
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