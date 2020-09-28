/**
 * leetcode no.117
 */
 
void connect(Node* &prev, Node* &p, Node* &nextStart) {
    if (prev != nullptr) {
        prev->next = p;
    }
    prev = p;
    if (nextStart == nullptr) {
        nextStart = p;
    }
}

Node* connect(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    Node *start = root;
    while (start != nullptr) {
        Node *prev = nullptr;
        Node *nextStart = nullptr;
        for (Node *n = start; n != nullptr; n = n->next) {
            if (n->left != nullptr) {
                connect(prev, n->left, nextStart);
            }
            if (n->right != nullptr) {
                connect(prev, n->right, nextStart);
            }
        }
        start = nextStart;
    }
    return root;
}