// Trie

#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }

    void printAllWordsWithPrefix(const std::string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return;
            }
            current = current->children[ch];
        }

        std::string currentWord = prefix;
        printAllWordsWithPrefixHelper(current, currentWord);
    }

    void printAllWordsWithPrefixHelper(TrieNode* node, std::string& currentWord) {
        if (node->isEndOfWord) {
            std::cout << currentWord << std::endl;
        }

        for (auto& child : node->children) {
            currentWord.push_back(child.first);
            printAllWordsWithPrefixHelper(child.second, currentWord);
            currentWord.pop_back();
        }
    }
};

int main()
{
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("car");
    trie.insert("carrot");

    std::cout << std::boolalpha;
    std::cout << "Search for 'apple': " << trie.search("apple") << std::endl;      // true
    std::cout << "Search for 'app': " << trie.search("app") << std::endl;          // true
    std::cout << "Search for 'apricot': " << trie.search("apricot") << std::endl;  // true
    std::cout << "Search for 'apri': " << trie.search("apri") << std::endl;        // false
    std::cout << "StartsWith 'apri': " << trie.startsWith("apri") << std::endl;    // true

    trie.printAllWordsWithPrefix("apricot");

    return 0;
}
