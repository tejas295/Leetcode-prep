class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        for (const string& op : operations) {
            if (op == "C") {
                scores.pop();
            } 
            else if (op == "D") {
                scores.push(scores.top() * 2);
            } 
            else if (op == "+") {
                int last = scores.top();
                scores.pop();
                int second_last = scores.top();
                scores.push(last);
                scores.push(last + second_last);
            } 
            else {
                scores.push(stoi(op));
            }
        }
        int totalScore = 0;
        while (!scores.empty()) {
            totalScore += scores.top();
            scores.pop();
        }
        return totalScore;
    }
};
