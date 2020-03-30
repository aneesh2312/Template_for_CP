template<class holderType>
class ZFunction {

public:
	holderType arr;
	vector< int > z;
	ZFunction(holderType var) {
		arr = var;
		z.resize((int) arr.size() + 1);
	}	

	void build() {
		z[0] = 0;
		int l = 0, r = 0;
		for (int i = 1; i < arr.size(); i++) {
			if (i <= r) {
				z[i] = min(r-i+1, z[i-l]);
				for (int j = i+z[i]; j < arr.size(); j++) {
					if (arr[j] == arr[j-i]) {
						z[i]++;
					} else {
						break;
					}
				}
				if (i + z[i] - 1 > r) {
					l = i;
					r = i + z[i] - 1;
				}
			} else {
				z[i] = 0;
				for (int j = i; j < arr.size(); j++) {
					if (arr[j] == arr[j-i]) {
						z[i]++;
					} else {
						break;
					}
				}

				if (i + z[i] - 1 > r) {
					l = i;
					r = i + z[i] - 1;
				}
			}
		}
	}

	void change(holderType newVar) {
		arr = newVar;
		z.resize((int) newVar.size() + 1);
		build();
	}
};

