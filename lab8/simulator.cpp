#include<iostream>
#include"simulator.h"

using namespace std;

int random_byte_generator(){
    int k = (rand()%950) +50;
    return k;
}

void swap(node* a,node* b){
    node temp = *a;
    *a = *b;
    *b = temp;
}

/////////////////////////////////////////////////
simulator::simulator(int N,int T){
    total_no_of_nodes = N;
    total_time = 1000*T;
    time_array = new node[N];
    node_array = new node[N];
}

int simulator::l_child(int parent){
    int left = 2*parent+1;
    if(left<temp_count){return left;}
    else return -1;
}

int simulator::r_child(int parent){
    int right = 2*parent+2;
    if(right<temp_count){return right;}
    else return -1;
}

int simulator::parent(int child){
    if(child==0){return -1;}
    int parent = (child-1)/2;
    return parent;
}

void simulator::insert(int size,int time){
    time_array[temp_count].size = size;
    time_array[temp_count].trigger_time = time;
    time_array[temp_count].node_number = node_count;
    node_array[node_count].size = size;
    node_array[node_count].trigger_time = time;
    node_array[node_count].node_number = node_count;
    node_count++;
    temp_count++;
    heapify_up(temp_count-1);
}

void simulator::insert(node Node){
    time_array[temp_count] = Node;
    temp_count++;
    heapify_up(temp_count-1);
}

void simulator::delete_min(){
    if(temp_count ==0){return ;}
    time_array[0] = time_array[temp_count-1];
    time_array[temp_count-1].size = -1;
    time_array[temp_count-1].trigger_time = -1;
    time_array[temp_count-1].node_number = -1;
    temp_count--;
    heapify_down(0);
}

void simulator::heapify_up(int index){
    if(index>=0 &&parent(index)>=0 && (time_array[parent(index)].trigger_time > time_array[index].trigger_time)){
        swap(&time_array[index],&time_array[parent(index)]);
        heapify_up(parent(index));
    }
}

void simulator::heapify_down(int index){
    int temp1 = l_child(index);
    int temp2 = r_child(index);
    if(temp1 >= 0 && temp2 >=0 && time_array[temp1].trigger_time > time_array[temp2].trigger_time){temp1 = temp2;}
    if(temp1>=0&& time_array[index].trigger_time>time_array[temp1].trigger_time){
        swap(&time_array[index],&time_array[temp1]);
        heapify_down(temp1);
    }
}



int main(){
    int N,T;
    cout << "no of wireless nodes : " ;
    cin >> N;
    cout << "time T : " ;
    cin >> T;

}