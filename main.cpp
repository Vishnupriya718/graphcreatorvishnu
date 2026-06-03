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
        cout << "2. Print Vertices\n";
        cout << "3. Quit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                addVertex();
                break;

            case 2:
                printVertices();
                break;

            case 3:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
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
