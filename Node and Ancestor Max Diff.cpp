class Solution{
	public:
      void maxDiffHelper(Node* root,int maxEle,int &ans){
		if(root==NULL)
		return;
		ans=max(ans,maxEle-root->data);
		if(root->data>maxEle){
			maxEle=root->data;
		}
		if(root->left)
		maxDiffHelper(root->left,maxEle,ans);
		if(root->right)
		maxDiffHelper(root->right,maxEle,ans);
		return;
	}
	int maxDiff(Node* root){
		int ans=INT_MIN;
		if(root->left)
		maxDiffHelper(root->left,root->data,ans);
		if(root->right)
		maxDiffHelper(root->right,root->data,ans);
		return ans;
	}
};
