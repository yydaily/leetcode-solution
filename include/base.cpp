#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include "./tree_node.cpp"
#include "./number_theory.cpp"
#include "./discrete_transformation.cpp"

using namespace std;

class Checker {
private:
	int case_index = 1;
	template<typename T1, typename T2>
	bool check(const T1 &a, const T2 &b) {
		return a==b;
	}

	template<typename T>
	bool check(const vector<T> &a, const vector<T> &b) {
		if(a.size()!=b.size()) return false;
		for(int i = 0;i<a.size();i++) {
			if(!check(a[i], b[i])) {
				return false;
			}
		}
		return true;
	}

	template<typename K, typename V>
	bool check(const map<K, V> &m1, const map<K, V> &m2) {
		if(m1.size() != m2.size()) return false;
		for(auto k : m1) {
			if(m1[k] != m2[k]) return false;
		}
		for(auto k : m2) {
			if(m1[k] != m2[k]) return false;
		}
		return true;
	}

public:
	template<typename T1, typename T2>
	void Check(const T1 &a, const T2 &b) {
		bool ok = check(a, b);
		cout<<"case"<<case_index++<<(ok?" ok":" fault")<<endl;

		_TreeNode_idx = -1;
	}
};

Checker checker;