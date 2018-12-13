#include <iostream>
#include <string>
#include <map>

using namespace std;

class Dictionary {
    public:
        int capacity;
        map <char, Dictionary> wordbook;
        void insert ( char c ) {
            //добвление элемента
            Dictionary empty_dict;
            wordbook[c] = empty_dict;
            //wordbook.insert( pair <char,Dictionary>( c, empty_dict ));
        }
        bool key_exist( char key) {
            //проверка наличия ключа на этом уровне
            if ( wordbook.find( key) != wordbook.end()) {
                return true;
            } else
                return false;
        }
        Dictionary() {
            capacity = 0;
            wordbook.clear();
        }
};
class Token {
    public:
        int length;
        string token;
        int first() {
            return token[0];
        }
        void add_to_end( char c) {
            token.push_back( c );
            ++length;
        }
        void delete_first() {
            --length;
            if ( length > 0 ) {
                short i = 0;
                while ( i < length)
                    token[i] = token[++i];
            } else
                token.clear();
        }
        void clear() {
            length = 0;
            token.clear();
        }
        Token() {
            length = 0;
            token.clear();
        }
};

bool add_element( Dictionary *dictionary, Token token ) {
    if ( token.length == 0) {
        if ( !(dictionary->key_exist( '\0' )) ) {
            dictionary->insert('\0');
            return true;
        } else
            return false;
    } else {
        if ( !(dictionary->key_exist( token.first() )) )
            dictionary->insert( token.first());
        Dictionary *invest_dict = &( dictionary->wordbook[token.first()] );
        token.delete_first();
        if (add_element( invest_dict , token ) )
            dictionary->capacity += 1;
    }
}
bool find_elemednt( Dictionary *dictionary, Token token ) {
    if ( token.length == 0)
        return dictionary->key_exist( '\0' );
    if ( dictionary->key_exist( token.first() )) {
        Dictionary *invest_dict = &( dictionary->wordbook[token.first()] );
        token.delete_first();
        return find_elemednt( invest_dict , token);
    } else
        return false;
}

void read_token( Token *token, char c ) {
    do {
        token->add_to_end( c );
    } while ( cin.get(c) && c != ' ');
    if ( c != ' ') {
        token->token.pop_back();
        token->length -= 1;
    }
}
int main() {
    return 0;
}
