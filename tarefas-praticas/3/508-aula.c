typedef struct Result {
    int val;
    int freq;
} Result;

void preOrderTraversal(struct TreeNode* node, int* acc);
void sumNodes(struct TreeNode* node, int* acc);

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) 
{
    int* array = (int*)malloc(sizeof(int));
    array[0] = 5;

    Result* results;
    int results_size = 0;

    preOrderTraversal(root, results, &results_size);

    return array;
}

void preOrderTraversal(struct TreeNode* node, Result* results, int* results_size)
{
    if (!node) return;

    int acc = 0;
    sumNodes(node, &acc);
    appendResult(results, results_size, acc);
    
    preOrderTraversal(node->left, acc);
    preOrderTraversal(node->right, acc);
}

void sumNodes(struct TreeNode* node, int* acc) 
{
    if (!node) return;

    *acc += node->val;
    sumNodes(node->left, acc);
    sumNodes(node->right, acc);
}

void appendResult(Result* results, int* results_size, int val)
{
    if (*results_size == 0) {
        results[0] = (Results*)malloc(sizeof(Results));
        results[0]->val = val;
        results[0]->freq = 1;
        *results_size++;
        return;
    }

    for ( int i = 0; i < results_size; i++ ) {
        if ( resuts[i]->val == val) {
            results[i]->freq += 1;
        } else {
            results[] = (Results*)malloc(sizeof(Results));
            *results_size
        }
            
    }

}
