#include <iostream>
#include <stdexcept>

template <typename T>
class BinaryTree {
private:
	struct Node {
		T data;
		Node* left;
		Node* right;
		Node(const T& data) : data(data), left(nullptr), right(nullptr) {}
	};

	Node* root;

	void insert(Node*& node, const T& data) {
		if (node == nullptr) {
			node = new Node(data);
		}
		else if (data < node->data) {
			insert(node->left, data);
		}
		else {
			insert(node->right, data);
		}
	}

	void inorder(Node* node) const {
		if (node != nullptr) {
			inorder(node->left);
			std::cout << node->data << " ";
			inorder(node->right);
		}
	}

	void destroy(Node* node) {
		if (node != nullptr) {
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}

public:
	BinaryTree() : root(nullptr) {}

	~BinaryTree() {
		destroy(root);
	}

	void insert(const T& data) {
		insert(root, data);
	}

	void inorder() const {
		inorder(root);
		std::cout << std::endl;
	}
};

int main() {
	try {
		BinaryTree<int> tree;
		tree.insert(10);
		tree.insert(5);
		tree.insert(15);
		tree.insert(3);
		tree.insert(7);
		std::cout << "Inorder traversal: ";
		tree.inorder();
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}