class StringHash {
	string s;
	vector< pi > hash;
	int mod1, mod2, primenum, *power1, *power2, *inv1, *inv2;
	public: 
		StringHash(string inp, vector< int > *hashmods, int* p1, int *p2, int *i1, int *i2) {
			s = inp;
			mod1 = (*hashmods)[0];
			mod2 = (*hashmods)[1];
			primenum = 131;
			power1 = p1;
			power2 = p2;
			inv1 = i1;
			inv2 = i2;
		}

		void build() {
			pi curr = mp(0, 0);
			for (int i = 0; i < s.size(); i++) {
				curr.first += (ll(s[i])*power1[i])%mod1;
				curr.second += (ll(s[i])*power2[i])%mod2;
				
				curr.first %= mod1;
				curr.second %= mod2;

				hash.pb(curr);
			}
		}

		pl getHash(int l, int r) {
			pl ans = hash[r];
			if (l > 0) {
				ans.first = (ans.first - hash[l-1].first + mod1)%mod1;
				ans.second = (ans.second - hash[l-1].second + mod2)%mod2;
			}

			ans.first = (ans.first * ll(inv1[l]))%mod1;
			ans.second = (ans.second * ll(inv2[l]))%mod2;

			return ans;
		}
};

//958A2_1.cpp
