# 🙌 Depth First Traversal of N-Child Tree
Depth first traversal algorithm is implemented on n-child tree in C++. It was a lab task. The main purpose was the implementation of the Depth First Traversal which can be extended easily to implement depth first search. 



## N-Child Tree
To generate n-child tree, it uses the followig data structure:
```
struct node {
	int key_value;
	vector <node*> child; 
};
```
`vector <node*> child` is used to dynamically maintain the list of the childs of tree.
It contains only insert function for the n-child tree. However, it can be extended further for to provide following features:
* Insertion (Currently, it takes input at one time only)
* Deletion 
* Search
* Memory Management
## 🍕Depth First Traversal
Instead of using the stack to implement depth first traversal, I used a recursive function to implement this.
```
void btree::dfs(node* leaf) {
	cout << leaf->key_value << "\t";
	for (int i = 0; i < leaf->child.size(); i++) {
		dfs(leaf->child[i]);
	}
}
```
`btree` is the class name implementing the n-tree structure. 
## ⚙ Working
On executing the dft.cpp files, it asks for the value of the root and it's child recursively. It does not perform any check on the input. Simply add the values in the order you input the file.

Once you have entered the numbers, it prints the numbers in depth first manner. 🎉
Following screenshot shows the working on sample input.

![Sample Working Screenshot](https://github.com/MrSaqibAmeen/Depth-First-Traversal-of-N-Child-Tree/blob/master/result.PNG)

## License
Licenced Under GPL 2.0. 
