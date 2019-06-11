//二叉树中和为某一值得路径
struct BinaryTreeNode{
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};
//因为没有指向父节点的指针 因此每次遍历一个结点的时候都要保存到路径path中,然后求和判断不符合的就删除。

void FindPath(BinaryTreeNode *root,int exceptSum)
{
    if(root == nullptr)
        return;
    if(root -> value == exceptSum)
        print("%d->",root->value);
    vector<int>path;
    int currentSum = 0;
    FindPath(root,exceptSum,path,currentSum);
}

void FindPath(BinaryTreeNode *root, int exceptSum, vector<int>&path, int currentSum)
{
    currentSum += root -> value;
    path.push_back(root->value);

    //如果是叶子结点 并且和为exceptSum,则打印这条路径
    bool isLeaf = root->left == nullptr && root->right == nullptr;
    if(currentSum = exceptSum && isLeaf)
    {
        pritnf("找到一条路径：");
        vector<int>::iterator iter = path.begin();
        for(; iter != path.end(); ++iter)
        {
            pritnf("%d->",*iter);
        }
    }
    //如果不是叶子结点 则因此遍历它的子结点
    if(root->left!=nullptr)
    {
        FindPath(root->left,exceptSum,path,currentSum);
    }
    if(root->right!=nullptr)
    {
        FindPath(root->right,exceptSum,path,currentSum);
    }
    //返回父节点之前在路径上删除当前节点
    path.pop_back();

}