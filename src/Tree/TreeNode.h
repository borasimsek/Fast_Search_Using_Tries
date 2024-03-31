//
// Created by bora on 31.03.2024.
//

#ifndef CS_201_PROJECT2_TREENODE_H
#define CS_201_PROJECT2_TREENODE_H


class TreeNode {
protected:
    TreeNode* left;
    TreeNode* right;
    int data;
public:
    TreeNode(int data);
    ~TreeNode();
    int getData() const;
    void setData(int data);
    TreeNode* getLeft() const;
    TreeNode* getRight() const;
    void setLeft(TreeNode* _left);
    void setRight(TreeNode* _right);
    TreeNode* recursiveSearch(int value);
    TreeNode* recursiveMinSearch();
    TreeNode* recursiveMaxSearch();
    void preorder();
    void inorder();
    void postorder();
    void prettyPrint(int level);
    void recursiveInsert(TreeNode* node);
};

#endif //CS_201_PROJECT2_TREENODE_H
