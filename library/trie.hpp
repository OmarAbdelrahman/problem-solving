struct trie_node_t {
  char alphabet;
  bool exist;
  std::vector<trie_node_t*> child;

  explicit trie_node_t(const char& ch): alphabet(ch), exist(false) {
    child.assign(CHARS, nullptr);
  }

  const int CHARS = 26;
};

class trie_t {
public:
  trie_t() {
    root = new trie_node_t('!');
  }

  void insert(const std::string& word) {
    const int n = static_cast<int>(word.size());
    trie_node_t* node = root;
    for (int i = 0; i < n; i++) {
      int which = word[i] - 'A';
      if (node->child[which] == nullptr) {
        node->child[which] = new trie_node_t(word[i]);
      }
      node = node->child[which];
    }
    node->exist = true;
  }

  bool search(const std::string& word) {
    const int n = static_cast<int>(word.size());
    trie_node_t* node = root;
    for (int i = 0; i < n; i++) {
      int which = word[i] - 'A';
      if (node->child[which] == nullptr) {
        return false;
      }
      node = node->child[which];
    }
    return node->exist;
  }

  bool startsWith(const std::string& prefix) {
    const int n = static_cast<int>(prefix.size());
    trie_node_t* node = root;
    for (int i = 0; i < n; i++) {
      int which = prefix[i] - 'A';
      if (node->child[which] == nullptr) {
        return false;
      }
      node = node->child[which];
    }
    return true;
  }

private:
  trie_node_t* root;
};
