#include<stdio.h 
#define MAX 100

// khai bao danh sach ke
int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1;
int rear = -1;

// ham them vao hang doi
void enqueue(int value){
	if(rear == MAX -1){
		return; 
	} 
	if(front == -1){
		front = 0; 
	} 
	queue[++rear ] = value; 
}
// loai bo phan tu hang doi
void dequeue(int value){
	if(front == -1 || front > rear){
		return -1; 
	} 
	return queue[front++]; 
} 
// thuat toan
void BFSFunction(int start, int n){
	for(int i = 0; i < n; i++){
		visited[i] = 0; 
	} 
	enqueue(start);
	visited[start] = 1;
	while(front <= rear){
		int current = dequeue() 
	} 
} 
int main(){
	
} 
