/*
Class used for building syntax tree.
Get stream from lexer and build syntax tree;
*/

#include <mutex>

class Parser {
    static Parser *pinstance_;
    static std::mutex mutex_;

    //methods for react on different tokens
    void react_on_keyword() const;

    void react_on_intval() const;

    void react_on_stringval() const;

    void react_on_floatval() const;

    void react_on_operator() const;

    void react_on_identifier() const;

public:
    Parser() = default;

    ~Parser() = default;

    Parser(Parser &other) = delete;

    void operator=(const Parser &) = delete;

    static Parser *GetInstance();

    void build_tree() const;

    std::vector<Token> *parse_tokens(std::vector<Token> *) const; //Entry point of the Parser
};

Parser *Parser::pinstance_{nullptr};
std::mutex Parser::mutex_;

/**
 * The first time we call GetInstance we will lock the storage location,
 *      and then we make sure again that the variable is null, and then we
 *      set the value. RU:
 */
Parser *Parser::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new Parser();
    }
    return pinstance_;
}

/*
Method that aggregates syntax tree actions
*/
void Parser::build_tree() const {
    //
}

/*
Method that reacts on keyword tokens
*/
void Parser::react_on_keyword() const {
    //
}

/*
Method that reacts on int val token
*/
void Parser::react_on_intval() const {
    //
}

/*
Method that reacts on string val token
*/
void Parser::react_on_stringval() const {
    //
}

/*
Method that reacts on float val token
*/
void Parser::react_on_floatval() const {
    //
}

/*
Method that reacts on operator token
*/
void Parser::react_on_operator() const {
    //
}

/*
Method that reacts on value identifier token
*/
void Parser::react_on_identifier() const {
    //
}

/*
Entry point of the parser
*/
std::vector<Token> *Parser::parse_tokens(std::vector<Token> *) const {
    //
    return nullptr;
}
