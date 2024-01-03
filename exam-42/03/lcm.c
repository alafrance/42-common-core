unsigned int    lcm(unsigned int a, unsigned int b){
    int i;

    i = 2;
    if(a == 1 && b == 1)
        return 1;
    while(1 == 1){
        if(i % a == 0 && i % b == 0)
            return i;
        i++;
    }
}