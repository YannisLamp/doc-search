#ifndef TRIENODE
#define TRIENODE

class TrieNode {
private:
	char letter;
	TrieNode* right_p;
    TrieNode* down_p;
public:
	TrieNode(char);
	~TrieNode();

	void set_right_p(TrieNode*);
    void set_down_p(TrieNode*);

	char get_letter();
	TrieNode* get_right_p();
    TrieNode* get_down_p();
};

#endif
