#include <iostream>
#include <vector>
using namespace std;

// Include the header file here...

   vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
        int repeatingNumber=-1;
        int missingNumber=-1;
        int n = a.size();
        int i=0;
        while(i<n)
        {
            if(a[i]!=a[a[i]-1])
            {
                swap(a[i],a[a[i]-1]);
            }
            else
            {
                i++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(a[i]!=i+1)
            {
                repeatingNumber=a[i];
                missingNumber=i+1;
            }
        }
        return {repeatingNumber,missingNumber};
    }

int main() {

    vector<int> numbers = {3, 1, 2, 5, 2}; // Replace this with your test vector

    vector<int> result = findMissingRepeatingNumbers(numbers);

    cout << "Repeating Number: " << result[0] << endl;
    cout << "Missing Number: " << result[1] << endl;

    return 0;
}