#include <bits/stdc++.h>

using namespace std;

typedef unsigned int u;


// Math
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

// Loop
#define rep(i,n) for (i = 0; i < n; ++i)
#define repn(i,k,n) for (i = k; i <= n; ++i)
#define repr(i,k,n) for (i = k; i >= n; --i)

// INF

#define INF 1000000000

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef stack<char> sc;



template<typename T>
void printList(vector<T> text)
{
    cout << "size : " << text.size() << endl;
    for (const auto & value: text){
        cout << value << " " << endl;
    }
		cout << '\n';
}

int getIndex(const string& card)
{
  //The order is important got stuck on that one
  if(card[1] == 'S')
  {
    return 0;
  }
  else if(card[1] == 'H')
  {
    return 1;
  }
  else if(card[1] == 'D')
  {
    return 2;
  }
  else
  {
    return 3;
  }
}

int getValue(const string& card)
{
  if(card[0]== 'J')
  {
    return 1;
  }
  else if(card[0] == 'Q')
  {
    return 2;
  }
  else if(card[0] == 'K')
  {
    return 3;
  }
  else if(card[0] == 'A')
  {
    return 4;
  }
  else
  {
    return 0;
  }
}

int main()
{
	std::ios::sync_with_stdio(false);
  string line;

  while(cin >> line)
  {
      //read input
      vector<vs> suits(4);
      suits[getIndex(line)].push_back(line);
      int i,score(0);
      int spscore(0);
      u ls(0);
      char ms;
      score += getValue(line);
      rep(i,12)
      {
          cin >> line;
          suits[getIndex(line)].push_back(line);
          score += getValue(line);
      }
      rep(i,4)
      {
        if(suits[i].size() != 0 && ls < suits[i].size())
        {
          ls = suits[i].size();
          ms = suits[i][0][1];
        }
      }
      vb stopped(4);
      vb faces(4);
      int num(0);
    for(vs suit : suits)
    {
      for(string card : suit)
      {
          if(getValue(card) != 0)
          {
            faces[getValue(card) - 1] = true;
          }
      }

      //r2
      if(faces[2] && suit.size() == 1)
      {
        score -=1;
      }
      //r3
      if(faces[1] && suit.size() <= 2)
      {
        score -=1;
      }
      //r4
      if(faces[0] && suit.size() <= 3)
      {
        score -=1;
      }
      //r5
      if(suit.size() == 2)
      {
        score +=1;
        spscore += 1;
      }
      //r6
      if(suit.size() == 1)
      {
        score +=2;
        spscore += 2;
      }
      //r7
      if(suit.size() == 0)
      {
        score +=2;
        spscore += 2;
      }
      //stopped
      if(faces[3]
        || faces[2] && suit.size() > 1
        || faces[1] && suit.size() > 2)
      {
        stopped[num] = true;
      }
      rep(i,4)
      {
        faces[i] = false;
      }
      num++;
    }

    if(score < 14)
    {
      cout << "PASS" << endl;
    }
    else
    {
      bool isStopped(true);
      for(bool stop : stopped)
      {
        isStopped = isStopped & stop;
      }
      if(score - spscore >= 16 && isStopped)
      {
        cout << "BID NO-TRUMP" << endl;
      }
      else
      {
        cout << "BID " << ms << endl;
      }
    }

    }
  return 0;
}

