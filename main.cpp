#include <limits>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 20;

// Stores all vertex labels
vector<string> vertices;

// Adjacency table for graph edges
// -1 means no edge exists
int adjacency[MAX][MAX];

// Adds a new vertex to the graph
void addVertex() {
    string label;

    cout << "Enter vertex label: ";
    cin >> label;

    // Add vertex label to vector
    vertices.push_back(label);

    cout << "Vertex added!\n";
}
// Prints all current vertices
void printVertices() {

    cout << "\nVertices:\n";

    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices[i] << endl;
    }
}

// Returns the index of a vertex label
// Returns -1 if not found
int findVertex(string label) {

    for (int i = 0; i < vertices.size(); i++) {

        if (vertices[i] == label) {
            return i;
        }
    }

    return -1;
}

// Adds a directed weighted edge
void addEdge() {

    string from;
    string to;
    int weight;

    cout << "Enter starting vertex: ";
    cin >> from;

    cout << "Enter destination vertex: ";
    cin >> to;

    cout << "Enter edge weight: ";
    cin >> weight;

    int fromIndex = findVertex(from);
    int toIndex = findVertex(to);

    // Make sure both vertices exist
    if (fromIndex == -1 || toIndex == -1) {
        cout << "Vertex not found.\n";
        return;
    }

    // Store the weight in the adjacency table
    adjacency[fromIndex][toIndex] = weight;

    cout << "Edge added!\n";
}

// Prints the adjacency table
void printTable() {

    cout << "\nAdjacency Table:\n\n";

    // Print column headers
    cout << "\t";

    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices[i] << "\t";
    }

    cout << endl;

    // Print rows
    for (int i = 0; i < vertices.size(); i++) {

        cout << vertices[i] << "\t";

        for (int j = 0; j < vertices.size(); j++) {

            if (adjacency[i][j] == -1) {
                cout << "-\t";
            }
            else {
                cout << adjacency[i][j] << "\t";
            }
        }

        cout << endl;
    }
}

// Removes an edge between two vertices
void removeEdge() {

    string from;
    string to;

    cout << "Enter starting vertex: ";
    cin >> from;

    cout << "Enter destination vertex: ";
    cin >> to;

    int fromIndex = findVertex(from);
    int toIndex = findVertex(to);

    // Make sure both vertices exist
    if (fromIndex == -1 || toIndex == -1) {
        cout << "Vertex not found.\n";
        return;
    }

    // Remove edge by setting it back to -1
    adjacency[fromIndex][toIndex] = -1;

    cout << "Edge removed!\n";
}
// Removes a vertex and all associated edges
void removeVertex() {

    string label;

    cout << "Enter vertex to remove: ";
    cin >> label;

    int index = findVertex(label);

    // Make sure vertex exists
    if (index == -1) {
        cout << "Vertex not found.\n";
        return;
    }

    int size = vertices.size();

    // Shift rows up
    for (int i = index; i < size - 1; i++) {

        for (int j = 0; j < size; j++) {
            adjacency[i][j] = adjacency[i + 1][j];
        }
    }

    // Shift columns left
    for (int j = index; j < size - 1; j++) {

        for (int i = 0; i < size - 1; i++) {
            adjacency[i][j] = adjacency[i][j + 1];
        }
    }

    // Remove vertex from vector
    vertices.erase(vertices.begin() + index);

    cout << "Vertex removed!\n";
}

// Finds the shortest path using Dijkstra's Algorithm
void shortestPath() {

    string start;
    string end;

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "Enter ending vertex: ";
    cin >> end;

    int startIndex = findVertex(start);
    int endIndex = findVertex(end);

    // Make sure both vertices exist
    if (startIndex == -1 || endIndex == -1) {
        cout << "Vertex not found.\n";
        return;
    }

    int size = vertices.size();

    vector<int> distance(size, numeric_limits<int>::max());
    vector<bool> visited(size, false);
    vector<int> previous(size, -1);

    distance[startIndex] = 0;

    // Dijkstra's Algorithm
    for (int count = 0; count < size; count++) {

        int current = -1;
        int smallest = numeric_limits<int>::max();

        // Find unvisited vertex with smallest distance
        for (int i = 0; i < size; i++) {

            if (!visited[i] && distance[i] < smallest) {
                smallest = distance[i];
                current = i;
            }
        }

        if (current == -1) {
            break;
        }

        visited[current] = true;
        // Check neighbors
        for (int i = 0; i < size; i++) {

            if (adjacency[current][i] != -1) {

                int newDistance =
                    distance[current] + adjacency[current][i];

                if (newDistance < distance[i]) {

                    distance[i] = newDistance;
                    previous[i] = current;
                }
            }
        }
    }

    // No path exists
    if (distance[endIndex] == numeric_limits<int>::max()) {
        cout << "No path exists.\n";
        return;
    }
    // Build path
    vector<int> path;

    int current = endIndex;

    while (current != -1) {

        path.push_back(current);
        current = previous[current];
    }

    cout << "\nShortest Path: ";

    for (int i = path.size() - 1; i >= 0; i--) {

        cout << vertices[path[i]];

        if (i > 0) {
            cout << " -> ";
        }
    }

    cout << "\nTotal Weight: "
         << distance[endIndex]
         << endl;
}

int main() {

    // Initialize adjacency table
    // Every position starts with -1
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adjacency[i][j] = -1;
        }
    }

    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Vertex\n";
        cout << "2. Add Edge\n";
	cout << "3. Remove Vertex\n";
	cout << "4. Remove Edge\n";
        cout << "5. Print Vertices\n";
	cout << "6. Print Adjacency Table\n";
        cout << "7. Find Shortest Path\n";
	cout << "8. Quit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                addVertex();
                break;

	    case 2:
	       addEdge();
	       break;

	    case 3:
	       removeVertex();
	       break;

	    case 4:
	       removeEdge();
	       break;
	  
            case 5:
               printVertices();
               break;

	    case 6:
	       printTable();
	       break;


	    case 7:
	       shortestPath();
	       break;

	       
            case 8:
               cout << "Goodbye!\n";
               break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    return 0;
}
