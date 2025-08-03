#include <iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;


    }
};

//TC: O(n) where n is the size of preOrder sequence. Linear TC.
static int idx = -1;
Node* buildTree(vector<int> preOrder){
    idx++;
    if(preOrder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preOrder[idx]);

    root->left = buildTree(preOrder); //LEFT
    root->right = buildTree(preOrder); //RIGHT

    return root;

}


//Pre order (O(n)) [root, left, right.]
void preOrder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//inorder (O(n)) [left, root, right.]
void inOrder(Node* root){
    if(root == NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//postorder (o(n)) [left, right, root.]
void postOrder(Node* root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

//level order (O(n)) - one push and one pop for every n. 
void levelOrder(Node* root){
    queue<Node*> q;
    if(root == NULL){
        cout<<"Tree is empty"<<endl;
        return;
    } 
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        
        if(curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
            
        }
        cout<<curr->data<<" ";

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
        
    }
}

int height(Node* root){
    if(root == NULL) return 0;

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    return max( rightHt, leftHt) + 1;
}

int countNode(Node* root){
    if(root == NULL) return 0;

    int leftCount = countNode(root->left);
    int rightCount = countNode(root->right);

    return leftCount+rightCount+1;
}

int sumNode(Node* root){
    
    if(root == NULL) return 0;

    int leftSum = sumNode(root->left);
    int rightSum = sumNode(root->right);
   
    return leftSum+rightSum+(root->data);
}

void topView(Node* root){
    map<int, Node*> map;
    
    if(root==NULL) return;
    queue<pair<int, Node*>> q;
    q.push({0, root});
    
    while(!q.empty()){

        Node* curr = q.front().second;
        int x = q.front().first;
        q.pop();

        if(map.find(x) == map.end()){
            map[x] = curr;
        }
        

        

        if(curr->left != NULL){
            q.push({x-1, curr->left});
        }
        if(curr->right != NULL){
            q.push({x+1, curr->right});
        }

    }
    for(auto it = map.begin(); it!=map.end(); it++){
        cout<<it->second->data<<" ";
    }
    cout<<endl;
}
int transform(Node* root){
    if(root==NULL) return 0;
    int leftSum = transform(root->left);
    int rightSum = transform(root->right);
    root->data = leftSum+rightSum+root->data;
    return root->data;

}

void kthlevel(Node* root, int k){
    if(root==NULL) return;
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    kthlevel(root->left, k-1);
    kthlevel(root->right, k-1);
}

int main()
{
    vector<int> preOrderArr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrderArr);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    cout<<root->right->left->data<<endl;

    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;

    cout<<height(root)<<endl;
    cout<<countNode(root)<<endl;
    cout<<sumNode(root)<<endl;

    cout<<endl;
    topView(root);
    cout<<endl;
    kthlevel(root, 3);

    cout<<endl;
    transform(root);
    postOrder(root);
    
    return 0;
}