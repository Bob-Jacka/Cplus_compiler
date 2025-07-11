#include "../declaration/Parser.hpp"
/**
 * The first time we call GetInstance we will lock the storage location,
 *      and then we make sure again that the variable is null, and then we
 *      set the value. RU:
 */
Parser *Parser::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == null) {
        pinstance_ = new Parser();
    }
    return pinstance_;
}

/*
Method that aggregates syntax tree actions
*/
None Parser::build_tree() const {
    //
}

/*
Method that reacts on keyword tokens
*/
None Parser::react_on_keyword() const {
    //
}

/*
Method that reacts on int val token
*/
None Parser::react_on_intval() const {
    //
}

/*
Method that reacts on string val token
*/
None Parser::react_on_stringval() const {
    //
}

/*
Method that reacts on float val token
*/
None Parser::react_on_floatval() const {
    //
}

/*
Method that reacts on operator token
*/
None Parser::react_on_operator() const {
    //
}

/*
Method that reacts on value identifier token
*/
None Parser::react_on_identifier() const {
    //
}

/*
Entry point of the parser
*/
std::vector<Token> *Parser::parse_tokens(std::vector<Token> *) const {
    //
    return null;
}
