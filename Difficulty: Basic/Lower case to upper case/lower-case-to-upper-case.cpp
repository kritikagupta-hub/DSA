
string to_upper(string str) {
    // code
    for(char &i:str){
        i=toupper(i);
    }
    return str;
}