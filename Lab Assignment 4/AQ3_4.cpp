//sorting first n natural numbers using 2 queues and a stack

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool canArrange(queue<int>& q1){
	stack<int> s;
	queue<int> q2;
	int expected=1;
	int top;
	
	while(!q1.empty()){
		top=q1.front();
		q1.pop();
		
		s.push(top);
		
		while(!s.empty() && s.top()==expected){
			q2.push(s.top());
			s.pop();
			expected++;
		}
	}
	
	while(!s.empty()){
		if(s.top()!=expected){
			return false;
		}
		
		q2.push(s.top());
		s.pop();
		expected++;
	}
	return true;
}

int main(){
	queue<int> q;
	
	q.push(5);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	
	//3,1,4,2 -> No
	
	bool canArr=canArrange(q);
	
	if(canArr){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	
	return 0;
}
