#include <iostream>
#include <string>
using namespace std;

// Browser history = Stack (LIFO: the most recent page is removed first)
class BrowserHistory {
private:
    static const int CAPACITY = 100;
    string pages[CAPACITY];
    int top;

public:
    BrowserHistory() : top(-1) {}

    bool isEmpty() const { return top == -1; }
    bool isFull() const { return top == CAPACITY - 1; }

    // Visit a new page (push)
    void visit(const string& url) {
        if (isFull()) {
            cout << "History is full.\n";
            return;
        }
        pages[++top] = url;
    }

    // Back button: remove the most recently visited page (pop)
    void back() {
        if (isEmpty()) {
            cout << "History is empty. Cannot go back.\n";
            return;
        }
        cout << "Back pressed. Removed: " << pages[top] << "\n";
        top--;
    }

    // Page currently at the top of the history (peek)
    void showTop() const {
        if (isEmpty())
            cout << "History is empty.\n";
        else
            cout << "Page currently at the top: " << pages[top] << "\n";
    }

    // Display the whole history, top page first
    void display() const {
        if (isEmpty()) {
            cout << "History is empty.\n";
            return;
        }
        cout << "History (top to bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << "  " << pages[i];
            if (i == top) cout << "   <-- top";
            cout << "\n";
        }
    }
};

int main() {
    BrowserHistory history;

    // Pages visited in this order
    history.visit("google.com");
    history.visit("youtube.com");
    history.visit("abcsc.com");
    history.visit("facebook.com");

    cout << "Initial history:\n";
    history.display();

    cout << "\n--- Back pressed first time ---\n";
    history.back();
    history.display();

    cout << "\n--- Back pressed second time ---\n";
    history.back();
    history.display();

    cout << "\n";
    history.showTop();

    return 0;
}
