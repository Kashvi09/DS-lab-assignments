#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;

    Node(int val) {
        data = val;
        next = prev = up = down = NULL;
    }
};

class MatrixDLL {
public:
    Node* head;

    MatrixDLL() {
        head = NULL;
    }

    Node* construct(int mat[10][10], int rows, int cols) {
        if (rows == 0 || cols == 0) return NULL;

        Node* prevRow[10]; // stores addresses of previous row’s nodes
        for (int i = 0; i < cols; i++)
            prevRow[i] = NULL;

        for (int i = 0; i < rows; i++) {
            Node* rowHead = NULL;
            Node* prevNode = NULL;

            for (int j = 0; j < cols; j++) {
                Node* newNode = new Node(mat[i][j]);

                // Connect horizontally (left-right)
                if (prevNode != NULL) {
                    prevNode->next = newNode;
                    newNode->prev = prevNode;
                }

                // Connect vertically (up-down)
                if (i > 0 && prevRow[j] != NULL) {
                    newNode->up = prevRow[j];
                    prevRow[j]->down = newNode;
                }

                // Store for next iteration
                prevRow[j] = newNode;

                if (j == 0)
                    rowHead = newNode;

                prevNode = newNode;
            }

            // Set list head as first row’s first element
            if (i == 0)
                head = rowHead;
        }

        return head;
    }

    void display() {
        Node* row = head;
        while (row != NULL) {
            Node* col = row;
            while (col != NULL) {
                cout << col->data << " ";
                col = col->next;
            }
            cout << endl;
            row = row->down;
        }
    }
};

int main() {
    int mat[10][10] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rows = 3, cols = 3;

    MatrixDLL list;
    Node* head = list.construct(mat, rows, cols);

    cout << "4-way Doubly Linked List Representation:\n";
    list.display();

    return 0;
}

