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
	cout << "3. Remove Edge\n";
        cout << "4. Print Vertices\n";
	cout << "5. Print Adjacency Table\n";
        cout << "6. Quit\n";
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
	       removeEdge();
	       break
	  
            case 4:
               printVertices();
               break;

	    case 5:
	       printTable();
	       break;
		
            case 6:
               cout << "Goodbye!\n";
               break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
