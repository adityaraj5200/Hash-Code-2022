/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Code written by Aditya ;)   ||  Codechef/codeforces: @adityaraj5200 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//----------HEADER----------
#include<bits/stdc++.h>
using namespace std;

//----------MACROS----------
#define fastio                        \
    ios_base::sync_with_stdio(false);   \
    cin.tie(NULL);                      \
    cout.tie(NULL)
#define endl                  "\n" 
#define PI                    3.14159265358979323846
#define all(u)                u.begin(), u.end()
#define rall(v)               v.rbegin(), v.rend()
#define sortall(u)            sort(all(u))
#define lcm(a,b)              (a*b)/__gcd(a,b)
#define gcd(a,b)              __gcd(a,b)
#define summation(n)          (((n)*((n)+1))/2)
#define lb(u,val)             lower_bound(all(u),val)
#define ub(u,val)             upper_bound(all(u),val)
#define digits(n)             (1+floor(log10(n)))
#define setbits(u)            __builtin_popcount(u)
#define ctz(u)                __builtin_ctz(u)
#define clz(u)                __builtin_clz(u)
#define checkbit(num,i)       (num&(1<<i))  //select the bit of position i of val
#define lowbit(u)             ((u)&((u)^((u)-1))) //get the lowest bit of u
#define trav(u,it)            for(auto it = u.begin(); it != u.end(); it++)
#define in(u, a, b)           (min(a,b) <= u && u <= max(a,b))
#define print(u)              for(auto it=u.begin();it!=u.end();it++)\
                        cout<<*it<<' '; cout<<endl
#define printpair(u)            for(auto it=u.begin();it!=u.end();it++)\
                        cout<<it->first<<' '<<it->second<<endl
#define yes                   "YES"
#define no                    "NO"

//----------TYPEDEFS----------
typedef unsigned int          uint;
typedef long long             ll;
typedef unsigned long long    ull;
typedef long double           ld;
typedef pair<int,int>         pii;

//----------DEBUG METHODS----------
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define nline cerr << endl
#else
#define debug(x...)
#define nline 
#endif

//----------GLOBAL FUNCTIONS AND VARIABLES----------
template<typename T>
T getrandom(T l,T r){
    return rand() % (r-l+1) + l;
}

pair<int,unordered_set<string>> ans = {0,{}};
unordered_set<string> allIngredients;
vector<string> allIngredientsVector;
unordered_map<string,int> freqLikes, freqDislikes;

struct Person
{
    vector<string> likes;
    vector<string> dislikes;
};

vector<Person> persons;

int getScore(unordered_set<string> &pickedIngredients){
    auto isSatisfied = [&](Person &person,unordered_set<string> &pickedIngredients) -> bool{
        for(string &str: person.likes){
            if(pickedIngredients.find(str) == pickedIngredients.end())
                return false;
        }
        for(string &str: person.dislikes){
            if(pickedIngredients.find(str) != pickedIngredients.end())
                return false;
        }
        return true;
    };

    int ans = 0;
    for(auto &person: persons){
        if(isSatisfied(person,pickedIngredients))
            ans++;
    }
    return ans;
}
//----------DIFFERENT METHODS TO SOLVE----------

unordered_set<string> take_where_like_is_more_than_dislike(){
    unordered_set<string> result;
    for(string s: allIngredients){
        if(freqLikes[s] > freqDislikes[s])
            result.insert(s);
    }
    return result;
}

unordered_set<string> take_where_like_is_more_than_or_equal_to_dislike(){
    unordered_set<string> result;
    for(string s: allIngredients){
        if(freqLikes[s] >= freqDislikes[s])
            result.insert(s);
    }
    return result;
}

void addIngredientsWithZeroDislikes(unordered_set<string> &pickedIngredients){
    // Adding those ingredients who have zero dislikes, as they are causing no problem 
    for(string s: allIngredients){
        if(freqDislikes[s] == 0)
            pickedIngredients.insert(s);
    }
}

void maximizeAnswer(unordered_set<string> currIngredient){
    addIngredientsWithZeroDislikes(currIngredient);
    int currScore = getScore(currIngredient);
    if(currScore > ans.first){
        ans = {currScore, currIngredient};
    }
}


unordered_set<string> getRandomIngredients(){
    unordered_set<string> randomIngredients;
    
}

//----------MAIN CODE----------
int main(){
    srand(time(0));

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);

    // Taking Input
    int numOfCustomers;
    cin>>numOfCustomers;

    persons = vector<Person>(numOfCustomers);
    string ingredient;
    for(int i=0;i<numOfCustomers;i++){
        int l; cin>>l;
        while(l--){
            cin>>ingredient;
            persons[i].likes.push_back(ingredient);
            freqLikes[ingredient]++;
            allIngredients.insert(ingredient);
        }
        int r; cin>>r;
        while(r--){
            cin>>ingredient;
            persons[i].dislikes.push_back(ingredient);
            freqDislikes[ingredient]++;
            allIngredients.insert(ingredient);
        }
    }
    // Input ends!

    allIngredientsVector = vector<string>(all(allIngredients));

    unordered_set<string> emptyIngredient; 
    
    maximizeAnswer(emptyIngredient);
    maximizeAnswer(take_where_like_is_more_than_dislike());
    maximizeAnswer(take_where_like_is_more_than_or_equal_to_dislike());
    


    // ----------------Printing Results!-------------------------

    int finalScore = ans.first;

    debug(finalScore);
    debug(numOfCustomers);
    debug(allIngredients.size());


    // printing result to output.txt
    cout<<ans.second.size()<<' ';
    for(string s: ans.second){
        cout<<s<<' ';
    }
    
    fclose(stdin);//move this line to bottom

    return 0;
}