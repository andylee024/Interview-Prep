/*
List of common mathematical functions.

Notes:
1. fillCombinations uses specific array size (change when necessary) 
*/


/*
Creates a table of binomial coefficients using recursive formula: nCk = (n-1)C(k-1) + (n-1)C(k)
- accounts for modular choose 
*/
long long chooseTable[301][301];
void fillCombinations(long long chooseTable[][301], int M, int MOD){
	chooseTable[1][0] = 1; // initialization
	chooseTable[1][1] = 1;
	for (int n=2;n<=M;n++){
		chooseTable[n][0] = 1;
		chooseTable[n][n] = 1;
	}
	for (int n=2; n<=M; n++){ // recursive compute
		for (int k=1; k<=n; k++){
			chooseTable[n][k] = (chooseTable[n-1][k-1] % MOD) + (chooseTable[n-1][k] % MOD);
			chooseTable[n][k] %= MOD;
		}
	}
	return;
}

// modular power
long long modular_pow(long long base, long long exponent, int modulus){
	long long result = 1;
	while (exponent > 0){
		if (exponent % 2 == 1){result = (result * base) % modulus;}
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

// n choose k mod p
long long nCk_mod(int n, int k, int p){
	long long numerator = 1;
	long long denominator = 1;
	
	for (int i=0;i<k;i++){ numerator = (numerator*(n-i))%p; }
	for (int i=1;i<=k;i++){ denominator = (denominator*i)%p; }
	long long c = modular_pow(denominator, p-2, p);
	
	return (numerator * c)%p;
}

// regular choose function
long long nChoosek( long long n, long long k ){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    long long result = n;
    for( long long i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
