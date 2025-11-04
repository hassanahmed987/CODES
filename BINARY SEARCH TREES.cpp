#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int da) {
        data = da;
        left = right = nullptr;
    }
};

node* insertinbst(node* root, int d) {
    if (root == nullptr) {
        root = new node(d);
        return root;
    }
    if (d > root->data) {
        root->right = insertinbst(root->right, d);
    }
    if (d < root->data) {
        root->left = insertinbst(root->left, d);
    }
    return root;
}

void takeinput(node*& root) {
    int val;
    cin >> val;
    while (val != -1) {
        root = insertinbst(root, val);
        cin >> val;
    }
}

void inorder(node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(node* root) {
    if (root == nullptr) return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
    }
    cout << endl;
}

bool search(node* root, int x) {
    if (root == nullptr) {
        cout << "not found" << endl;
        return false;
    }
    if (root->data == x) {
        cout << "found" << endl;
        return true;
    }
    if (root->data > x) {
        return search(root->left, x);
    } else {
        return search(root->right, x);
    }
}

node* min(node* root) {
    node* temp = root;
    while (temp && temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}

node* max(node* root) {
    node* temp = root;
    while (temp && temp->right != nullptr) {
        temp = temp->right;
    }
    return temp;
}

void findpresuc(node* root, node*& pre, node*& suc, int key) {
    if (root == nullptr) {
        return;
    }

    if (root->data == key) {
        if (root->left) {
            pre = max(root->left);
        }
        if (root->right) {
            suc = min(root->right);
        }
    } else if (root->data < key) {
        pre = root;
        findpresuc(root->right, pre, suc, key);
    } else {
        suc = root;
        findpresuc(root->left, pre, suc, key);
    }
}

node* delnode(node* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data == val) {
        if (root->right == nullptr && root->left == nullptr) {
            delete root;
            return nullptr;
        } else if (root->right == nullptr && root->left != nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        } else if (root->left == nullptr && root->right != nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->left != nullptr && root->right != nullptr) {
            int mini = min(root->right)->data;
            root->data = mini;
            root->right = delnode(root->right, mini);
            return root;
        }
    } else if (root->data > val) {
        root->left = delnode(root->left, val);
        return root;
    } else {
        root->right = delnode(root->right, val);
        return root;
    }

    return root;
}

int main() {
    node* root = nullptr;
    takeinput(root);

    cout << "Max value is: " << max(root)->data << endl;
    cout << "Min value is: " << min(root)->data << endl;

    return 0;
}
