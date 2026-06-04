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
        cout << "3. Print Vertices\n";
        cout << "4. Quit\n";
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
                printVertices();
                break;

            case 4:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
