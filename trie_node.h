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

	void set_right(TrieNode*);
    void set_down(TrieNode*);

	char get_letter();
	TrieNode* get_right();
    TrieNode* get_down();
};

#endif
