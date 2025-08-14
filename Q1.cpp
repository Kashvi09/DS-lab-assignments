#include<iostream>
using namespace std;

const int Max=100;
int a[Max];

int create(int a[],int n){
    

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter element:";
        cin>>a[i];
    }

    return a[n];
    
}

void display(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\n";
    }
}

int insert(int a[],int n){
	int pos,ele;
	cout<<"Enter position for insertion:";
	cin>>pos;
	
	if(pos>n){
		cout<<"Position exceeds length of array!!!";
	}
	else{
		cout<<"Enter element:";
		cin>>ele;
		for(int i=n;i>pos-1;i--){
			a[i]=a[i-1];
		}
		a[pos-1]=ele;
		return n+1;
	}
}

int deletele(int a[],int n){
	int pos,ele;
	cout<<"Enter position for deletion:";
	cin>>pos;
	
	if(pos>n){
		cout<<"Position exceeds length of array!!!";
	}
	else{
		for(int i=pos-1;i<n-1;i++){
			a[i]=a[i+1];
		}
		return n-1;
	}
}

void linsearch(int a[],int n){
	int ele,i,flag=0;
	if(n==0){
		cout<<"Array is empty!!!";
	}
	else{
		cout<<"Enter element to be searched:";
		cin>>ele;
		
		for(i=0;i<n;i++){
			if(a[i]==ele){
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<"Element not found!\n";
		}
		else{
			cout<<"Element is at "<<i+1<<" position.\n";
		}
	}
}

int main() {
    int n,choice;
    char ans='y';

    cout<<"Enter no. of elements:\n";
    cin>>n;
    
	do {
		cout << "MENU\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
            
    
        switch(choice) {
            case 1: 
            create(a,n);
            break;

            case 2: 
			display(a,n); 
			break;
            
			case 3: 
			n=insert(a,n); 
			break;
                 
		    case 4: 
			n=deletele(a,n); 
			break;
                 
			case 5: 
			linsearch(a,n); 
			break;
            
			case 6: 
			cout << "Exiting program.\n"; 
			break;
            
			default: 
			cout << "Invalid choice. Please try again.\n";
            }
            
			if (choice != 6) {
			cout << "Do you wish to continue (y/n): ";
			cin >> ans;
        }
    } while (choice != 6 && ans == 'y');
    return 0;

}
