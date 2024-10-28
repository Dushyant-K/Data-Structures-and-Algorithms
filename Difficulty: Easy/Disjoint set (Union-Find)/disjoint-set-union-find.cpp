//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int x);
void unionSet(int a[],int x ,int z);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	
cout << "~" << "\n";
}
}
// } Driver Code Ends




//Disjoint Data Structure
// class DSU {
// private:
//     vector<int> parent; // stores the parent of each element
//     vector<int> rank; // stores the rank (depth) of each tree
//     vector<int> size;
// public:
//     // Constructor to initialize the DSU for n elements (1 to n)
//     DSU(int n) {
//         parent.resize(n + 1); // as we are considering 1-based indexing
//         rank.resize(n + 1, 0); // initialize ranks to 0
//         size.resize(n+1,0);
//         // Initially, each element is its own parent (disjoint sets)
//         for (int i = 1; i <= n; i++) {
//             parent[i] = i;
//         }
//     }

//     // Find operation with path compression
//     int find(int x) {
//         if (parent[x] == x) {
//             return X;
//         }
//         return parent[X]=find(parent[X]);
//     }

//     // Union operation with union by rank
//     void unionSetsByRank(int x, int z) {
//         int rootX = find(x);
//         int rootZ = find(z);

//         // If they have the same root, they are already in the same set
//         if (rootX != rootZ) {
//             // Union by rank: attach the smaller tree under the larger tree
//             if (rank[rootX] < rank[rootZ]) {
//                 parent[rootX] = rootZ;
//             } else if (rank[rootX] > rank[rootZ]) {
//                 parent[rootZ] = rootX;
//             } else {
//                 // If they have the same rank, attach one under the other and increase rank
//                 parent[rootZ] = rootX;
//                 rank[rootX]++;
//             }
//         }
//     }
    
//      void unionSetsBySize(int x, int z) {
//         int rootX = find(x);
//         int rootZ = find(z);

//         // If they have the same root, they are already in the same set
//         if (rootX != rootZ) {
//             // Union by rank: attach the smaller tree under the larger tree
//             if (size[rootX] < size[rootZ]) {
//                 parent[rootX] = rootZ;
//                 size[rootX]+=size[rootZ];
//             } else if (size[rootX] > size[rootZ]) {
//                 parent[rootZ] = rootX;
//                 size[rootZ] = size[rootX];
//             } else {
//                 // If they have the same rank, attach one under the other and increase rank
//                 parent[rootZ] = rootX;
//                 size[rootX]+=size[rootZ];
//             }
//         }
//     }
// };

/*Complete the functions below*/
int find(int A[], int X) {
    if (A[X] != X) {
        A[X] = find(A, A[X]);
    }
    return A[X];
}

/* Function to perform union of X and Z */
void unionSet(int A[], int X, int Z) {
    int rootX = find(A, X);
    int rootZ = find(A, Z);
    

    if (rootX != rootZ) {
        A[rootX] = rootZ;
    }
}