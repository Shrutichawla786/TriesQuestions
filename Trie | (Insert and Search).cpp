link-->https://geeksforgeeks.org/problems/trie-insert-and-search0651/1?page=1&category=Trie&sortBy=submissions
Q.Trie | (Insert and Search)
code-->
  void insert(struct TrieNode *root, string key)
{
    // code here
    if(key.length()==0){
        root->isLeaf= true;
        return;
    }
    int index=key[0]-'a';
    struct TrieNode * child;
    if(root->children[index]!=NULL){
        child = root->children[index];
    }
    else{
        child=getNode();
        root->children[index]=child;
    }
    insert(child , key.substr(1));
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    // code here
    if(root==NULL){
        return false;
    }
    if(key.length()==0){
      return  root->isLeaf;
    }

    int index=key[0]-'a';
    struct TrieNode * child=root->children[index];
    return search(child , key.substr(1));

}
Expected Time Complexity: O(M+|search|).
Expected Auxiliary Space: O(M).
