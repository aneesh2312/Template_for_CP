struct segNode {
	bool ign;
	int val, aux;
};

template <class segTreeType, class holderType, class helperType>
class LazySegmentTree {
	holderType *st, ignore;
	helperType *arr;

	public:	
		LazySegmentTree(holderType *holderarr, helperType *helparr) {
			st = holderarr;
			arr = helparr;
			ignore.ign = 1;
		}

		holderType function(holderType a, holderType b) {
			holderType c;
			c.val = 0;
			c.aux = 0;
			return c;
		}

		void updateVal(int index, segTreeType val) {
			st[index].val = val;
		}

		void init(int a, int index) {
			st[index].val = arr[a];
			st[index].aux = 0;
		} 

		bool auxInfoUpdate(int index) {
			return false;
		}

		void resetAux(int index) {
			st[index].aux = 0;
		}

		void build(int a, int b, int index) {
			if (a == b) {
				init(a, index);
			} else {
				build(a, avg(a, b), 2*index);
				build(avg(a, b) + 1, b, 2*index+1);
				st[index] = function(st[2*index], st[2*index+1]);
			}
		}

		void update(int a, int b, int index, int l, int r, segTreeType val) {
			if (a > r or b < l)
				return;
			if (l <= a and b <= r) {
				updateVal(index, val);
			} else {
				if (auxInfoUpdate(index)) {
					update(a, avg(a, b), 2*index, a, avg(a, b), st[index].aux);
					update(avg(a, b)+1, b, 2*index+1, avg(a, b)+1, b, st[index].aux);
					resetAux(index);
				}
				update(a, avg(a, b), 2*index, l, r, val);
				update(avg(a, b)+1, b, 2*index+1, l, r, val);
				st[index] = function(st[2*index], st[2*index+1]);
			}
		}

		holderType query(int a, int b, int index, int l, int r) {
			if (a > r or b < l)
				return ignore;
			if (l <= a and b <= r) {
				return st[index];
			} else {
				holderType t1 = query(a, avg(a, b), 2*index, l, r);
				holderType t2 = query(avg(a, b)+1, b, 2*index+1, l, r);
				if (t1.ign)
					return t2;
				if (t2.ign)
					return t1;
				return function(t1, t2);
			}
		}
};	

