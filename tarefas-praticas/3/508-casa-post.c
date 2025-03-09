typedef struct {
    int val;
    int freq;
} Result;

typedef struct {
    Result* results;
    int size;
    int maxFreq;
} Results;

Results* initResults();
void postOrderTraversal(struct TreeNode* node, Results* r);
void sumNodes(struct TreeNode* node, int* acc);
void appendResult(Results* r, int val);

int* 
findFrequentTreeSum(struct TreeNode* root, int* returnSize) 
{
    Results* r = initResults();

    postOrderTraversal(root, r);

    int j = 0;
    for ( int i = 0; i < r->size; i++ ) {
        if ( r->results[i].freq == r->maxFreq ) 
            j++;
    }

    *returnSize = j;
    int* returnArray = (int*)malloc(j * sizeof(int));

    j = 0;
    for (int i = 0; i < r->size; i++) {
        if (r->results[i].freq == r->maxFreq) {
            returnArray[j] = r->results[i].val;
            j++;
        }
    }

    free(r->results);
    free(r);

    return returnArray;
}

Results* 
initResults()
{
    Results* r = (Results*)malloc(sizeof(Results));
    
    r->results = NULL;
    r->size = 0;
    r->maxFreq = 0;

    return r;
}

void 
postOrderTraversal(struct TreeNode* node, Results* r)
{
    if ( !node ) return;

    postOrderTraversal(node->left, r);
    postOrderTraversal(node->right, r);
    
	int acc = 0;
    sumNodes(node, &acc);
    appendResult(r, acc);
}

void 
sumNodes(struct TreeNode* node, int* acc) 
{
    if ( !node ) return;

    sumNodes(node->left, acc);
    sumNodes(node->right, acc);
    *acc += node->val;
}

void 
appendResult(Results* r, int val)
{   
    for ( int i = 0; i < r->size; i++ ) {
        if ( r->results[i].val == val ) {
            r->results[i].freq++;
            if ( r->results[i].freq > r->maxFreq )
                r->maxFreq = r->results[i].freq;
            return;
        }
    }

    Result* temp = realloc(r->results, (r->size + 1) * sizeof(Result));

    r->results = temp;
    r->results[r->size].val = val;
    r->results[r->size].freq = 1;
    if (r->maxFreq < 1) 
        r->maxFreq = 1;
    r->size++;
}

