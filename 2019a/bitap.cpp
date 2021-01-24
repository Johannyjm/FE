#include <iostream>
#include <string>
using namespace std;

int mask[26];

int index(char c){
    return c - 'A';
}

int generate_bitmask(string pat){
    int pat_len;
    pat_len = pat.size();
    for(int i = 0; i < 26; ++i){
        mask[i] = 0;
    }
    for(int i = 0; i < pat_len; ++i){
        mask[index(pat[i])] = (1<<i) | mask[index(pat[i])];
    }
    return pat_len;
}

int bitap_match(string text, string pat){
    int goal, status, text_len, pat_len;
    text_len = text.size();
    pat_len = generate_bitmask(pat);
    status = 0;
    goal = (1 << (pat_len-1));

    for(int i = 0; i < text_len; ++i){
        status = ((status << 1) | (1));
        status = (status & mask[index(text[i])]);

        if((status & goal) != 0){
            return (i - pat_len + 2);
        }
    }


    return -1;
}

int main(){
    string text, pat;
    cin >> text >> pat;

    cout << bitap_match(text, pat) << endl;

    return 0;
}