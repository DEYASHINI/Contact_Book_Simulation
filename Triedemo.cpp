#include <iostream>
#include<bits/stdc++.h>
typedef unsigned long long int ull;
using namespace std;

class Trie
{
   public:
    bool isEndOfWord;
    unordered_map<char, Trie*> mp;

    Trie() {
      isEndOfWord=false;

    }

    void insertInTrie(const string &word)
   {

    Trie* tmp=this;
       for(char ch:word)
       {

           if(tmp->mp.find(ch)==tmp->mp.end())
             tmp->mp[ch]=new Trie;
           tmp=tmp->mp[ch];
        }
        tmp->isEndOfWord=true;
    }


    bool search(string word)
    {
        Trie * cur=this;
        for(char ch:word)
        {
            cur=cur->mp[ch];
            if(!cur)
                return false;
        }
        if(cur->isEndOfWord)
            return true;
        else
            return false;
    }
int printAutoSuggestions(string s);
bool isLastNode(Trie *root);
void getSuggestions(Trie * root, string currPrefix);
Trie* removeFromTrie(Trie* root, string keyString,int depth);
void deleteTrie(string s);
};

Trie* Trie :: removeFromTrie(Trie* root, string keyString,int depth=0)
{
  if(!root)
        return NULL;
if(depth==keyString.size())
{
    if(root->isEndOfWord)
        root->isEndOfWord=false;
    if(isLastNode(root))
    {
        delete(root);
        root=NULL;
    }
    return root;
}

char ch=keyString[depth];
root->mp[ch]=removeFromTrie(root->mp[ch],keyString,depth+1);

if(isLastNode(root) && (root->isEndOfWord==false))
 {
   delete(root);
    root=NULL;
 }

 if(!isLastNode(root))
 {
    unordered_map<char, Trie*> :: iterator it;
   for(it=root->mp.begin();it!=root->mp.end();it++)
   {
     if(it->second==NULL)
        (root->mp).erase(it);
   }

 }

 return root;

}



void Trie :: deleteTrie(string s)
{
    Trie* root=this;
    root=removeFromTrie(root,s);
}

bool Trie ::  isLastNode(Trie *root)
{
    if(!(root->mp).empty())
        return 0;
    return 1;
}


void Trie :: getSuggestions(Trie * root, string currPrefix)
{
    if(root->isEndOfWord)
    {
        cout<<currPrefix<<endl;
    }
    if(isLastNode(root))
        return;

    for(auto it:root->mp)
    {
        currPrefix.push_back(it.first);
        getSuggestions(it.second,currPrefix);
        currPrefix.pop_back();
    }
}

int Trie :: printAutoSuggestions(string s)
{
    Trie * root=this;
    Trie *crawler=root;
    for(char ch:s)
    {
        if(!((crawler->mp)[ch]))
            return 0;
        crawler=(crawler->mp)[ch];
    }

    bool isEndingWord=((crawler->isEndOfWord)==true);
    bool isLastnode=isLastNode(crawler);

    if(isEndingWord && isLastnode)
    {
        cout<<s<<endl;
        return -1;
    }

    if(!isLastnode)
    {
        string prefix=s;
        getSuggestions(crawler,prefix);

    }
    return 1;
}



Trie* trieObj=new Trie();

void autoComplete(string s)
{   cout<<"Stage 1"<<endl;
    bool comparison=trieObj->printAutoSuggestions(s);
    if(comparison==-1)
        cout<<"No other names with this prefix string"<<endl;
    else if(comparison==0)
       cout<<"No string with this prefix string"<<endl;

}

//driver module
int main()
{
        /* trieObj->insertInTrie("dog");
         trieObj->insertInTrie("hello");
         trieObj->insertInTrie("hell");
         trieObj->insertInTrie("cat");
         trieObj->insertInTrie("a");

         trieObj->insertInTrie("hel");
         trieObj->insertInTrie("help");
         trieObj->insertInTrie("helps");
         trieObj->insertInTrie("helping");

         cout<<endl<<trieObj->search("hello");
         cout<<trieObj->search("hell");
         cout<<trieObj->search("hel");
         cout<<trieObj->search("help");
         cout<<trieObj->search("helps");
         cout<<trieObj->search("helping")<<endl;*/

         trieObj->insertInTrie("Dita");
         trieObj->insertInTrie("Dip");
         trieObj->insertInTrie("Di");
         //trieObj->insertInTrie("Deesha");
         trieObj->insertInTrie("Diya");


         /*cout<<"Suggested words with hel are"<<endl;
         autoComplete("hel");
         cout<<endl;*/

         trieObj->deleteTrie("Diya");

         cout<<"Autocomplete results:"<<endl;
         autoComplete("Di");
         trieObj->insertInTrie("Diya");
        cout<<endl<<"searching Diya"<<trieObj->search("Diya")<<endl;
         /*cout<<endl<<trieObj->search("hello");
         cout<<trieObj->search("hell");
         cout<<trieObj->search("hel");
         cout<<trieObj->search("help");
         cout<<trieObj->search("helps");
         cout<<trieObj->search("helping")<<endl;*/
         return 0;
}
