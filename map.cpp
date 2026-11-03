
#include <iostream>
#include <vector>
#include <map>
using namespace std;


void countFrequencyBruteForce(const vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        bool dejaVu = false;

        for (int k = 0; k < i; k++) {
            if (numbers[k] == numbers[i]) {
                dejaVu = true;
                break;
            }
        }

        if (dejaVu) {
            continue;
        }

        int count = 0;
        for (int j = 0; j < numbers.size(); j++) {
            if (numbers[i] == numbers[j]) {
                count++;
            }
        }

        cout << numbers[i] << ": " << count << " times" << endl;
    }
}


map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> frequencyMap;

    for (int i = 0; i < numbers.size(); i++) {
        frequencyMap[numbers[i]]++;
    }

    return frequencyMap;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    cout << "Frequency (Brute-Force):" << endl;
    countFrequencyBruteForce(numbers);

   
    cout << "\nFrequency (Optimal):" << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);

    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << ": " << entry.second << " times" << endl;
    }

    return 0;
}

