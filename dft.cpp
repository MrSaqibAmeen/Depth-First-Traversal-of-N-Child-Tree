#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

/*
* struct declaration for n-child tree
*/
struct node {
	int key_value;
	vector <node*> child; //to dynamically maintain the list of childs
};

/*
* Class Declaration
*/
class btree {
public:
	btree();
	node *root;
	void insert();
	void dfs(node *leaf);
private:
	void add_child(node *&leaf);
};

int main() {
	btree newTree; 
	newTree.insert();
	newTree.dfs(newTree.root);
	return 0;
}

//null constructor 
btree::btree() {
	root = NULL;
}

void btree::insert() {	
	int root_value;
	cout << "Enter the value of the root: ";
	cin >> root_value;
	root = new node();
	root->key_value = root_value;
	add_child(root); 
}

void btree::dfs(node* leaf) {
	cout << leaf->key_value << "\t";
	for (int i = 0; i < leaf->child.size(); i++) {
		dfs(leaf->child[i]);
	}
}

// recursively add new child
void btree::add_child(node *&leaf){
	bool newEntries = false;
	char input = 'y';
	int value;
	while ( input != 'n') {
		cout << "Do you want to add children of " << leaf->key_value << " (y/n)? ";
		cin >> input; 
		if (input == 'y') {
			node *new_entry = new node();	
			cout << "Enter the value ";
			cin >> value;
			new_entry->key_value = value;
			leaf->child.push_back(new_entry);
			newEntries = true;
		}
	}
	cout << "\n";	
	
	//recursive call
	if (newEntries) {
		for (int i = 0; i < leaf->child.size(); i++) {
			add_child(leaf->child[i]);
		}
	}
}
