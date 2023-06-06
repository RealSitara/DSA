/*
Consider a scenario for Hospital to cater services to different kinds of patients as Serious
(top priority), b) non-serious (medium priority), c) General Checkup (Least priority).
Implement the priority queue to cater services to the patients.
*/
#include<iostream>
#include<queue>
#include<string>

using namespace std;

class Patient{
	public :
		string name;
		int priority;
		
		Patient(string n,int p){
			name=n;
			priority=p;
		}
		
		bool operator<(const Patient& other)const{
			return priority > other.priority;
		}
};

int main(){
	priority_queue<Patient> hospitalqueue;
	
	char ch='y';
	string n;
	int p;
	do{
		cout<<"\nEnter patient name : ";
		cin>>n;
		cout<<"\nEnter severity of patient :\n1.Serious\n2.Non-Serious\n3.General Checkup\nEnter the choice : ";
		cin>>p;
		hospitalqueue.push(Patient(n,p));
		cout<<"\nRecord for "<<n<<" is inserted ! ";
		cout<<"\nEnter y or Y to countinue\nEnter n or N to print list : ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	
	cout<<"\n--------------:Serving Patient list:--------------\n";
	while(!hospitalqueue.empty()){
		Patient pat=hospitalqueue.top();
		hospitalqueue.pop();
		
		string pri;
		
		if(pat.priority==1){
			pri="Serious";
		}
		else if(pat.priority==2){
			pri="Non-Serious";
		}
		else{
			pri="General checkup";
		}
		//cout<<"\n"<<pri;
		cout<<"\nPatient Name : "<<pat.name<<", Priority : "<<pri;
	}
	
	return 0;
}
