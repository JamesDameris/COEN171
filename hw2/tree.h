#include <cstdlib>
namespace hw2 {
template <class Item>
class node {
    public:
        typedef Item value_type;
        node(Item value = 0, node<Item> *left = NULL, node<Item> *right = NULL) {
            this->left = left;
            this->right = right;
            this->value = value;
        }
        bool member(const Item& anItem) {
            if (anItem < value) {
                if (left == NULL) {
                    return false;
                }
                return left->member(anItem);
            }
            if (anItem > value) {
                if (right == NULL) {
                    return false;
                }
                return right->member(anItem);
            }
            return true;
        }
        void insert(const Item& anItem) {
            if (anItem < value) {
                if (left == NULL) {
                    left = new node<Item>(anItem);
                }
                left->insert(anItem);
            }
            if (anItem > value) {
                if (right == NULL) {
                    right = new node<Item>(anItem);
                }
                right->insert(anItem);
            }
        }

    private:
        Item value;
        node<Item> *left;
        node<Item> *right;
        
        
    
};
template <class Item>
class tree {
    public:
        tree() {
            root = NULL;
        }
        bool member(Item anItem) {
            if (root == NULL) {
                return false;
            }
            return root->member(anItem);
        }
        void insert(Item anItem) {
            if (root == NULL) {
                root = new node<Item>(anItem);
            }
            else {
                root->insert(anItem);
            }
        }
    private:
        node<Item> *root;
};
}