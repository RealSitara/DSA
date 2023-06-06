/*
There are flight paths between cities. If there is a flight between city A and city B then
there is an edge between the cities. The cost of the edge can be the time that flight take to
reach city B from A, or the amount of fuel used for the journey. Represent this as a graph.
The node can be represented by airport name or name of the city. Use adjacency list
representation of the graph or use adjacency matrix representation of the graph. Check
whether the graph is connected or not. Justify the storage representation used.
*/
#include<iostream>
using namespace std;

int main(){
	int n;
	int adjmat[20][20]={0,0};
	
	cout<<"\nEnter how many cities you want to enter ? ";
	cin>>n;
	string city[n];
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter City Name "<<i+1<<" : ";
		cin>>city[i];
	}
	
	for(int i=0;i<n;i++){
		
		for(int j=i+1;j<n;j++){
			/*if(city[i]==city[j]){
				continue;
			}*/
			cout<<"\nEnter the distance between "<<city[i]<<" and "<<city[j]<<" : ";
			cin>>adjmat[i][j];
			adjmat[j][i]=adjmat[i][j];
		}
	}
	cout<<"\n\n----Displaying the Adjacency Matrix----\n\n";
	for(int i=0;i<n;i++){
		cout<<"\t\t"<<city[i];
	}
	cout<<"\n";
	for(int i=0;i<n;i++){
		cout<<city[i];
		for(int j=0;j<n;j++){
			cout<<"\t\t"<<adjmat[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n\n----Displaying the Adjacency list----\n\n";
	for(int i=0;i<n;i++){
		cout<<city[i];
		for(int j=0;j<n;j++){
			if(adjmat[i][j]==0){
				continue;
			}
			cout<<" --> "<<city[j]; //<<adjmat[i][j];
		}
		cout<<"\n";
	}
	return 0;
}
