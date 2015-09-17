//for val = 105, it calculates combinations

LL fact_arr[105][105];

void init(){
    for(int i=0;i<105;i++)
        for(int j=0;j<105;j++)
            fact_arr[i][j] = 0LL;

    for(int i=0;i<105;i++)
        fact_arr[i][0] = 1LL;

    for(int i=1;i<105;i++){
        for(int j=1;j<=i;j++){
            fact_arr[i][j] =(fact_arr[i-1][j-1] + fact_arr[i-1][j]) % 1000000007LL;
        }
    }

}
