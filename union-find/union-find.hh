/* 
 * A Union Find Disjoint Set Data Structure
 * 
 * Author: Eliezer Abate
 * Last Edit: October 25 2017  
 *
 */

#ifndef _UNION_FIND_HH
#define _UNION_FIND_HH

#include <iostream> 
#include <exception>
#include <vector>
using namespace std;
using vi = vector<int>;

/*
 * class: UnionFind
 * ------------
 * Defines the public member functions that this
 * class exports. 
 */
class UnionFind {
	public:
		UnionFind(int N);
		int findSet(int x);
    bool isSameSet(int x,int y);
    void unionSet(int x,int y);
    int numDisjointSets() {
      return setNum;
    }
    int sizeOfSet(int i) {
      return setSize[findSet(i)];
    }
  private:
    int setNum;
    vi p, rank, setSize;
};

UnionFind::UnionFind(int N) {
  setNum = N;
  p.assign(N,0); rank.assign(N,0); 
  setSize.assign(N,1);
  /* set each disjoint tree's parent node to itself */
  for(int i = 0; i < N; i++) p[i] = i;
}

int UnionFind::findSet(int x) {
  return p[x] == x ? x : (p[x] = findSet(p[x]));
}

bool UnionFind::isSameSet(int x, int y) {
  return findSet(x) == findSet(y);
}

void UnionFind::unionSet(int x, int y) {
  if (!isSameSet(x,y)) {
    setNum--;
    int i = findSet(x), j = findSet(y);
    if (rank[i] > rank[j]) {
      p[j] = i;
      setSize[i] += setSize[j];
    } else {
      p[i] = j;
      setSize[j] += setSize[i];
      if (rank[i] == rank[j]) rank[j]++;
    }
  }
}

#endif

