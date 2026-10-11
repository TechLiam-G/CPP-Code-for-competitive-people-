/*
In Summer Informatics School, if a student doesn't behave well, teachers make a hole in his badge. And today one of the teachers caught a group of 𝑛
 students doing yet another trick.

Let's assume that all these students are numbered from 1
 to 𝑛
. The teacher came to student 𝑎
 and put a hole in his badge. The student, however, claimed that the main culprit is some other student 𝑝𝑎
.

After that, the teacher came to student 𝑝𝑎
 and made a hole in his badge as well. The student in reply said that the main culprit was student 𝑝𝑝𝑎
.

This process went on for a while, but, since the number of students was finite, eventually the teacher came to the student, who already had a hole in his badge.

After that, the teacher put a second hole in the student's badge and decided that he is done with this process, and went to the sauna.

You don't know the first student who was caught by the teacher. However, you know all the numbers 𝑝𝑖
. Your task is to find out for every student 𝑎
, who would be the student with two holes in the badge if the first caught student was 𝑎
.
 */

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> p;
vector<bool> visited;
vector<int> ans;

// depth first search function to find possible 2 holed people and go to next node in "student graph"
void dfs(int i) {
    if (visited[i]) {
        ans.push_back(i);
        return;
    }
    visited[i] = true;
    dfs(p[i]);
}

int main() {
    // MARK: input
    cin >> n;
    p.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    // END: input

    // Run dfs per student
    for (int i = 1; i <= n; i++) {
        fill(visited.begin(), visited.end(), false);
        dfs(i);
    }

    for (int item : ans) {
        cout << item << " ";
    }
    return 0;
}
