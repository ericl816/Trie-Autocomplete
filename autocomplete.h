#define SIZE 30000
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
using namespace std;

struct trieNode {
    bool isEnd;
    struct trieNode* children[SIZE]; // The array of pointers sores the references to the children of next level
};
// Create a new node and return its pointer
struct trieNode* getnode() {
    trieNode* node = new trieNode;
    node->isEnd = 0;
    for (int i=0; i<SIZE; ++i) node->children[i] = NULL;
    return node;
};
void insert (trieNode* root, const string key) {
    trieNode* crawl=root;
    for (int i=0; i<key.length(); ++i) {
        int index = CHAR_TO_INDEX(key[i]);
        if (!crawl->children[index]) crawl->children[index] = getnode();
        crawl = crawl->children[index];
    }
    crawl->isEnd = 1;
}
// To check if a node is the last node.
bool isLastNode (trieNode* root) {
    for (int i=0; i<SIZE; ++i) {
        if (root->children[i]) return 0;
    }
    return 1;
}
// To find the words below the tree in prefix (after prefix).
void suggestions (trieNode* root, string q) {
    if (root->isEnd) cout << q << "\n";
    if (isLastNode(root)) return;
    for (int i=0; i<SIZE; ++i) {
        if (root->children[i]) {
             q.push_back(i + 97);
             suggestions(root->children[i], q);
             q.pop_back();
        }

    }
}
// Crawls n levels and calls the suggestions function if the query is not he last node
int printSuggestions (trieNode* root, string q) {
    trieNode* crawl = root;
    int n=q.length();
    for (int l=0; l<n; ++l) {
        int index=CHAR_TO_INDEX(q[l]);
        if (!crawl->children[index]) return 0;
        crawl = crawl->children[index];
    }
    bool isWord = (crawl->isEnd);
    bool isLast = isLastNode(crawl);

    if (isLast && isWord) {
        cout << q << "\n";
        return -1;
    }
    if (!isLast) {
        string prefix = q;
        suggestions(crawl, prefix);
        return 1;
    }
}