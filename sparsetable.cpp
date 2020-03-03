template<class sparseTableType>
class SparseTable {
	vector< vector< sparseTableType > > *table;
	int numLayers, numElements;
	public:
		SparseTable(vector< vector< sparseTableType > > *tablev, int sz) {
			table = tablev;
			numLayers = (*table)[1].size();
			numElements = sz;
		}

		sparseTableType function(sparseTableType a, sparseTableType b) {
			sparseTableType c;
			return c;
		}

		void build() {
			for (int j = 1; j < numLayers; j++) {
				for (int i = 1; i <= numElements; i++) {
					if (i+(1<<j)-1 > numElements) {
						(*table)[i][j] = 1e18;
						continue;
					}
					(*table)[i][j] = function((*table)[i][j-1], (*table)[i+(1<<(j-1))][j-1]);
				}
			}
		}

		sparseTableType query(int l, int r) {
			sparseTableType ans;
			int j, diff = (r-l+1);
			for (j = 0; (1<<j) <= diff; j++);
			j--;
			ans = (*table)[l][j];
			if (diff != (1<<j))
				ans = function(ans, query(l+(1<<j), r));
			return ans;
		}
};

