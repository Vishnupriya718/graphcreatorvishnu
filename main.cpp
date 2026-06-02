#Ainclude <iostream>
#include <vector>

using namespace std;

const int MAX = 20;

// stores vertex labels
vector<string> vertices;

// adjacency table
int adjacency[MAX][MAX];

// add a vertex
void addVertex() {
    string label;

    cout << "Enter vertex label: ";
    cin >> label;

    // add to vector
    vertices.push_back(label);

    cout << "Vertex added!\n";
}

// print vertices (for testing)
void printVertices() {

    cout << "\nVertices:\n";

    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices[i] << endl;
    }
}

int main() {

    // initialize adjacency table
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
