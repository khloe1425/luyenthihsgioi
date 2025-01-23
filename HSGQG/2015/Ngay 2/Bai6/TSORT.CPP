#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc cây nhị phân
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Hàm xây dựng cây nhị phân từ hoán vị
Node* buildTree(const vector<int>& permutation, int start, int end) {
    if (start > end) return nullptr;
    int maxIndex = start;
    for (int i = start + 1; i <= end; i++) {
        if (permutation[i] > permutation[maxIndex]) maxIndex = i;
    }
    Node* root = new Node(permutation[maxIndex]);
    root->left = buildTree(permutation, start, maxIndex - 1);
    root->right = buildTree(permutation, maxIndex + 1, end);
    return root;
}

// Hàm duyệt cây theo thứ tự đặc biệt
void traverseTree(Node* root, vector<int>& result) {
    if (!root) return;
    traverseTree(root->left, result);
    traverseTree(root->right, result);
    result.push_back(root->value);
}

// Hàm kiểm tra tính chất TSort
bool isTSort(const vector<int>& permutation, const vector<int>& treeOrder) {
    return permutation == treeOrder;
}

int main() {
    ifstream input("TSORT.INP");
    ofstream output("TSORT.OUT");

    int n, k;
    input >> n >> k;

    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        input >> permutation[i];
    }

    vector<int> sortedPermutation = permutation;
    sort(sortedPermutation.begin(), sortedPermutation.end());

    int countTSort = 0;
    for (int i = 0; i < k; i++) {
        vector<int> currentPermutation = permutation;
        Node* root = buildTree(currentPermutation, 0, n - 1);
        vector<int> treeOrder;
        traverseTree(root, treeOrder);
        if (isTSort(sortedPermutation, treeOrder)) {
            countTSort++;
        }
        next_permutation(permutation.begin(), permutation.end());
    }

    output << countTSort << endl;

    input.close();
    output.close();

    return 0;
}
