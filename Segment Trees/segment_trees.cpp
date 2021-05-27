#include <bits/stdc++.h>
using namespace std;

int lazy[10000] = {0};

void buildTree(int *a, int s, int e, int *tree, int index) {
	if (s == e) {
		tree[index] = a[s];
		return;
	}

	int mid = (s + e) / 2;
	buildTree(a, s, mid, tree, 2 * index) ;
	buildTree(a, mid + 1, e, tree, 2 * index + 1) ;
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}

int queryTree(int *tree, int ss, int se, int qs, int qe, int index) {
	// complete overlap
	if (ss >= qs && se <= qe) {
		return tree[index];
	}
	// no overlap
	if (qe < ss || qs > se) {
		return INT_MAX;
	}

	// partial overlap
	int mid = (ss + se) / 2;
	int left = queryTree(tree, ss, mid, qs, qe, 2 * index);
	int right = queryTree(tree, mid + 1, se, qs, qe, 2 * index + 1);
	return min(left, right);
}

void updateSegmentTree(int *tree, int ss, int se, int index, int inc, int updateIndex) {
	if (updateIndex > se || updateIndex < ss) {
		return;
	}
	if (ss == se) {
		tree[index] += inc;
		return;
	}
	int mid = (ss + se) / 2;
	updateSegmentTree(tree, ss, mid, 2 * index, inc, updateIndex);
	updateSegmentTree(tree, mid + 1, se, 2 * index + 1, inc , updateIndex);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;

}

void updateRangeSegmentTree(int *tree, int ss, int se, int l, int r, int inc, int index) {

	if ( l > se || r < ss) {
		return;
	}

	if (ss == se) {
		tree[index] += inc;
		return;
	}

	int mid = (ss + se) / 2;
	updateRangeSegmentTree(tree, ss, mid, l, r, inc, 2 * index);
	updateRangeSegmentTree(tree, ss, mid, l, r, inc, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}

void printSegmentTree(int *tree) {
	for (int i = 1; i <= 13; i++) {
		cout << tree[i] << " ";
	}
}

void updateRangeLazy(int * tree, int ss, int se, int l, int r, int inc, int index) {
	// before goin down resolve the value if it exists
	if (lazy[index] != 0) {

		tree[index] += lazy[index];
		// non-leaf nodes
		if (ss != se) {
			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}
		lazy[index] = 0; //clear the lazy values at the current node
	}

	if (ss > r || se < l) {
		return;
	}

	// complete overlap case, current node range 2-4 and update query range is 1-5
	if (ss >= l && se <= r) {
		tree[index] += inc;

		if (ss != se) {
			lazy[2 * index] += inc;
			lazy[2 * index + 1] += inc;
		}
		return;
	}

	int mid = (ss + se) / 2;
	updateRangeLazy(tree, ss, mid, l, r, inc, 2 * index);
	updateRangeLazy(tree, mid + 1, se, l, r, inc, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}

int queryRangeLazy(int *tree, int ss, int se, int qs, int qe, int index) {
	// resolve the lazy value at current node
	if (lazy[index] != 0) {
		tree[index] += lazy[index];

		if (ss != se) {
			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}
		lazy[index] = 0;
	}
	// Query overlap
	// No Overlap
	if (ss > qe || se < qs) {
		return INT_MAX;
	}
	// complete the overlap
	if (ss >= qs && se <= qe) {
		return tree[index];
	}
	// partial overlap
	int mid = (ss + se) / 2;
	int left = queryRangeLazy(tree, ss, mid, qs, qe, 2 * index);
	int right = queryRangeLazy(tree, mid + 1, se, qs, qe, 2 * index + 1);

	return min(left, right);
}

int main() {

	int a[] = {1, 3, 2, -5, 6, 4};
	int n = sizeof(a) / sizeof(int);
	// building tree array dynamically
	int *tree = new int[4 * n + 1];

	buildTree(a, 0, n - 1, tree, 1);
	printSegmentTree(tree);
	cout << "\n";

	// updateSegmentTree(tree, 0, n - 1, 1, 5, 3);
	// cout << "after update \n";
	// printSegmentTree(tree);
	// int q;
	// cout << "Enter no of queries: ";
	// cin >> q;

	// while (q--) {
	// 	int l, r;
	// 	cin >> l >> r;
	// 	cout << queryTree(tree, 0, n - 1, l, r, 1) << endl ;
	// }
	return 0;
}