#include<iostream>

using namespace std;

class node{
    public:
    int size ;
    int trigger_time;
    int node_number;
};



class simulator{
    node* node_array;
    node* time_array;
    int total_no_of_nodes;
    int total_time;
    int temp_count=0;
    int node_count =0;


    public:
    simulator(int N,int T);
    void insert(int size,int time);
    void insert(node Node);
    void delete_min();
    int l_child(int parent);
    int r_child(int parent);
    int parent(int child);
    void heapify_up(int index);
    void heapify_down(int index);
    void min();
    void simulation_start();



};