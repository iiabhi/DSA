#include <iostream>
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

Node* insert(Node* root, int val){
    if(root==NULL){
        Node* newNode = new Node(val);
        return newNode;
    }

    if(val<root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(vector<int> arr){
    Node* root= NULL;
    for(auto val: arr){
        root = insert(root, val);
    }
    return root;

}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}


bool searchBST(Node* root, int key){
    if(root == NULL) return false;
    
    if(root->data == key){
        // cout<<"Key Found"<<endl;

        return true;
    }
    if(root->data < key){
        return searchBST(root->right, key);
    }else{
        return searchBST(root->left, key);
    }
}
Node* getInorderSuccessor(Node* root){
    while(root!=NULL && root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root->data < key){
        root->right = deleteNode(root->right, key);
    }else if(root->data > key){
        root->left = deleteNode(root->left, key);
    }else{ // root->data == key
        //three case:

        //zero or one children.
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }else if (root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }else{ //2 children case
            Node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right, IS->data);

        }
    }
    return root;
}

int main()
{
    vector<int> arr = {4,1,5,2,8,6};

    Node* root = buildBST(arr);
    

    // bool isFound = searchBST(root, 2);
    // if(isFound){
    //     cout<<"Found"<<endl;
    // }else{
    //      cout<<"Not found"<<endl;
    // }
    // bool isF = searchBST(root, 3);
    // if(isF){
    //     cout<<"Found"<<endl;
    // }else{
    //      cout<<"Not found"<<endl;
    // }
    inorder(root);
    cout<<endl;

    deleteNode(root, 2);
    
    inorder(root);
    cout<<endl;




    return 0;
}