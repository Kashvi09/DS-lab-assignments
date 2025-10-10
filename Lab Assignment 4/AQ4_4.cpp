//sandwish question

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int sandwich(queue<int>& q, stack<int>& s,int n){
	int again=1,count =0;
	int remaining=n;
	while(!s.empty() && again<=remaining){
		if(q.front()==s.top()){
			q.pop();
			s.pop();
			again=0;
			remaining--;
		}
		else{
			q.push(q.front());
			q.pop();
			again++;
		}
	}
	
	if(s.empty()){
		return 0;
	}
	else{
		while(!q.empty()){
			count++;
			q.pop();
		}
		return count;
	}
}

int main(){
	stack<int> s;
	queue<int> q;
//	int n=4;
	int n=6;
	
//	q.push(1);
//	q.push(1);
//	q.push(0);
//	q.push(0);
	
//	s.push(0);
//	s.push(1);
//	s.push(0);
//	s.push(1);
	
	q.push(1);
	q.push(1);
	q.push(1);
	q.push(0);
	q.push(0);
	q.push(0);
	
	s.push(0);
	s.push(0);
	s.push(0);
	s.push(0);
	s.push(1);
	s.push(1);
	
	int hungry=sandwich(q,s,n);
	
	cout<<hungry;
}

