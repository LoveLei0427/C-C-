//�������к�Ϊĳһֵ��·��
struct BinaryTreeNode{
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};
//��Ϊû��ָ�򸸽ڵ��ָ�� ���ÿ�α���һ������ʱ��Ҫ���浽·��path��,Ȼ������жϲ����ϵľ�ɾ����

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

    //�����Ҷ�ӽ�� ���Һ�ΪexceptSum,���ӡ����·��
    bool isLeaf = root->left == nullptr && root->right == nullptr;
    if(currentSum = exceptSum && isLeaf)
    {
        pritnf("�ҵ�һ��·����");
        vector<int>::iterator iter = path.begin();
        for(; iter != path.end(); ++iter)
        {
            pritnf("%d->",*iter);
        }
    }
    //�������Ҷ�ӽ�� ����˱��������ӽ��
    if(root->left!=nullptr)
    {
        FindPath(root->left,exceptSum,path,currentSum);
    }
    if(root->right!=nullptr)
    {
        FindPath(root->right,exceptSum,path,currentSum);
    }
    //���ظ��ڵ�֮ǰ��·����ɾ����ǰ�ڵ�
    path.pop_back();

}