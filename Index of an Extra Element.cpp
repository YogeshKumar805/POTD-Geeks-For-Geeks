class Solution {

  public:

    int findExtra(int n, int arr1[], int arr2[]) {

        // add code here.

        vector<pair<int,int>> mp;

        

        for(int i=0;i<n;i++){

            mp.push_back({i,arr1[i]});

        }

        int temp=0;

        for(int i=0;i<n;i++){

            

            if(mp[i].second == arr2[i]){

                continue;

            }else{

                temp=mp[i].first;

                break;

            }

        }

        return temp;

    }

};

