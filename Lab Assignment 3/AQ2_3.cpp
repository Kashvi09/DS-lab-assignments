#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int minEle; 

void pushStack(int x) {
    if (st.empty()) {
        st.push(x);
        minEle = x;
    }
    else if (x >= minEle) {
        st.push(x);
    }
    else {
        st.push(2 * x - minEle);
        minEle = x;
    }
}

void popStack() {
    if (st.empty()) {
        cout << "Stack is empty\n";
        return;
    }

    int t = st.top();
    st.pop();

    if (t < minEle) {
        minEle = 2 * minEle - t;
    }
}

int topStack() {
    if (st.empty()) {
        cout << "Stack is empty\n";
        return -1;
    }

    int t = st.top();
    if (t >= minEle) return t;
    else return minEle;
}

int getMin() {
    if (st.empty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return minEle;
}

int main() {
	int n;
	cout<<"Enter no. of elements in array: ";
	cin>>n;
	cout<<endl;
	
	int a[n];
	
	cout<<"Enter elements:"<<endl;
	for(int i=0; i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		pushStack(a[i]);
	}

    cout << "Current Min: " << getMin() << "\n"; // 2
    popStack();
    cout<<"One element popped from stack.\n";
    cout << "Current Min: " << getMin() << "\n"; // 3
    popStack();
    cout<<"One more element popped from stack. \n";
    cout << "Top: " << topStack() << "\n";       // 3
    cout << "Current Min: " << getMin() << "\n"; // 3

    return 0;
}

