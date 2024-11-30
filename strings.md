- Strings are immutable in programming languages like Java, Python, JavaScript and C#.
- `std::string::npos`, It is a constant static member value with the highest possible value for an element of type size_t.
- We consider the lexicographic order of characters as their order of ASCII value.
` ‘A’, ‘B’, ‘C’, …, ‘Y’, ‘Z’, ‘a’, ‘b’, ‘c’, …, ‘y’, ‘z’. `


# KMP Algorithm
- Used to find a pattern within large texts efficiently.
- Uses the structure of the pattern to avoid redundant comparisons
- Longest Prefix Suffix (lps) array : How much pattern can be reused ? -> Longest Proper Prefix which is also a Suffix.

```cpp

/*
TC -> O(m+n)
SC -> O(m)
*/
void computeLPS(vector<int> &lps, string &p){
    int len = 0, i=1, n=p.size();
    lps[len] = 0;
    while(i < n){
        if(p[i] == p[len]){
            len++;
            lps[i] = len;
            i++;
        }else if(p[i] != p[len]){
            if(len > 0){ 
                len = lps[len - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool kmp_find(string &s, string &p){
    int n = s.size(), m=p.size(), i=0, j=0;
    vector<int> lps(m);
    computeLPS(lps, p);
    while(i < n){
        if(s[i] == p[j]){
            i++;j++;
            if(j == m){
                /*
                    cnt++;
                    j = lps[j-1];
                */
                return true;
            }
        }else{
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return false;
}
```

# Z Algorithm
- Z Array : An element Z[i] of Z array stores length of the longest substring starting from str[i] which is also a prefix of str[0..n-1]. 

- The first entry of Z array is meaning less as complete string is always prefix of itself. 

- concatenate pattern and text, calc Z array

```cpp
vector<int> Zalgo_find(string &s, string &p){
    string w = p + " " + s;
    int n = w.size(),m = p.size();
    int l=0, r=0;
    vector<int> z(n);
    for(int i=1;i<n;i++){
        if(i >= r){
            l = i;
            r = i;
            while(w[r] == w[(r-l)]){
                r++;
            }
            z[i] = (r-l);
        }else{
            int k = i-l;
            z[i] = z[k];
            if(z[k] >= r-i){
                l = i;
                while(w[r] == w[(r-l)]){
                    r++;
                }
                z[i] = (r-l);
            }
        }
    }
    return z;
}
```

# Rabin-Karp Algorithm
- Use a rolling hash function, to calculate the hash value of the pattern and then calculate hash values of each window to check their equality and then check if it is actually equal to the pattern

- Select a prime number ‘p‘ as the modulus. This choice helps avoid overflow issues and ensures a good distribution of hash values.
Choose a base ‘b‘ (usually a prime number as well), which is often the size of the character set (e.g., 256 for ASCII characters).

- For each character ‘c’ at position ‘i’, calculate its contribution to the hash value as ‘c * (b ^ (pattern_length – i – 1)) % p’ and add it to ‘hash‘.
