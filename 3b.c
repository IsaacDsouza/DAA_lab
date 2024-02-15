#include <stdio.h>
#include <string.h>

int match(char text[], char pattern[]){
    int c, d, e, text_length, pattern_length, position=-1;
    text_length = strlen(text);
    pattern_length = strlen(pattern);
    if(pattern_length>text_length)
        return -1;
    for(int i=0; c<=text_length-pattern_length;i++){
        position=e=c;
        for(d=0; d<pattern_length; d++){
            if(pattern[d]==text[e]){
                e++;
            }else{
                break;
            }
        }
        if(d==pattern_length){
            return position;
        }

    }
    return -1;
}
int main(){
    char text[] = "ababcababcabcabc";
    char pattern[] = "abc";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    match(text, pattern);

    return 0;
}

