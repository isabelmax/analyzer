// PARAM: --set ana.activated "['base']" --set ana.int.interval true --set ana.int.trier true --set ana.int.queries true --set ana.int.relational true --set ana.int.equations true --set ana.int.queries true --set ana.structs.relational true --set ana.structs.relational_to_analyze "['S']"
typedef struct  {
    int i;
    int k;
    
} S;

S some_function(){
    S xx;
    xx.i = 5;
    xx.k = 5;
    S yy;
    yy.i = 7;
    int z;
    if (xx.i != 0){
        yy.i = 8;
        xx.k = 9;
    } else {
        yy.i = 9;
        xx.k = 8;
    }

    assert(xx.k<10);
    assert(xx.k<=9);
    assert(!(xx.k<8));
    assert(xx.k==8);//FAIL
    return xx;
}

int main(){
    S a;
    a.i = 5;
    a.k = 7;
    a = some_function();
    return a.i;
}