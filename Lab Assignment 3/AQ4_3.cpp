#include <iostream>
#include <stack>
using namespace std;

void nearestWarmerTemp(int temp[],int n){
	int answer[100];
	stack<int> st;
	
	for(int i=n-1;i>=0;i--){
		while(!st.empty() && temp[st.top()]<=temp[i]){
			st.pop();
		}
		if(!st.empty()){
			answer[i]=st.top()-i;
		}
		else{
			answer[i]=0;
		}
		
		st.push(i);
	}
	
	cout << "Nearest greater elements: ";
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, A[100];

    cout << "Enter no. of days: ";
    cin >> n;

    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    nearestWarmerTemp(A, n);

    return 0;
}
