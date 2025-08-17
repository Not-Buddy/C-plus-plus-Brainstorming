#include <iostream>
#include <vector>
#include <queue>
void bfs(const std::vector<std::vector<int>> &graph, int startNode)
{
	int numVertices = graph.size();
	std::vector<bool> visited(numVertices, false);
	std::queue<int> q;

	visited[startNode] = true;
	q.push(startNode);
	std::cout<<"Starting bfs at the node:"<<startNode<<std::endl;

	while(!q.empty())
	{
		int currentNode=q.front();
		q.pop();
		std::cout<<currentNode<<" ";
		
		for(int neighbour : graph[currentNode])
		{
			if(!visited[neighbour])
			{
				visited[neighbour]=true;
				q.push(neighbour);
			}
		}

	}
	std::cout<<"\n";
}

int main() {
    // Example graph represented as an adjacency list.
    // This graph has 6 vertices (0 to 5).
    std::vector<std::vector<int>> graph = {
        {1, 2},    // Neighbors of node 0
        {0, 3, 4}, // Neighbors of node 1
        {0, 4},    // Neighbors of node 2
        {1, 5},    // Neighbors of node 3
        {1, 2, 5}, // Neighbors of node 4
        {3, 4}     // Neighbors of node 5
    };

    // Start BFS traversal from node 0.
    bfs(graph, 0);

    return 0;
}
