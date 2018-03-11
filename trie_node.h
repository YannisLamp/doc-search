#ifndef TRIENODE
#define TRIENODE

class TrieNode {
private:
	char letter;
	TrieNode* right_ptr;
    TrieNode* down_ptr;
public:
	TrieNode(char);
	~TrieNode();

	void set_right_ptr(TrieNode*);
    void set_down_ptr(TrieNode*);

	char get_letter();
	TrieNode* get_right_ptr();
    TrieNode* get_down_ptr();
};

#endif
