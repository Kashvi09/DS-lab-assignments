#include <iostream>
#include <stack>
using namespace std;

void nearestSmallerToLeft(int A[],int n){
	int G[100];
	stack<int> st;
	
	for(int i=0;i<n;i++){
		while(!st.empty() && st.top()>=A[i]){
			st.pop();
		}
		if(!st.empty() && st.top()<A[i]){
			G[i]=st.top();
		}
		else{
			G[i]=-1;
			st.push(A[i]);
		}
	}
	
	cout << "Nearest smaller elements: ";
    for (int i = 0; i < n; i++) {
        cout << G[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, A[100];

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    nearestSmallerToLeft(A, n);

    return 0;
}
