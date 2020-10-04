/*Complete the function below
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
*/
struct Node* newNode(int data) 
{ 
    struct Node* node = new(struct Node); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
int maxpath(Node *root,int &sum)
    {   if(root==NULL)
    return 0;

        if(root->left==NULL && root->right==NULL)
        return root->data;
       int l=maxpath(root->left,sum);
       int r=maxpath(root->right,sum);
       if(root->left && root->right)
        {
           sum=max(sum,l+r+root->data);
           return max(l,r)+root->data;
        }
        if(root->left==NULL)
        return r+root->data;
        return l+root->data;
        
    }
int maxPathSum(struct Node *root)
{   int sum=INT_MIN;
     maxpath(root,sum);
     return sum;
}

int maxPathSum(struct Node *root) 
{ 
    int res = INT_MIN; 
    maxPathSumUtil(root, res); 
    return res; 
} 
  

int main() 
{ 
    struct Node *root = newNode(-15); 
    root->left = newNode(5); 
    root->right = newNode(6); 
    root->left->left = newNode(-8); 
    root->left->right = newNode(1); 
    root->left->left->left = newNode(2); 
    root->left->left->right = newNode(6); 
    root->right->left = newNode(3); 
    root->right->right = newNode(9); 
    root->right->right->right= newNode(0); 
    root->right->right->right->left= newNode(4); 
    root->right->right->right->right= newNode(-1); 
    root->right->right->right->right->left= newNode(10); 
    cout << "Max pathSum of the given binary tree is "
         << maxPathSum(root); 
    return 0; 
} 
